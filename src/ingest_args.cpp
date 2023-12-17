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
#include <unordered_map>


using vString = std::vector<std::string>;

// A helper function to simplify the main part.
template <class T>
std::ostream &std::operator<<(ostream &os, const vector<T> &v)
{
    copy(v.begin(), v.end(), ostream_iterator<T>(os, " "));
    return os;
} // end operator()

// copied with thanks from cppreference.com, std::tolower()
std::string WWF::str_tolower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), 
                   [](unsigned char c){ return std::tolower(c); } // correct
                  );
    return s;
}


// string lettersInput(string Rack, string Extend)
std::string WWF::lettersInput(std::string Rack, std::string Extend ) {
    std::string lettersIn = str_tolower( Rack );

    if ( Extend.empty() )
        return lettersIn;

    lettersIn += str_tolower( Extend );
    return lettersIn;
}


// ingest_args(). Process the input args
std::unordered_map<std::string,std::string> WWF::ingest_args( int argc, char* argv[]) {
//std::vector<std::string> WWF::ingest_args( int argc, char* argv[]) {

    std::string nothing = "";

    // store variables in a unordered_map container return value
    std::unordered_map<std::string,std::string> arg;
  
    po::options_description desc("Allowed options");
    int word_length = 0;

    // aggregate letters to pass to permutations generator
    std::string letters_input;
    std::string lettersIn = "";

    // indicate presence of 1 oe 2 blank tiles
//    int blanks = 0;

    
    try {
        //        po::options_description desc("Allowed options");
        desc.add_options()
        ("help,h", "Print this help message and exit")
        ("blank1,b", "Rack contains 1 blank char")
        ("blank2,B", "Rack contains 2 blank chars")
        ("extend,e", po::value<std::string>()->implicit_value(""), "Extend rack with these chars")
        ("filter,f", po::value<std::string>(), "Filter results by <regex>")
        ("group,g", po::value<std::string>(), "Create words using this contiguous group of chars")
        ("length,l", po::value<int>(&word_length)->default_value(5), "Display words at least this long")
        ("rack,r", po::value<std::string>(), "Rack of chars to combine into words")
        ("search,s", po::value<std::string>(), "Search dictionary for <regex>")
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

        // presently, a blank must be defined, even if it is 0
        if (vm.count("blank1") || vm.count("blank2") ) {
            if (vm.count("blank1"))
                arg.emplace("blanks", "blank1");
            if (vm.count("blank2") ) 
                arg.emplace("blanks", "blank2");
        }
        else {
            // if no blank defined, say so
            arg.emplace("blanks", "blank0");
        }

        if (vm.count("rack") ) {
            std::string theRack = "";
            theRack = vm["rack"].as<std::string>();
            arg.insert({"rack",theRack});
            std::string theExtend = "";
            if (vm.count("extend") ) {
                theExtend = vm["extend"].as<std::string>();
                arg.insert({"extend",theExtend});

                lettersIn = lettersInput(   theRack, theExtend );
                arg.insert({"lettersIn",lettersIn});
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
    std::cout << "Ingest_args(): Letters in " << lettersIn << "\n";

    return arg;

    /*
    std::vector<std::string> Permutations;
    Permutations = WWF::create_permutations( lettersIn, blanks );

    std::cout << Permutations.size() << " Permutations returned from \"" << lettersIn << "\".\n";

    return Permutations;
    */

} // end ingest_args()
