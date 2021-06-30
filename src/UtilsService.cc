#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <regex>
#include "UtilsService.h"

std::vector<std::string> UtilsService::getLineInfo(std::string line)
{
    std::vector<std::string> lineInfo;
    std::regex re("\\S+");
    //start/end points of tokens in line
    std::sregex_token_iterator
        begin(line.begin(), line.end(), re),
        end;
    std::copy(begin, end, std::back_inserter(lineInfo));
    return lineInfo;
}