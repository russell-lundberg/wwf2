#ifndef OPTIONS_HPP
#define OPTIONS_HPP
//
//  options.hpp
//  xcode2
//
//  Created by Russell Lundberg on 12/21/23.
//


#include <string>
#include <unordered_map>

void show_usage(std::string );

// std::unordered_map<std::string,std::string> ingest_args( int, char**);
std::unordered_map<std::string,std::string> process_argv( int, char** );

std::string optionLetter( std::string );

bool isOption( std::string );

std::string valuelessOption( std::string );

#endif /* OPTIONS_HPP */
