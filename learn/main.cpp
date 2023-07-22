//
// Created by wyh on 23-7-22.
//
#include <iostream>

class Token
{
public:
    int Kind;
    std::string_view Content;
    size_t Line;
    Token(int kind,std::string_view content,size_t line)
            :Kind(kind),Content(content),Line(line)
    {

    }
};

int main()
{
    Token token1(1,"hello",12);
    Token token2=token1;

    token1.Line=1000;
    std::cout<<token2.Line<<std::endl;


}