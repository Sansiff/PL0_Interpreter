#include "parsing/lexer.h"
#include "parsing/token.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>


int main(){
    Lexer lexer; Token::init();
    std::vector<Token> tokens = lexer.lex();
    std::cout << "tokens size = " << tokens.size() << std::endl;
    for(Token token : tokens){
        std::cout << token.to_string() << "\n";
    }
    return 0;
}