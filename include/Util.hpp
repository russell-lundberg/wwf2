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

int factorial( int );

void not_implemented(std::string );

//std::map<std::string,int> Score_Word ( std::string );

}

namespace WWF {


void not_implemented(std::string );

std::map<char,int> LetterScores();

void sort( std::map<std::string, int>& );


} // close namespace declaration


#endif /* util_h */
