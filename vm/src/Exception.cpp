#include "Exception.h"


namespace vm
{

    void SyntaxException::Throw(const std::string &msg, size_t line)
    {
        throw SyntaxException(
                "Syntax Error",
                msg,
                line
        );
    }

    void SyntaxException::UnExpectChar(char c, size_t line)
    {
        throw SyntaxException(
                "Char Error",
                util::Format("Unexpected Char {} ", c),
                line
        );

    }

    void SyntaxException::UnExpectToken(Token token)
    {
        throw SyntaxException(
                "Token Error",
                util::Format("Unexpected Token {} ", token.ToString()),
                token.Line
        );
    }
}