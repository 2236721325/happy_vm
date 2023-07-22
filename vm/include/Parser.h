//
// Created by wyh on 23-7-22.
//

#ifndef HAPPY_VM_PARSER_H
#define HAPPY_VM_PARSER_H
#include "pch.h"
#include "lexer.h"
#include "AstNode.h"
namespace vm
{
    class Parser
    {
    private:
        Lexer& lex;
    public:
        Parser(Lexer& lex)
        :lex(lex)
        {
        }

        Block Parse();


    };
}



#endif //HAPPY_VM_PARSER_H
