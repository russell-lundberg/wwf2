#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include "util.hpp"

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


    // code below to test that dictionary was opened
    /*
    std::vector<std::string> input = {"e","o","t","h","c","a","p"};
    std::vector<std::string> valid_words;
    std::vector<std::string> candidates;
    candidates.push_back("cat");
    candidates.push_back("dog");
    candidates.push_back("crush");
    candidates.push_back("table");
    candidates.push_back("fdxc");
    candidates.push_back("qqqqq");

    for ( auto & word : candidates ) {
        if ( Dictionary.find(word) != Dictionary.end() ) {
            valid_words.push_back(word);
        }
    }

    std::cout << "there are " << valid_words.size() << " valid words.\n";
    */

    // this will need a proper return value, like the SET name
    return Dictionary;

}

