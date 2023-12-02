#ifndef UTIL_LIB
#define UTIL_LIB
#include <string>
#include <vector>
#include <set>
#include <map>

namespace WWF {


void show_usage(std::string name);

void not_implemented(std::string option);

std::set<std::string> get_dictionary();

std::map<std::string,int> LetterScore();

std::vector<std::string> ingest_args( int argc, char* argv[] );

}
#endif