#ifndef UTILS_SERVICE_H
#define UTILS_SERVICE_H
#include <iostream>
#include <vector>
#include <string>

class Person;

class UtilsService
{
public:
    static std::vector<std::string> getLineInfo(std::string line);
};

#endif