#ifndef _SYNTAX_H
#define _SYNTAX_H
#pragma once

#include <iostream> 	//std::cout
#include <string>	//string::string, string::length(), 
#include <fstream>	//ofstrea::ofstream, ifstream::ifstream, open, close
#include <vector>	//for vector, vector::size()
#include <cctype>	//isdigit(), isalpha()
#include <iomanip>	//std::setw() 

using namespace std;

class Syntax{
public:
	string state;
	string variable;
	void isGeneratedS();
	
};
#endif

