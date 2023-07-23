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
        std::unique_ptr<Lexer> lexer;
    public:
        Parser(Lexer& lex)
        {
            this->lexer=std::make_unique<Lexer>(lex);
        }
        Instruction ParseInstruction();
        Directive ParseDirective();
        Block ParseBlock();
        Block Parse();


        LabelDirective ParseLabelDirective();

    };
}



#endif //HAPPY_VM_PARSER_H
