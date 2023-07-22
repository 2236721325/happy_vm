//
// Created by wyh on 23-7-22.
//

#include "lexer.h"
#include "Exception.h"


namespace vm
{

    Token Lexer::LookAhead()
    {
        if (nextToken != nullptr)
        {
            return *nextToken;
        }
        auto line = Line;
        nextToken = std::make_unique<Token>(NextToken());
        Line = line;
        return *nextToken;
    }

    Token Lexer::NextToken()
    {
        if (nextToken != nullptr)
        {
            Line = nextToken->Line;
            auto result = *nextToken;
            nextToken = nullptr;
            return result;
        }
        SkipWhiteSpace();

        if (!CanDoNext())
        {
            return Token(TokenKind::Token_EOF, "", Line);
        }
        switch (code[cur_pos])
        {
            case ',':
                Next();
                return Token(TokenKind::Sep_Comma, ",", Line);
            case '+':
                Next();

                return Token(TokenKind::Op_Plus, "+", Line);
            case '-':
                Next();

                return Token(TokenKind::Op_Sub, "-", Line);
            case '*':
                Next();
                return Token(TokenKind::Op_Mul, "*", Line);
            case '/':
                Next();
                return Token(TokenKind::Op_Div, "/", Line);
            case '<':
                Next();

                return Token(TokenKind::Op_LT, "<", Line);
            case '>':
                Next();

                return Token(TokenKind::Op_GT, ">", Line);
            case '(':
                Next();

                return Token(TokenKind::Sep_Lparen, "(", Line);
            case ')':
                Next();

                return Token(TokenKind::Sep_Rparen, ")", Line);
        }

        if (std::isdigit(Look()))
        {
            return NextNumberToken();
        }

        if (std::isalpha(Look()) || Look()=='_')
        {
            return NextIdentifier();
        }


        SyntaxException::UnExpectChar(Look(),Line);


    }
    void Lexer::SkipWhiteSpace()
    {
        while (CanDoNext())
        {
            if (Look()==';')
            {
                SkipComment();
            }
            else if (StartWith("\r\n") || StartWith("\n\r"))
            {
                Next(2);
                Line++;
            }
            else if (IsNewLine())
            {
                Next(1);
                Line++;
            }
            else if (IsWhiteSpace())
            {
                Next(1);
            }
            else
            {
                break;
            }

        }
    }

    void Lexer::SkipComment()
    {
        Next(2);
        while (CanDoNext() && !IsNewLine())
        {
            Next(1);
        }
    }

    bool Lexer::StartWith(const char* str)
    {
        auto len = std::strlen(str);
        for (size_t i = 0; i < len; i++)
        {
            if (cur_pos + i >= code.length())
            {
                return false;
            }
            if (code[cur_pos + i] != str[i])
            {
                return false;
            }
        }
        return true;
    }

    Token Lexer:: NextNumberToken()
    {
        size_t start_idx=cur_pos;
        bool is_first_dot = true;
        while (CanDoNext())
        {
            if (std::isdigit(Look()))
            {
                Next();
                continue;
            }
            if (Look() == '.')
            {
                if (!is_first_dot)
                {
                    SyntaxException::Throw("A float number has too many dot char!",Line);
                }
                is_first_dot= false;
                Next();
                continue;
            }
            break;
        }
        auto ret_str=code.substr(start_idx,cur_pos-start_idx);
        return Token(TokenKind::Number, ret_str, Line);
    }

    Token Lexer::NextIdentifier()
    {
        size_t start_idx=cur_pos;
        Next();

        while (CanDoNext())
        {

            if ( !std::isalnum(Look()) && Look()!='_')
            {
                break;
            }

            Next();
        }

        auto  str=code.substr(start_idx,cur_pos-start_idx);
        auto iter=Identifier_map.find(str);
        if (iter != Identifier_map.end())
        {
            return Token(iter->second, str, Line);
        }

        return Token(TokenKind::Identifier, str, Line);
    }

}