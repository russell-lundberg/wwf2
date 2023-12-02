#include <iostream>
#include <string>
#include <unordered_map>
#include "util.hpp"

/*
 * this works to load the letters with their assigned values.
 * it uses an unordered_map as an associative array
 *
 */

std::map<std::string,int> WWF::LetterScore() {

	std::map<std::string,int> LetterScore;

    LetterScore.insert(std::make_pair("blank",0));
    LetterScore.insert(std::make_pair("a",1));
    LetterScore.insert(std::make_pair("b",4));
    LetterScore.insert(std::make_pair("c",4));
    LetterScore.insert(std::make_pair("d",2));
    LetterScore.insert(std::make_pair("e",1));
    LetterScore.insert(std::make_pair("f",4));
    LetterScore.insert(std::make_pair("g",3));
    LetterScore.insert(std::make_pair("h",3));
    LetterScore.insert(std::make_pair("i",1));
    LetterScore.insert(std::make_pair("j",10));
    LetterScore.insert(std::make_pair("k",5));
    LetterScore.insert(std::make_pair("l",2));
    LetterScore.insert(std::make_pair("m",4));
    LetterScore.insert(std::make_pair("n",2));
    LetterScore.insert(std::make_pair("o",1));
    LetterScore.insert(std::make_pair("p",4));
    LetterScore.insert(std::make_pair("q",10));
    LetterScore.insert(std::make_pair("r",1));
    LetterScore.insert(std::make_pair("s",1));
    LetterScore.insert(std::make_pair("t",1));
    LetterScore.insert(std::make_pair("u",2));
    LetterScore.insert(std::make_pair("v",5));
    LetterScore.insert(std::make_pair("w",4));
    LetterScore.insert(std::make_pair("x",8));
    LetterScore.insert(std::make_pair("y",3));
    LetterScore.insert(std::make_pair("z",10));

    /*
    for ( const auto& elem : LetterScore ) {
	    std::cout << "Tile: " << elem.first
		    << ", Value: " << elem.second
		    << "\n";
    }
    */

    return LetterScore;
} // end main()
