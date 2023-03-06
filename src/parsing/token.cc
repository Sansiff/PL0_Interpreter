#include "token.h"

std::vector<std::string> Token::keys = {
    "begin", "end", "if", "then", "while", "do", "const", "var","call", "procedure", 
    "odd", "+", "-", "*", "/", "=", "#", "<", ">", ":=", "(", ")", ",", ".", ";"
};
std::unordered_map<std::string, int> Token::keytonum;
void Token::init(){
    for(int i = 0; i < keys.size(); i ++){
        keytonum[keys[i]] = i + 1; 
    }
}
int Token::match(std::string s){
    return keytonum[s];
}

int Token::get_key_number(std::string s){
    return keytonum[s];
}


std::string Token::to_string(){
    return std::to_string(loc.get_line()) + ":" + std::to_string(loc.get_colume() - key.size())
    + "\t" + key + "\t" + std::to_string(Token::get_key_number(key)); 
}