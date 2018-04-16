#include "syntax.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

/*--------------------------------Global Variable-------------------------------------*/

void isGeneratedS();
void keywordState();


void Syntax::isGeneratedS() {
  ifstream fs("Tokens.txt");	//Open file
  //Check that the file is open
  if(!fs.is_open()) {
    cout << "Could not find file. Aborting." << std::endl;
  }
  
  bool commentState = false;
  string comments = "";
  int keywordCounter = 0;
	
  // read until white space, save string into temp
  while(!fs.eof()) {
	  string temp;
	  fs >> temp;
	  
	  if(temp =="Keyword"){
		 keywordCounter++; //just using this to check that its being read properly.
	  }
	  else if(temp == "Operator"){
		  //do this
	  }
	  
	  cout << temp << endl;
  }
  fs.close();
  cout << keywordCounter << endl;
}

void keywordState(){
	// we want to now check this rule
}

