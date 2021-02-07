#include "argparse.hpp"
#include <iostream>
#include <cstdlib>

ArgParse::ArgParse()
{
}

void ArgParse::Parse(int argc, char *argv[])
{
    std::string str;
    for (int i = 1; i < argc; ++i) {
        if ((argv[i][0] == '-') &&
            (argv[i][1] == '-')) {
            str = argv[i];
            this->_map[str.substr(2)] = argv[i+1];
        }
    }
}

std::map<std::string, std::string>& ArgParse::GetMap()
{
    return this->_map;
}

std::string ArgParse::GetValueFromKey(std::string key)
{
    // returns empty string if not found
    auto it = this->_map.find(key);
    if (it == this->_map.end()) {
        // not found
        return "";
    }
    // found
    return it->second;
}

int ArgParse::GetIntFromKey(std::string key, int df)
{
    std::string str_value = this->GetValueFromKey(key);
    if (str_value.compare("")) {
        // found
        return atoi(str_value.c_str());
    }
    // not found
    return df;
}

unsigned int ArgParse::GetUnsignedIntFromKey(std::string key, unsigned int df)
{
    std::string str_value = this->GetValueFromKey(key);
    if (str_value.compare("")) {
        // found
        return (unsigned int)atoi(str_value.c_str());
    }
    // not found
    return df;
}

std::string ArgParse::GetStringFromKey(std::string key, std::string df)
{
    std::string str_value = this->GetValueFromKey(key);
    if (str_value.compare("")) {
        // found
        return str_value;
    }
    // not found
    return df;
}