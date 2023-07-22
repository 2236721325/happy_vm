#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "lexer.h"
#include "pch.h"
#include "Parser.h"
#include "AstNode.h"

TEST_CASE( "simple function lexer test", "[lexer]" )
{
    auto lex = vm::Lexer(R"(
add(int,int)->int ;（自动根据参数数量开辟stack)
    larg ax,0 ;0 the first arg ->load from stack
    larg bx,1 ;1 the second arg
    add ax,bx
    ret       ; ret
)"
);

    try
    {
        while (true)
        {

            auto token = lex.NextToken();
            if (token.Kind == vm::TokenKind::Token_EOF)
            {
                std::cout << (token.ToString()) << std::endl;
                break;
            }
            std::cout << (token.ToString()) << std::endl;
        }
    }
    catch (const std::exception& ex)
    {
        FAIL(ex.what());
        REQUIRE(false);
    }
    REQUIRE(true);
}

TEST_CASE( "simple function Parser test", "[lexer]" )
{
    auto lex = vm::Lexer(R"(
add(int,int)->int ;（自动根据参数数量开辟stack)
    larg ax,0 ;0 the first arg ->load from stack
    larg bx,1 ;1 the second arg
    add ax,bx
    ret       ; ret
)"
    );

    try
    {
        while (true)
        {

            auto token = lex.NextToken();
            if (token.Kind == vm::TokenKind::Token_EOF)
            {
                std::cout << (token.ToString()) << std::endl;
                break;
            }
            std::cout << (token.ToString()) << std::endl;
        }
    }
    catch (const std::exception& ex)
    {
        FAIL(ex.what());
        REQUIRE(false);
    }
    REQUIRE(true);
}
