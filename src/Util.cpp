//
//  Util.cpp
//  wwf2
//
//  Created by Russell Lundberg on 10/24/23.
//

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include "Util.hpp"
#include "Options.hpp"
#include <regex>
#include <sstream>

// function not_implemented() print msg then exit
void Util::not_implemented(std::string option) {
    std::cerr << "Option " << option << " has not yet been implemented.\n";
    Options::show_usage("");
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

    // name the dictionary file to open. This file ias in the top level 
    // directory of the project
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

/*
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
*/


// replace the Boost::Math::Factorial()
int Util::factorial( int n) {
    int result = 1;
    for (int i=1; i <=n ; i++ ) {
        result *= i;
    }
    return result;
}

