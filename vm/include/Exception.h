#pragma once

#include "pch.h"
#include "lexer.h"
namespace vm
{
	class SyntaxException : public std::exception
	{
	private:
        std::string msg;

	public:
		SyntaxException(std::string_view error_name ,const std::string& description,size_t line)
            : exception()
        {
            msg=util::Format("[ {} ]-> {}  -> at line {} !",error_name,description,line);
        }


		virtual const char *what() const throw()
		{
			return msg.c_str();
		}


		[[noreturn]] static void Throw(const std::string& msg, size_t line = 0);
        [[noreturn]] static void UnExpectChar(char c, size_t line = 0);
        [[noreturn]] static void UnExpectToken(Token token);


    };

}