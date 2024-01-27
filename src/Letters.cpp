/*
*  Letters.cpp
*  wwf2
*
* Created by Russell Lundberg on 10/24/23.
* this works to load the letters with their assigned values.
* it uses an ordered_map as an associative array
*/

#include <iostream>
#include <map>


namespace Letters {


std::map<char,int> Score() {

    std::map<char,int>Scores;

    Scores.emplace(std::pair<char,int>('a',1));
    Scores.emplace(std::pair<char,int>('b',4));
    Scores.emplace(std::pair<char,int>('c',4));
    Scores.emplace(std::pair<char,int>('d',2));
    Scores.emplace(std::pair<char,int>('e',1));
    Scores.emplace(std::pair<char,int>('f',4));
    Scores.emplace(std::pair<char,int>('g',3));
    Scores.emplace(std::pair<char,int>('h',3));
    Scores.emplace(std::pair<char,int>('i',1));
    Scores.emplace(std::pair<char,int>('j',10));
    Scores.emplace(std::pair<char,int>('k',5));
    Scores.emplace(std::pair<char,int>('l',2));
    Scores.emplace(std::pair<char,int>('m',4));
    Scores.emplace(std::pair<char,int>('n',2));
    Scores.emplace(std::pair<char,int>('o',1));
    Scores.emplace(std::pair<char,int>('p',4));
    Scores.emplace(std::pair<char,int>('q',10));
    Scores.emplace(std::pair<char,int>('r',1));
    Scores.emplace(std::pair<char,int>('s',1));
    Scores.emplace(std::pair<char,int>('t',1));
    Scores.emplace(std::pair<char,int>('u',2));
    Scores.emplace(std::pair<char,int>('v',5));
    Scores.emplace(std::pair<char,int>('w',4));
    Scores.emplace(std::pair<char,int>('x',8));
    Scores.emplace(std::pair<char,int>('y',3));
    Scores.emplace(std::pair<char,int>('z',10));

    /*
    for ( const auto& elem : Scores ) {
        std::cout << "Tile: " << elem.first
            << ", Value: " << elem.second
            << "\n";
    }
    */

    return Scores;
} // end main()

} // close namespace declaration
