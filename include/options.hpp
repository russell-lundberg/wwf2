//
//  options.hpp.h
//  wwf4
//
//  Created by Russell Lundberg on 12/21/23.
//

#ifndef options_hpp_h
#define options_hpp_h


#include <string>
#include <unordered_map>

namespace Options {
void show_usage( std::string );

std::unordered_map<std::string,std::string> process_argv( int, char** );

void Option_Switch( int, char**, int*, std::unordered_map<std::string,std::string>* );
}

//void show_usage(std::string );

//std::unordered_map<std::string,std::string> process_argv( int, char** );

std::string optionLetter( std::string );

bool isOption( char* );

std::string valuelessOption( std::string );

std::string valuefulOption( std::string );

void Letters_In( std::unordered_map<std::string,std::string>* );

std::string str_tolower(std::string s);

//void Option_Switch( int, char**, int*, std::unordered_map<std::string,std::string>* );


#endif /* options_hpp_h */
