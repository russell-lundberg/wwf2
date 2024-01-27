/*
*  Words.cpp
*  wwf2
*
*  Created by Russell Lundberg on 1o/24/23.
* All functions are in the Words namespace
*/

#include <map>
#include <unordered_map>
#include <iostream>
#include <string>
#include <regex>
#include "Util.hpp"
#include "Words.hpp"
#include "Letters.hpp"

namespace Words {


/*
* "word" consists of lower-case letters, unless a blank option was invoked, in wqhich case the letter 
* is substituted upper-case. When letter values are applied, the upper case letter will be given a 
* value of 0, and then lower-cased for presentation.
*/
std::map<std::string,int> Score_Word ( std::string word )
{
    // get the Letter scores
    std::map<char,int> Letters = Letters::Score();

    // these vars constitute a map pair
    std::string scored_word = {};
    int Sum = 0;

    // loop though all the letters of the input. If upper case, value is zero,
    // so no need to add to the Sum
    for ( const char ch : word ) {
        // Print current character
        if ( isupper( ch )  ) {
            scored_word += std::tolower(ch, std::locale());
            // letter value derived from a blank is zero
        }
        else {
            Sum += Letters.at(ch);
            scored_word += ch;
        }
    }
    std::map<std::string,int> return_value = {};
    return_value.emplace(scored_word,Sum);
    return return_value;
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




/*
* 
* sort by value the permutations which were found in the dictionary. Pardon the
* lame regex workaround
*/
std::set<std::pair<std::string,int>> Sorted(
            std::map<std::string, int>& M,
            std::unordered_map<std::string,std::string> options )
{
    // Declare set of pairs and insert pairs according to the comparator
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
            std::cout << "Words::Sorted(): no words match \"" << options.at("regex") << "\"\n";
        }
    }
    return return_value;
} // end Words_Sorted()


}