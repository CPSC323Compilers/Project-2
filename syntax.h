#ifndef _SYNTAX_H
#define _SYNTAX_H
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "lexer.h"

class Syntax{
public:
	Syntax();
};

bool ruleA(std::vector<Lexer> tokens, bool printSwitch);
//bool ruleB(bool printSwitch);
void retError();

#endif
