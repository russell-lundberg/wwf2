#include <fstream>
#include <iostream>
#include <vector>
#include <set>

// use set<> container
int main (int argc, char* argv[]) {

    // perl calls this a file handle, fh
    std::ifstream fh;

    // name the dictionary file to open
    const std::string fname = "/home/lundberg/Downloads/enable1.txt";

    // open the file handle
    fh.open(fname, std::ios::in);

    // did it open? alert and exit if not
    if ( ! fh ) {
        std::cerr << "error opening " << fname << " for read.\n";
	return 0;
    }

    // declare the vector to hold all dictionary words
    std::set<std::string> Dictionary;
    std::string word;

    // line-by-line read the file into our vector of strings
    while (fh >> word ) {
//        Dictionary.push_back(word);
        Dictionary.insert(word);
    }

    // clean up
    fh.close();

    // confirm the file got slurped
    std::cout << "Dictionary has " << Dictionary.size() << " words.\n";

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


    return 1;

}


