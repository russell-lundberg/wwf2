//
//  util.hpp
//  wwf2
//
//  Created by Russell Lundberg on 1/24/24.
//

#ifndef util_h
#define util_h

#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

namespace Util {

std::set<std::string> get_dictionary();

}

namespace WWF {


void show_usage(std::string );

void not_implemented(std::string );

std::map<char,int> LetterScores();
//std::map<std::string,int> LetterScores();

//std::unordered_map<std::string,std::string> ingest_args( int, char** );

std::map<std::string,int> Score_Word ( std::string );

std::string str_tolower( std::string );


void sort( std::map<std::string, int>& );
std::set<std::pair<std::string,int>> Words_Sorted( std::map<std::string, int>&, std::unordered_map<std::string,std::string> );


int factorial( int );

} // close namespace declaration


#endif /* util_h */
