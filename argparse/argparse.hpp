#pragma once
#include <string>
#include <map>

#define _GLIBCXX_USE_C99 1

using namespace std;

class ArgParse
{
public:
    ArgParse();
    ~ArgParse();
    void add_argument(string name, int df);
    void parse(int argc, char *argv[]);
    map<string, int> args;
};
