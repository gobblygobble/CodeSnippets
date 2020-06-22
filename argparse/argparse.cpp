#include "argparse.hpp"
#include <iostream>
#include <cstdlib>

ArgParse::ArgParse()
{
}

ArgParse::~ArgParse()
{
}

void ArgParse::add_argument(string name, int df)
{
    args[name] = df;
}

void ArgParse::parse(int argc, char *argv[])
{
    string a;
    for(int i =1; i<argc; i++){
        if((argv[i][0] == '-') && (argv[i][1] == '-')){
            a = argv[i];
            args[a.substr(2)] = atoi(argv[i+1]);
        }
    }
}
