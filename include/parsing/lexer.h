#ifndef LEXER_H
#define LEXER_H

#include "util.h"
#include "parsing/token.h"

class Lexer{
private:
    Location loc;
    std::vector<Token> tokens;
    Token token;
    std::string now_str;
    std::string line_str;
public:
    Lexer() : loc(0), now_str(""){ }
    void get_token();
    std::vector<Token> lex();
};


#endif