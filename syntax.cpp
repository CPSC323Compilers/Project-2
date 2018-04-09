#include "syntax.h"
#include "lexer.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int line_count = 1;

void retError() {
	cout << "\nError on line: " << line_count << endl;
}

bool ruleA(vector<Lexer> tokens, bool printSwitch) {
	cout << "<Rat18S>\n";
	string token;
	
	if(printSwitch) {
		cout << "A -> B %% BN\n";
	}
	
	if(ruleB(printSwitch)) {
		
	}
	
}
