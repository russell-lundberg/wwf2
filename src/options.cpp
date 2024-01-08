//
//  options.cpp
//  xcode2
//
//  Created by Russell Lundberg on 12/21/23.
//

#include "options.hpp"
#include <string>
#include <iostream>
#include <regex>
#define _DEBUG


/*
* ingest_args() needs to
 *  parse argv, poke options into a map container
*/
// function show_usage() print a message describing proper usage
void show_usage( std::string name ) {
    std::string msg;
    if ( name.size() == 0 ) {
        msg = "Usage:\n";
    }
    else {
        msg = "Usage: " + name + "\n";
    }
    std::cerr << msg
              << "Options:\n"
              << "\t-h,--help\t\tShow this help message\n"
              << "\t-b,\t\thand contains a blank tile\n"
              << "\t-B,\t\thand contains 2 blank tiles\n"
              << "\t-d,\t\tsearch the dictionary for provided regex\n"
              << "\t-e,\t\tadd letter(s) to the rack\n"
              << "\t-l,\t\tshow results having this many letters\n"
              << "\t-r,\t\tletters in the rack\n"
              << "\t-x,\t\tfilter results by provided regex\n"
              << "\n";
}
// END show_usage()



// 
/*
std::unordered_map<std::string,std::string> ingest_args( int argc, char* argv[]) {
    //std::vector<std::string> WWF::ingest_args( int argc, char* argv[]) {
    
    // only silencing a preprocessor warning
    int zip = argc;
    zip = 0;

    std::string nothing = "";
    
    // store variables in a unordered_map container return value
    std::unordered_map<std::string,std::string> arg;
    
    
    
    return arg;
} // end ingest::args()
*/


// unordered_map process_argv( argv )
std::unordered_map<std::string,std::string> process_argv( int argc, char* argv[] ) {
    
    #ifdef _DEBUG
    std::cout << argc << " args received.\n";
    #endif
    // unordered_map container holding arg,value pairs
    std::unordered_map<std::string,std::string> options;
    
    /*
    #ifdef _DEBUG
    std::cout << "using the for loop";
    // loop through all argv element looking for optionsa and values
    // argv[0] is the program name
    for ( int i = 1 ; i < argc ; i++ )
    {
        std::string option = optionLetter( argv[i] );
        if ( isOption( argv[i] )) {
            // this arg is an option, not a value. if the next arg
            // also begins with "-", then this arg has no assigned value
//            std::cout << argv[i] << " is an option ( i=" << i << ").\n";
            // there might not be any more options, so test for that
            if ( i+1 <= argc && isOption( argv[i+1] ) ) {
//                std::cout << "option " << i+1 << "has no value.\n";
                //this is also an option, so argv[i] is an option
                // having no value
                std::string optionValue = valuelessOption( argv[i]);
//                std::cout << argv[i] << " returned value " << optionValue << ").\n";
                options.emplace(option,optionValue);
            }
            else {
//            std::cout << "option " << i+1 << " value is " << argv[i+1] << ".\n";
                // argv[i+1] is a value, so save it. Mind the subscripts,
                // easy to get wrong
                options.emplace(option,argv[++i]);
            }
        }
        else {
            // this should not happen, so alert
            std::cout << "arg " << i << " erroneously not an option.\n";
        }
    } // end for loop
    #el
    */

    std::cout << "All options processed.\n";

    // force the map for debugging
    options.insert({"b","blank1"});
    options.insert({"r","abcd"});
    options.insert({"e","e"});
    options.insert({"lettersIn","abcde"});

    // just as a check, print the options
    for ( auto elem : options ) {
        std::cout << "Option " << elem.first << ", value="
        << elem.second << ".\n";
    }
//    std::cout << "Options are:\n";
//    for ( auto itr = options.begin() ; itr != options.end() ; ++itr ) {
//        std::cout << itr->first << "->" << itr->second << "\n";
//    }
    return options;
}
                

// return what remains after a match value is an actual input from 
// the command line, so it includes a leading "-" for options
std::string optionLetter( std::string value )
{
    std::smatch match;
    // check that the value begins with a hyphen
    std::regex_search(value, match, std::regex("^-") );
    if ( match.empty() ){
        std::cout << "No match for " << value << ".\n";
    }
    else {
        std::cout << "optionLetter(). option=" << value << ", match=" << match.size();
//        std::cout << ", match="; << match << ".\n";
    }
    return std::string( match.suffix() );
}

bool isOption( std::string value )
{
//    std::cout << "isOption(): \n";
    std::smatch match;
    // check that the value begins with a hyphen
    try {
     std::regex_search(value, match, std::regex("^-") );
    }
     catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
     if ( match.size() == 0 ) return false;
     return true;
//    return std::regex_search(value, match, std::regex("^-") );
}

// Option s/b assigned on the command line when the program is launched.
// All options having command line values should not get to this point
std::string valuelessOption( std::string Option )
{
//    std::cout << "valuelessOption(): \n";
    if ( Option == "-b" )
        return "blank1";
    else if ( Option == "-B" )
        return "blank2";
    else if ( Option == "-h" )
        return "help";
    else {
        std::cout   << "options::valuelessOption() returned \""
        << Option << "\"\n";
        return std::string( Option );
    }
}
