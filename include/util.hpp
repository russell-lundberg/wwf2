#ifndef UTIL_LIB
#define UTIL_LIB
#include <string>

namespace WWF {


void show_usage(std::string name);

void not_implemented(std::string option);

std::set<std::string> get_dictionary();

void LetterScore();

std::vector<std::string> ingest_args( int argc, char* argv[] );

}
#endif