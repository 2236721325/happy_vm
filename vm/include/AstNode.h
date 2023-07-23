//
// Created by wyh on 23-7-22.
//

#ifndef HAPPY_VM_ASTNODE_H
#define HAPPY_VM_ASTNODE_H

#include <utility>

#include "pch.h"
namespace vm
{



    class Directive
    {
    public:
        size_t Address;

        virtual std::string ToString()
        {
            return "Directive";
        }
    };




    class Instruction:public Directive
    {
    private:
    public:
    virtual std::vector<std::byte> GetBytes()=0;

    std::string ToString()
    {
        return "Instruction";
    }
    };



    class Block
    {
    public:
        std::shared_ptr<std::vector<Directive>> Instructions;
        Block(std::shared_ptr<std::vector<Directive>> instructions)
        :Instructions(instructions)
        {
            
        }

    };



    class LabelDirective: public Directive
    {public:
        LabelDirective(size_t address)
        {
            Address=address;
        }
        std::string ToString()
        {
            return util::Format("[{0}]->{ LabelDirective }",Address);
        }

    };
}


#endif //HAPPY_VM_ASTNODE_H
