#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include "util.hpp"
#include <regex>
#include <bits/stdc++.h>

// function show_usage() print a message describing proper usage 
void WWF::show_usage(std::string name) {
    std::string msg;
    if ( name.size() ==0 ) {
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


// function not_implemented() print msg then exit
void WWF::not_implemented(std::string option) {
    std::cerr << "Option " << option << " has not yet been implemented.\n";
    return;
} // END not_implemented()


// function get_dictionary() return a pointer to the dictionary file
std::set<std::string> WWF::get_dictionary() {

    // perl calls this a file handle, fh
    std::ifstream fh;

    // name the dictionary file to open
    const std::string fname = "/home/lundberg/Downloads/enable1.txt";

    // open the file handle
    fh.open(fname, std::ios::in);

    // did it open? alert and exit if not
    if ( ! fh ) {
        std::cerr << "error opening " << fname << " for read.\n";
    }

    // declare the SET to hold all dictionary words
    std::set<std::string> Dictionary;
    std::string word;

    // line-by-line read the file into a SET container
    while (fh >> word ) {
        Dictionary.insert(word);
    }

    // clean up
    fh.close();

    // confirm the file got slurped
    std::cout << Dictionary.size() << " words in dictionary.\n";

    // this will need a proper return value, like the SET name
    return Dictionary;

}


struct comp {
    template <typename T>
 
    // Comparator function
    bool operator()(const T& l, const T& r) const
    {
        if (l.second != r.second) {
            return l.second < r.second;
        }
        return l.first < r.first;
    }
};


// Function to sort the map according
// to value in a (key-value) pairs
void WWF::sort(std::map<std::string, int>& M)
{
 
    // Declare set of pairs and insert
    // pairs according to the comparator
    // function comp()
    std::set<std::pair<std::string, int>, comp> S(M.begin(), M.end());
 
    // Print the sorted value
    for (auto& it : S) {
        std::cout << it.first << ' ' << it.second << "\n";
    }
} // end sort()


// sort by value the permutations which were found in the dictionary. Pardon the 
// lame regex workaround
std::set<std::pair<std::string,int>> WWF::Words_Sorted(
            std::map<std::string, int>& M, 
            std::unordered_map<std::string,std::string> options )
{
    // Declare set of pairs and insert
    // pairs according to the comparator
    // function comp()
    std::set<std::pair<std::string, int>, comp> S(M.begin(), M.end());

    // Create a return SET container and a vectopr for regex matches
    std::set<std::pair<std::string,int>> return_value;
    std::vector<std::string> regex_matches;
    std::regex regex_input;
    bool isRegex = false;

//    std::cout << "About to test regex.\n";

    options.count("regex") == 1 ? isRegex = true : isRegex = false;

    if ( options.count("regex") == 1 ) {
        isRegex = 1;
        // this casts the std::string input to a std::regex
        regex_input = std::regex( options.at("regex") );
    }

//    std::cout << "Tested regex.\n";

    for (auto& it : S) {
        // this prints the valid, sorted words to the screen
        std::cout << it.first << ' ' << it.second << "\n";
        if ( isRegex ) {
            if ( std::regex_search(it.first, regex_input ) ) {
                // long-ass process to cast an int to a string
                std::stringstream stream;
                stream << it.second;
                std::string str;
                stream >> str;
                std::string cluster = it.first + ", " + str;
                regex_matches.push_back( cluster );
            }
        }
    }
    if ( regex_matches.size() ) {
        std::cout   << regex_matches.size() 
                    << " words match your regex \"" 
                    << options.at("regex")
                    << "\"\n";
    
        for ( auto elem : regex_matches ) {
            std::cout << elem << "\n";
        }
    }

    return return_value;
} // end Words_Sorted()


// Words_Printed.
void WWF::Words_Printed( std::set<std::pair<std::string,int>>& sorted)
{
    // Print the sorted value
    for (auto& it : sorted ) {
        std::cout << it.first << ' ' << it.second << "\n";
    }
}

