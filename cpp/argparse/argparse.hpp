#ifndef ARGPARSE_HPP
#define ARGPARSE_HPP
#include <string.h>
#include <string>
#include <map>

class ArgParse {
private:
    std::map<std::string, std::string> _map;
public:
    ArgParse();
    void Parse(int argc, char *argv[]);
    std::map<std::string, std::string>& GetMap();
    std::string GetValueFromKey(std::string key);
    // return value with type & default value specified
    int GetIntFromKey(std::string key, int df);
    unsigned int GetUnsignedIntFromKey(std::string key, unsigned int df);
    std::string GetStringFromKey(std::string key, std::string df);
}; // class ArgParse

#endif // ARGPARSE_HPP