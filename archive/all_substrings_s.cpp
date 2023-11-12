#include <iostream>
#include <set>
#include <algorithm>

namespace WWF
{

std::set<std::string> all_substrings_s (std::string letters ) 
{
    std::set<std::string> subs_s;
    subs_s.insert(letters);

    // if empty string passed, return immediately
    if ( letters == "" ) {
        subs_s.insert("");
        return subs_s;
    }

    std::string before;

    // assign the first remaining char to current, then 
    // delete that char from letters
    std::string current = letters.substr(0,1);

    while ( current.size() != 0 ) {
        std::set<std::string> this_loop;
        subs_s.insert(current);

        // can remove the char here or at end of loop
        letters.erase(0,1);

        this_loop = WWF::all_substrings_s( letters );
        for ( auto elem : this_loop ) {
            subs_s.insert( before + elem );
        }
        before += current;
        subs_s.insert(before);
        current = letters.substr( 0, 1 );
    }
    return subs_s;
}


} // close the namespace declaration