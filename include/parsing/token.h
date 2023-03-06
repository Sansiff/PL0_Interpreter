#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <unordered_map>
#include <vector>
#include "util.h"

class Token{
private:
    static std::unordered_map<std::string, int> keytonum;
    static std::vector<std::string> keys;
    Location loc;
    std::string key;
public:
    Token(){ }
    int get_key_number(std::string s){ return keytonum[s]; }
    void set_loc(Location _loc){ loc = _loc; }
    void set_key(std::string _key){ key = _key; }
    static void init();
    static int match(std::string);
    std::string to_string();
};

#endif