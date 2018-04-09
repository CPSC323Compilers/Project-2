#include <iostream> 	//std::cout
#include <string>	//string::string, string::length(), 
#include <fstream>	//ofstrea::ofstream, ifstream::ifstream, open, close
#include <vector>	//for vector, vector::size()
#include <cctype>	//isdigit(), isalpha()
#include <iomanip>	//std::setw() 
#include "lexer.h"
#include "syntax.h"

using namespace std;


int main(){
	vector<Lexer> tokens;
	Lexer lexer;
	tokens = lexer.isGenerated();
	lexer.print_list();
	
	return 0;
}
