#ifndef UTIL_H
#define UTIL_H

#include <string>

class Location{
private:
    int colume;
    int line;
public:
    Location(int _line) : line(_line) { colume = 1; }
    Location() {}
    void move_colume(){ colume += 1; }
    int get_colume(){ return colume; }
    void move_line(){ line += 1; }
    int get_line(){ return line; }
    void set_colume() { colume = 1; }
};

#endif