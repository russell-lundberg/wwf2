/*
* Words.hpp
* 01/27/2024
* function definitions
*/
#ifndef WORDS_HPP
#define WORDS_HPP

#include <map>
#include <unordered_map>
#include <string>
#include <set>

namespace Words {

std::map<std::string,int> Score_Word ( std::string );

std::set<std::pair<std::string,int>> Sorted( std::map<std::string, int>&, std::unordered_map<std::string,std::string> );



}

#endif