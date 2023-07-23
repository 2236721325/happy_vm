//
// Created by wyh on 23-7-22.
//

#ifndef HAPPY_VM_LEXER_H
#define HAPPY_VM_LEXER_H
#include "pch.h"


namespace vm
{
    enum class TokenKind
    {
        Reg_sp,
        Reg_bp,
        Reg_ax,
        Reg_bx,
        Reg_cx,
        Reg_dx,

        Inc_mov,
        Inc_push,
        Inc_pop,
        Inc_add,
        Inc_cmp,
        Inc_leave,
        Inc_goto,
        Inc_larg,
        Inc_ret,


        Identifier,
        Number,



        Kw_int,
        Kw_float,
        Kw_char,

        Op_Sub,
        Op_Plus,
        Op_Mul,
        Op_Div,
        Op_GT,
        Op_LT,
        Sep_Lparen,
        Sep_Rparen,
        Sep_Comma,
        Sep_Colon,
        Sep_Lbracket,
        Sep_Rbracket,
        Token_EOF,





    };
    const std::map<std::string_view, TokenKind> Identifier_map = {

            {"char", TokenKind::Kw_char},
            {"int", TokenKind::Kw_int},
            {"float", TokenKind::Kw_float},

            {"sp", TokenKind::Reg_sp},
            {"bp", TokenKind::Reg_bp},
            {"ax", TokenKind::Reg_ax},
            {"bx", TokenKind::Reg_bx},
            {"cx", TokenKind::Reg_cx},
            {"dx", TokenKind::Reg_dx},


            {"mov", TokenKind::Inc_mov},
            {"push", TokenKind::Inc_push},
            {"pop", TokenKind::Inc_pop},
            {"add", TokenKind::Inc_add},
            {"cmp", TokenKind::Inc_cmp},
            {"goto", TokenKind::Inc_goto},
            {"larg", TokenKind::Inc_larg},
            {"ret", TokenKind::Inc_ret},

    };
    class Token
    {
    public:
        TokenKind Kind;
        std::string_view Content;
        size_t Line;
        Token(TokenKind kind,std::string_view content,size_t line)
            :Kind(kind),Content(content),Line(line)
        {

        }
        std::string ToString()
        {
            return util::Format("[Line:{0}, Content:{1}, Kind:{2}]"
                                ,Line,Content,GetTokenKindStr());
        }
        std::string_view GetTokenKindStr()
        {
            return magic_enum::enum_name(Kind);
        }
    };
    class Lexer
    {
    private:
        std::string_view code;
        std::unique_ptr<Token> nextToken{nullptr};
        size_t cur_pos{0};
    public:
        size_t Line{1};

        explicit Lexer(const char* const code)
            :code(code)
        {

        }
        Lexer(const Lexer& other)
        :code(other.code)
        {

        }
        Token NextToken();
        Token LookAhead();

        Token NextTokenOfKind(TokenKind kind);
        char Next(size_t n=1)
        {
            char ret= code[cur_pos];
            cur_pos += n;
            return ret;
        }
        char Look(size_t n=0)
        {
            if(cur_pos+n>=code.length())
            {
                throw std::out_of_range("n+cur_pos is out code range!");
            }
            return code[cur_pos+n];
        }
        bool CanDoNext()
        {
            return cur_pos <= code.length()-1;
        }
        void SkipWhiteSpace();
        void SkipComment();

        bool IsNewLine()
        {
            return code[cur_pos] == '\r' || code[cur_pos] == '\n';
        }

        bool StartWith(const char* str);

        bool IsWhiteSpace()
        {
            switch (code[cur_pos])
            {
                case '\t':
                case '\v':
                case '\n':
                case '\f':
                case '\r':
                case ' ':
                    return true;
                default:
                    return false;
            }
        }


        Token NextNumberToken();
        Token NextIdentifier();


    };


}


#endif //HAPPY_VM_LEXER_H
