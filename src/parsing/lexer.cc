#include "parsing/lexer.h"
#include <iostream>
#include <exception>

void Lexer::get_token(){
    if(now_str == "") return;
    token.set_key(now_str);
    token.set_loc(loc);
    tokens.push_back(token);
    now_str = "";
}

std::vector<Token> Lexer::lex(){
    while(std::getline(std::cin, line_str)){
        loc.move_line(); loc.set_colume();
        for(int i = 0; i < line_str.size(); i += 1, loc.move_colume()){
            if(isalpha(line_str[i]) || isdigit(line_str[i]) || now_str == ":"){
                now_str += line_str[i];
            } else {
                get_token();
                if(line_str[i] != ' ') now_str += line_str[i];
            }
        }
        get_token();
    }
    return tokens;
}