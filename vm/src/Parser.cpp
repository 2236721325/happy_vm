//
// Created by wyh on 23-7-22.
//

#include "Parser.h"

namespace vm
{

    Block Parser::Parse()
    {
        return ParseBlock();
    }

    Block Parser::ParseBlock()
    {
        auto insts = std::make_shared<std::vector<Directive>>();

        while (true)
        {
            insts->push_back(ParseDirective());
            if (m_lex->LookAhead().Kind == TokenKind::Token_EOF)
            {
                break;
            }
        }
        return Block(insts);
    }

    Directive Parser::ParseDirective()
    {

        switch (lexer->LookAhead().Kind)
        {
            case TokenKind::Inc_mov:
            case TokenKind::Inc_push:
            case TokenKind::Inc_pop:
            case TokenKind::Inc_add:
            case TokenKind::Inc_cmp:
            case TokenKind::Inc_leave:
            case TokenKind::Inc_goto:
            case TokenKind::Inc_larg:
            case TokenKind::Inc_ret:
            case TokenKind::Identifier:
                return ParseLabelDirective();
            case TokenKind::Number:
            case TokenKind::Kw_int:
            case TokenKind::Kw_float:
            case TokenKind::Kw_char:
            case TokenKind::Op_Sub:
            case TokenKind::Op_Plus:
            case TokenKind::Op_Mul:
            case TokenKind::Op_Div:
            case TokenKind::Op_GT:
            case TokenKind::Op_LT:
            case TokenKind::Sep_Lparen:
            case TokenKind::Sep_Rparen:
            case TokenKind::Sep_Comma:
            case TokenKind::Sep_Colon:
            case TokenKind::Sep_Lbracket:
            case TokenKind::Sep_Rbracket:
            case TokenKind::Token_EOF:

        }
        return Directive();
    }

    LabelDirective Parser::ParseLabelDirective()
    {
        lexer->NextTokenOfKind(TokenKind::Identifier);
        lexer->NextTokenOfKind(TokenKind::Sep_Comma);
        return LabelDirective(lexer->Line);
    }

    Instruction Parser::ParseInstruction()
    {
        return Instruction();
    }
}