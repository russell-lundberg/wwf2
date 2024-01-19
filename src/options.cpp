//
//  options.cpp
//  xcode2
//
//  Created by Russell Lundberg on 12/21/23.
//
#include <string>
#include <iostream>
#include <regex>
#include <unordered_map>
#include "options.hpp"


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
    
//    std::cout << argc << " args received.\n";

    // unordered_map container holding arg,value pairs
    std::unordered_map<std::string,std::string> options;

    // not a string, a container
    std::unordered_map<std::string,std::string>* ptr = &options;

    if ( argc == 1 ) {
        show_usage( "" );
        options.emplace("return","usage");
        return options;
    }
    
    // loop through all argv element looking for optionsa and values
    // argv[0] is the program name
    // to refactor this create a function that tests for each defined option,
    // and does the right thing with each one
    std::string lettersIn;
    
//    std::cout << "process_argv(): entering the for loop\n";

    for ( int i = 1 ; i < argc ; i++ )
    {
        int* idx = &i;

        Option_Switch( argc, argv, idx, ptr );
    } // end for loop

    std::cout << "All options processed.\n";

/*
    // just as a check, print the options
    for ( auto elem : options ) {
        std::cout << "process_argv(): Option " << elem.first << ", value="
        << elem.second << ".\n";
    }
*/
    return options;
} // end process_argv()
                

// Option_Switch( option, i, ptr_to_map )
// option is known to be an option, argv[i+1] is the next element in the argv array,
// and ptr_to_map is a reference to a map container
void Option_Switch( int count, char** arg, int* j, std::unordered_map<std::string,std::string>* n )
{
    // std::cout << "Option_Switch(): Entry.\n";
    // save all the inputted letters in this string. It will be added to the map at the end
    if ( strcmp(arg[*j],"-r") == 0 ) {
        // std::cout << "Option_Switch(): Option \"-r\" detected.\n";

        // test if the next argument would overflow argv
        if ( *j+1 >= count ) {
            // there are no more args, which means no letters were submitted to -r.
            // That's an error.
            std::cout << "\"-r\" option requires letters, exiting.\n";
            show_usage("");
            exit(1);
        }

        // test if the next arg is an option
        if ( isOption( arg[*j+1] ) ) {
            // this is also an error, because if the next argv element is an option, it again 
            // means no letters were submitted to -r. That's an error.
            std::cout << "\"-r\" option requires letters, exiting.\n";
            show_usage("");
            exit(1);
        }

        // std::cout << "Option_Switch: " << arg[*j] << " returned value " << arg[*j+1] << ".\n";
        ( *n ).emplace( "rank", arg[*j+1] );
        ( *n )["lettersIn"] += str_tolower( arg[*j+1] );
        // increment j becaue the j+1 arg has already been used. Don't want 
        // to use it in the for loop twice
        *j += 1;
    }
    else if ( strcmp(arg[*j],"-e") == 0 ) {
        // allow -e to be present without having a value
        // std::cout << "Option_Switch(): Option \"-e\" detected.\n";

        // test if the next argument would overflow argv
        if ( *j+1 < count ) {
            // there is at least one more argv element. Test if the next arg is an option
            if ( ! isOption( arg[*j+1] ) ) {
                // letters were submitted to -e, so ingest them
                // std::cout << "Option_Switch():" << arg[*j] << " returned value " << arg[*j+1] << ".\n";
                ( *n ).emplace( "extend", arg[*j+1] );
                ( *n )["lettersIn"] += str_tolower( arg[*j+1] );
                // increment j becaue we have already tested and used the j+1 arg
                *j += 1;
            }
        }
    }
    else if ( strcmp(arg[*j],"-x") == 0 ){
        // this is the regex option, that filters the valid words by matching this user-inputted regex. 
        std::cout << "Option_Switch(): Option \"-x\" detected.\n";

        // test if the next argument would overflow argv
        if ( *j+1 >= count ) {
            // thia means now value was submitted with the -x option. That's an error/
            std::cout << "Option_Switch(): \"-x\" option requires a regex, exiting.\n";
            show_usage("");
            exit(1);
        }

        // test if the next arg is an option
        if ( isOption( arg[*j+1] ) ) {
            // this is also an error, because if the next argv element is an option, it again 
            // means no regex was submitted with -x. That's an error.
            std::cout << "Option_Switch(): \"-x\" option requires a regex, exiting.\n";
            show_usage("");
            exit(1);
        }

        std::cout << "Option_Switch: " << arg[*j] << " returned value " << arg[*j+1] << ".\n";

        ( *n ).emplace( "regex", arg[*j+1] );
        // increment j becaue the j+1 arg has already been used. Don't want 
        // to use it in the for loop twice
        *j += 1;
    }
    else if ( strcmp(arg[*j],"-b") == 0 ) {
        // std::cout << "Option_Switch(): option b loop index value is " << *j << "\n";
        ( *n ).insert({"blanks","blank1"});
    }
    else if ( strcmp(arg[*j],"-B") == 0 ) {
        // std::cout << "Option_Switch(): option B loop index value is " << *j << "\n";
        ( *n ).insert({"blanks","blank2"});
    }
    else {
        // unrecognized option
        std::cout << "Arg : " << arg[*j] << " is not recognized.\n";
        show_usage("");
        exit(0);
    }
    // no return value
} // end Option_Switch()


bool isOption( char* value )
{
    // std::cout << "isOption(): starting test.\n";
    // if the string is empty, the length is 1 for the null terminating char
    if ( strlen(value) == 1 ) return false;

    // std::cout << "isOption(): value has a value\n";

    // cast the char* input arg to a string
    std::string string = std::string( value );

    std::smatch match;
    // check that the value begins with a hyphen
    try {
     std::regex_search(string, match, std::regex("^-") );
    }
     catch (std::exception &e)
    {
        std::cout << " Error from isOption(): " << e.what() << "\n";
    }
    if ( match.size() == 0 ) return false;

    return true;
} // end isOption()


// Letters_In() combines -r letters and optionally -e letters
// into a single value "letters_in" in the options map container
// 1) test for option{rank}, add to option{letters_in}
// 2) test for option{extend}, add to option{letters_in}
void Letters_In( std::unordered_map<std::string,std::string>* n ) {
    // std::cout << "Letters_In(): starting\n";
    std::string lettersIn = {};
    // can prolly dispense with this test
    if ( ( *n ).empty() ) {
        std::cout << "letters_In(): zero options defined, exiting.\n";
        exit(1);
    }
    ( *n ).insert({"again","testing"});
    /*
    for ( auto elem : ( *n ) ) {
        std::cout << "LettersIn(): Option=" << elem.first << ". Value: " << elem.second << ".\n";
    }
    */

    // std::cout << "Letters_In(): rank? " << ( *n ).at("r") << "\n";
    if (auto search = ( *n ).find("r"); search != ( *n ).end()) {
        std::cout << "LettersIn(): Found " << search->first << ' ' << search->second << '\n';
        lettersIn = str_tolower( search->second );
    }
    else {
        std::cout << "find failed for rank.\n"; 
    }

    // allow -e to be present without having a value
    if (auto search = ( *n ).find("e"); search != ( *n ).end()) {
        std::cout << "LettersIn(): Found " << search->first << ' ' << search->second << '\n';
        if ( ( *n ).at("e").empty() == 0 ) {
            // -e present but no value
            ( *n ).erase("n");
        }
        else {
            lettersIn += str_tolower( search->second );
        }
    }
    std::cout << "Letters_In(): Exiting " << lettersIn << ".\n";

    ( *n ).insert({"lettersIn", lettersIn});

    // no return value

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
//        std::cout << "optionLetter(). option=" << value << ", match=" << match.size() << "\n";
//        std::cout << ", match="; << match << ".\n";
    }
    return std::string( match.suffix() );
}

// Option s/b assigned on the command line when the program is launched.
// All options having command line values should not get to this point
std::string valuelessOption( std::string Option ) {
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


// Option s/b assigned on the command line when the program is launched.
// All options having command line values should not get to this point
std::string valuefulOption( std::string Option) {
//    std::cout << "valuefulOption(): \n";
    if ( Option == "r" )
        return "rank";
    else if ( Option == "e" )
        return "extend";
    else if ( Option == "x" )
        return "regex";
    else {
        std::cout   << "options::valuefulOption() unrecognized option: \""
        << Option << "\"\n";
        return std::string( Option );
    }
}


// copied with thanks from cppreference.com, std::tolower()
std::string str_tolower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), 
                   [](unsigned char c){ return std::tolower(c); } // correct
                  );
    return s;
}
