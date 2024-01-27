//
//  util.cpp
//  wwf4
//
//  Created by Russell Lundberg on 1/24/24.
//

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include "util.hpp"
#include <regex>
#include <sstream>

// function not_implemented() print msg then exit
void WWF::not_implemented(std::string option) {
    std::cerr << "Option " << option << " has not yet been implemented.\n";
    return;
} // END not_implemented()


/*
 *
* function get_dictionary() return a pointer to the dictionary file
*
 */
std::set<std::string> Util::get_dictionary() {

    // perl calls this a file handle, fh
    std::ifstream fh;

    // name the dictionary file to open
//    const std::string fname = "/home/lundberg/Downloads/enable1.txt";
    const std::string fname = "dictionary.txt";


    // open the file handle
    try {
        fh.open(fname, std::ios::in);
    }
    catch (std::exception &e)
       {
           std::cout << " Util::get_dictionary(): " << e.what() << "\n";
    }

    // did it open? alert and exit if not
    if ( ! fh ) {
        std::cerr << "error opening " << fname << " for read (89).\n";
        exit(89);
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

//    options.count("regex") == 1 ? isRegex = true : isRegex = false;
    if (options.find("regex") != options.end() ) {
        isRegex = true;
    }
    
    // std::cout << "Util::Words_Sorted(): isRegex = " << isRegex << "\n";

    for (auto& it : S) {
        // this prints the valid, sorted words to the screen
        std::cout << it.first << ' ' << it.second << "\n";
        if ( isRegex ) {
            regex_input = std::regex( options.at("regex") );
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

    if ( isRegex ) {

        if ( regex_matches.size() ) {
            std::cout   << regex_matches.size()
                        << " words match your regex \""
                        << options.at("regex")
                        << "\"\n";
            for ( auto elem : regex_matches ) {
                std::cout << elem << "\n";
            }
        }
        else {
            std::cout << "Words_Sorted(): no words match \"" << options.at("regex") << "\"\n";
        }
    }
    return return_value;
} // end Words_Sorted()


// replace the Boost::Math::Factorial()
int WWF::factorial( int n) {
    int result = 1;
    for (int i=1; i <=n ; i++ ) {
        result *= i;
    }
    return result;
}

