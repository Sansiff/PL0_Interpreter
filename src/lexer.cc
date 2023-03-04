#include "lexer.h"
#include <iostream>
#include <exception>

void Lexer::get_token(){
    if(now_str == " "){ now_str = ""; return; }
    token.set_key(now_str);
    token.set_loc(loc);
    tokens.push_back(token);
    now_str = "";
}

std::vector<Token> Lexer::lex(){
    int tmp = 0;
    while(std::getline(std::cin, line_str)){
        loc.move_line();
        for(int i = 0; i < line_str.size(); i += 1){
            if(isalpha(line_str[i]) || isdigit(line_str[i])){
                now_str += line_str[i];
            } else{
                get_token();
                if(line_str[i] == ':'){
                    i += 1, loc.move_colume();
                    now_str += ":=";
                    get_token();
                } else{
                    now_str += line_str[i];
                    if(Token::match(now_str)) get_token();
                }
                loc.move_colume();
            }
        }
    }
    return tokens;
}