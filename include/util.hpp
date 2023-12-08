#ifndef UTIL_LIB
#define UTIL_LIB
#include <string>
#include <vector>
#include <set>
#include <map>

namespace WWF {


void show_usage(std::string );

void not_implemented(std::string );

std::set<std::string> get_dictionary();

std::map<char,int> LetterScores();
//std::map<std::string,int> LetterScores();

std::vector<std::string> ingest_args( int, char** );

std::map<std::string,int> Score_Word ( std::string );

std::string str_tolower( std::string );

void sort( std::map<std::string, int>&);

}
#endif