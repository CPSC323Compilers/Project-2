#include "lexer.h"

using namespace std;

/*--------------------------------Global Variable-------------------------------------*/
vector<Lexer> tokens;

/*-------------------------Function headers-------------------------------------------*/
void putVector(string original, string state);		//A helper function to add element to vector
bool isIdentifier(string original);					//Verifies if given word is valid identifier
bool isReal(string original);						//Verifies if given word is valid real
bool isInteger(string original);						//Verifies if given word is valid integer
bool isSeparator(string original);											//Verifies if given word is valid separator
bool isOperator(string original);											//Verifies if given word is valid operator
bool isValid(string original);
void print_list();								//Prints our list out to console and text file
void isGenerated();


/* ----------Const keywords, operators, and separators--------------------------------*/
const string keywords[] = { "function", "int", "boolean", "real", "if", "endif", "else", "return", "put", "get", "while", "true", "false" };
const string operators[] = { "=", "==", "^=", ">", "<", "=>", "=<", "+", "-", "*", "/", "_" };
const string separators[] = { "%%", "[", "]", ",", ";", "{", "}", ":", "(", ")" };

const int num_key = 13;
const int num_op = 12;
const int num_sep = 10;

/*-----------------------------------Start of main------------------------------------*/
vector<Lexer> Lexer::isGenerated() {
  ifstream fs("test1.txt");	//Open file
  //Check that the file is open
  if(!fs.is_open()) {
    cout << "Could not find file. Aborting." << std::endl;
  }
  
  bool commentState = false;
  string comments = "";
	
  // read until white space, save string into temp
  while(!fs.eof()) {
	  string temp;
	  fs >> temp;
	  
	  /*----Handles comments----*/
	  if(temp == "!" && commentState == true) {
	  	comments += temp + ' ';
		putVector(comments, "Comment");
		comments = "";	//Clear our buffer
		commentState = false;
	  }
	  
	  //Switch our commentState to off when the next '!' is found
	  else if(temp == "!" && commentState == false) {
	  	commentState = true;
	  }
	  
	  if(commentState) {
		  comments += temp + ' ';
	  }
	  
	  /*-------Non-comment section--------*/
	  else {
		  isValid(temp);
	  }
  }
  fs.close();
  return tokens;
}
/*-----------------------------------End of main------------------------------------*/

/*------------------------------print function--------------------------------------*/
void Lexer::print_list() {
	
	const int space = 20;
	filebuf fb;
	fb.open("Tokens.txt", ios::out);
	ostream os(&fb);
	
	cout << " === State ===" << setw(space) << "=== Token ===\n";
	os << " === State ===" << setw(space) << "=== Token ===\n";
	 
	for(int i = 0; i < tokens.size(); i++) {
		int indent = space - tokens[i].state.length();
		cout << right << tokens[i].state << left << setw(indent) << " " << tokens[i].variable << endl;
		os << right << tokens[i].state << left << setw(indent) << " " << tokens[i].variable << endl;
	}
	fb.close();
}
/*------------------------------END print function--------------------------------------*/
bool isIdentifier(string original) {
 	for(int i = 0; i < original.length(); i++) {
		// condition checks the strings first character, meets condition if first character is not a digit
		// Checks to make sure that the word does not have a symbol in the middle
		if(i != original.length()-1) {
			if(!isalpha(original[i]) && !isdigit(original[i])) { 
				cout << original << " contains a non-alphabet or non-digit.\n";
				return false;
			} 
		}
		
		//Checks the last character of the word to make sure that it ends in either an letter or $
		else {
			if(!isalpha(original[i]) && original[i] != '$') {
				cout << original << " does not end with either an alphabet or a '$'. \n";
				return false;
			}
		}
	}
	putVector(original, "Identifier");
	return true;
}

bool isReal(string original) {
	//There must be exactly one dot. Integers must both precede and follow the dot.
	int dotcount = 0;
	
	for(int i = 0; i < original.length(); i++) {
		if(!isdigit(original[i])) {
			if(original[i] == '.') {
				dotcount++;
			}
			else {
				cout << original << " has something other than a dot or digit\n";
				return false;
			}
		}
		if(dotcount == 2) {
			cout << original << " has too many dots for this to be real..." << endl;
			return false;
		}
	}
	
	putVector(original, "Real");
	return true;
}

bool isInteger(string original) {
	for(int i = 0; i < original.length(); i++) {
		if(!isdigit(original[i]) && original[i] != '.') {
			return false;
		}
		else if(original[i] == '.') {
			cout << "Integer found a dot. Testing if it's a real.\n";
			if(isReal(original)) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	
	putVector(original, "Integer");
	return true;
}

bool isKeyword(string original) {
	for(int i = 0; i < num_key; i++) {
		if(original == keywords[i]) {
			return true;
		}
	}
	return false;
}
bool isSeparator(string original) {
	//Checks the last character of the word to make sure that it does not have alpha or $ in string.
	if (!isalpha(original[0]) && original[0] != '$'){
		for(int i = 0; i < num_sep; i++) {
			if(original == separators[i]) {
				putVector(original, "Separator");
			}
			else if(original == operators[i]){
				putVector(original, "Operators");
			}
		}
	}
	return true;
}

bool isOperator(string original) {
	//Checks the last character of the word to make sure that it does not have alpha or $ in string.
	if (!isalpha(original[0]) && original[0] != '$'){
		for(int i = 0; i < num_op; i++) {
			if(original == operators[i]) {
				putVector(original, "Operator");
				return true;
			}	
		}
	}
	return true;
}
bool isValid(string original) {
	if(isalpha(original[0])) {
		if(isIdentifier(original)) {
			//Check if the word is a keyword
			if(isKeyword(original)) {
				tokens.back().state = "Keyword";
			}
			return true;
		}
	}
	else if(isdigit(original[0])) {
		if(isInteger(original)) {
			return true;
		}
	}
	else if(isSeparator(original)){
		return true;
	}
	return false;
}

/*-------------Helper function to pushback to our token vector--------------------*/
void putVector(string var, string state) {
	Lexer token;
	token.variable = var;
	token.state = state;
	tokens.push_back(token);
}
