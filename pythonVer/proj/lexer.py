#!/usr/bin/python

import sys, os, os.path

# check will display if the proper arguments are not entered on console
_CHECK = "fileName.py <textFileName.txt> <outputFilename.txt>"
# ERRORNOFILE will display if with the input or output file do not exist within the directory
_ERRORNOFILE = "ERROR: INPUT/OUTPUT TEXT FILE DOES NOT EXIST"
class lexerUtility():
    def __init__(self):
        self.keywords = keywordList = ['while', 'if', 'endif','else','return','function', 'int', 'boolean', 'true','false','put','get']
        self.separators = separatorsList = ["(", ")", "{", "}", "[", "]", "," ]
        self.operators = operatorsList = ["<", ">", "<=", ">=", "=", "+", "-", "+=", "-=", "*", "/", "*=", "/="]
        self.ignore = ignoreList = ["#", "@"]
        self.delim = delimList = [";",":"]
        self.readFile();
    def readFile(self):
        # checks that there are 3 arguments entered within the console during compile times
        if len(sys.argv) != 3:
            print(_CHECK)
            exit(1)
        if os.path.isfile(sys.argv[1]):
            inputFile = sys.argv[1]
            outputFile = sys.argv[2]
        else:
            print(_ERRORNOFILE+ "\n"+ _CHECK)
            exit(1)

        self.lexer(inputFile, outputFile)
            
    def lexer(self, inputFile, outputFile):
        new_string = ""
        inFile = open(inputFile, 'r')
        outFile = open(outputFile, 'w')
        # write to file
        # display on console
        print("Tokens\t\tlexemes")
        print("------\t\t-------")
        for line in inFile:
            line = line.rstrip('\n')
            strippedLine = line.lower().split()
            for word in strippedLine:
                if word not in self.keywords and word not in self.separators and word not in self.operators and word not in self.delim:
                    for letter in word:
                        if letter in self.separators:
                            print("separator:\t"+ letter)
                            outFile.write("\nseparator:\t"+ letter)
                        elif letter in self.delim:
                            print("delim:\t\t" + letter)
                            outFile.write("\ndelim:\t\t"+ letter)
                        elif letter in self.operators:
                            print("operators:\t" + letter)
                            outFile.write("\noperators:\t"+ letter)
                        else:
                            # concatenates all the letters into a new string after checking that it doesnt meet the criteria above
                            new_string = new_string + letter
                    if new_string.isdigit() is True:
                        print("digit:\t\t" + new_string)
                        outFile.write("\ndigit:\t\t"+ new_string)
                        new_string = ""
                    else:
                        print("identifier:\t" + new_string)
                        outFile.write("\nidentifier:\t"+ new_string)
                        new_string = ""
                elif word in self.keywords:
                    print("keyword:\t" + word)
                    outFile.write("\nkeyword:\t"+ word)
                elif word in self.operators:
                    print("operators:\t" + word)
                    outFile.write("\noperators:\t"+ word)
                elif word in self.separators:
                    print("separators:\t" + word)
                    outFile.write("\nseparator:\t"+ word)
                else:
                    print("unidentified:\t" + word)
                    outFile.write("\nunidentified:\t"+ word)
                    
                    
class genAssemUtility():
    def __init__(self):
        self.keywords = keywordList = ['while', 'if', 'endif','else','return','function', 'integer', 'boolean', 'true','false','put','get']
        self.separators = separatorsList = ["(", ")", "{", "}", "[", "]", "," ]
        self.operators = operatorsList = ["<", ">", "<=", ">=", "=", "+", "-", "+=", "-=", "*", "/", "*=", "/="]
        self.ignore = ignoreList = ["#", "@"]
        self.delim = delimList = [";",":"]
        self.rules = rulesList = ["identifier:"]
        self.notIden = notIden = ["operators:","keywords:","separator:","delim:"]
        self.readFile();
    def readFile(self):
        inFile = open('test1.txt', 'r')
        self.assem(inFile)
            
    def assem(self, inFile):
        new_string = ""
        identifs = {}
        types = []
        registers = []
        data = []
        memory = 2000
        memoryVal = ""
        counter = 0
        for line in inFile:
            line = line.rstrip('\n')
            strippedLine = line.lower().split()
            for word in strippedLine:
                if word == '=':
                    registers.append("PUSHI")
                if word not in self.keywords and word not in self.separators and word not in self.operators and word not in self.delim and word not in identifs:
                    for letter in word:
                        if letter in self.separators:
                            pass
                        elif letter in self.delim:
                            pass
                        elif letter in self.operators:
                            pass
                        elif letter.isdigit() is True:
                            data.append(letter)
                        else:
                            # concatenates all the letters into a new string after checking that it doesnt meet the criteria above
                            new_string = new_string + letter
                    if new_string not in identifs and new_string != '':
                        # creates table for identifiers with its memory locations
                        lex = new_string
                        identifs[lex] = memory
                        memory+=1
                        new_string = ""
                
                        
        

        
                            
                    
                    
                            
        print("\n\nIdentifers")
        print(identifs.keys())
        print("\n\nIdentifers and memory addresses")
        print(identifs)
        print("\n\nAssembly")
        print(registers + data)
 

        
# create an instance of lexerUtility class
lexer = lexerUtility()
print("\nGenerating Assembly code...")
# create an instance of assmUtility class
genAssemOb = genAssemUtility()