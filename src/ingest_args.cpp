// Copyright Vladimir Prus 2002-2004.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/program_options.hpp>

using namespace boost;
namespace po = boost::program_options;

#include <iostream>
#include <algorithm>
#include <iterator>
#include <ostream>
#include <string>
#include <cstring>
#include "create_permutations.hpp"
#include "util.hpp"


using vString = std::vector<std::string>;

// A helper function to simplify the main part.
template <class T>
std::ostream &std::operator<<(ostream &os, const vector<T> &v)
{
    copy(v.begin(), v.end(), ostream_iterator<T>(os, " "));
    return os;
}

std::vector<std::string> WWF::ingest_args( int argc, char* argv[]) {

    std::string nothing = "";

  
    po::options_description desc("Allowed options");
    int word_length = 0;

    // aggregate letters to pass to permutations generator
    std::string letters_input;

    // indicate presence of 1 oe 2 blank tiles
    int blanks = 0;

    
    try {
        //        po::options_description desc("Allowed options");
        desc.add_options()
        ("help,h", "Print this help message and exit")
        ("blank1,b", "Rack contains 1 blank char")
        ("blank2,B", "Rack contains 2 blank chars")
        ("extend,e", po::value<std::string>()->implicit_value(""), "Extend rack with these chars")
//        ("extend,e", po::value<std::string>(), "Extend rack with these chars")
        ("filter,f", po::value< vString >(), "Filter results by <regex>")
        ("group,g", po::value< vString >(), "Create words using this contiguous group of chars")
        ("length,l", po::value<int>(&word_length)->default_value(5), "Display words at least this long")
        ("rack,r", po::value< std::string >(), "Rack of chars to combine into words")
        ("search,s", po::value< vString >(), "Search dictionary for <regex>")
        ;

        po::variables_map vm;

        po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);
        po::notify(vm);

        // this is only to silence a warning
        if ( argc == 0 ) {
            WWF::show_usage( nothing );
        }
        else if ( argc == 1 ) {
            std::cout << "You entered " << argc - 1
                  << " arguments:" << "\n";
            WWF::show_usage( nothing );
        }
        else {
            // elem must be converted using <cstring> library
            std::string array;
            for ( int i = 0 ; i < argc ; i++ ) {
                std::string space = " ";
                array += argv[i] + space;
            }
        }


        if (vm.count("help")) {
            std::cout << "Usage: program [options]\n";
            std::cout << desc;
        }

        if (vm.count("blank1") ) {
            std::cout << "There is one blank character\n";
            blanks = 1;
        }

        if (vm.count("blank2") ) {
            std::cout << "There are two blank characters\n";
            blanks = 2;
        }

        if (vm.count("rack") ) {
            std::cout << "Rack letters used to make words: "
                 << vm["rack"].as<std::string>() << "\n";

                letters_input += vm["rack"].as<std::string>();
            

            if (vm.count("extend") ) {
                std::cout << "Board letters to combine with rack letters: "
                     << vm["extend"].as<std::string>() << "\n";
                letters_input += vm["extend"].as<std::string>();
            }
        }

        if (vm.count("subtract-dict") )
        {
            std::cout << "Disallowed words in WWF dictionary: "
                 << vm["subtract-dict"].as<vString>() << "\n";
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
    std::cout << "Letters in: " << letters_input << "\n";

//    std::vector<std::string> Permutations = WWF::create_permutations( letters_input );
    std::vector<std::string> Permutations;
    Permutations = WWF::create_permutations( letters_input, blanks );

    std::cout << Permutations.size() << " Permutations returned from \"" << letters_input << "\".\n";

    return Permutations;

}
