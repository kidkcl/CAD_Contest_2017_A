/****************************************************************************
  FileName     [ parse.h ]
  PackageName  [ parse gate ]
  Synopsis     [ Declare utility function interfaces ]
  Author       [ kcl ]
****************************************************************************/
#ifndef UTIL_PARSE_H
#define UTIL_PARSE_H

#include <istream>
#include <vector>
#include <string>
#include <fstream>

//using namespace std;

std::string readUntil(std::ifstream& ifs, char end) {
   std::string str;
   char c;
   while(!ifs.eof()) {
      ifs.get(c);
      str += c;
      if(c == end) break;
   }
   return str;
}

std::vector<std::string> split(const std::string& str, const std::string& sep) {
   unsigned n = str.size();
   std::vector<std::string> vec;
   std::string token;
   for(unsigned i = 0; i < n; ++i) {
      if(sep.find(str[i]) == std::string::npos) {
         token += str[i];
      }
      else if {
         vec.push_back(token);
         token.clear();
      }
   }
   if(token.size() > 0)
      vec.push_back(token);
   return vec;
}

#endif // UTIL_PARSE_H
