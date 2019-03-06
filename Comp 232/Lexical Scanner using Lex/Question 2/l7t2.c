/**
Name : Yulia Maliauka 
Date : March 8, 2017 
Lab 7 Question 2 
Professor Bieszczad, Professor Scrivnor
**/ 

#include "l7t2.h"

extern char *yytext; 

int main(void) {

	TOKEN tok;

	char *tokenTypes[] = {"if", "then", "while", "do", "print", "number", "identifier", "addOp", "multOp", "assignment", "semicolon", "lparen", "rparen"};

	while ((tok = yylex()) != 0) {
		tok -= IF; 

		// "+"|"-" {return ADDOP;}

		switch ((int)tok) {
			// KEYWORDS : Prints "keyword", type 
			case 0:
			case 1:
			case 2:
			case 3: 
			case 4: 
					printf("{<keyword> \"%s\"} , ", tokenTypes[tok]); 
					break; 
			// ALPHANUMERICS AND OPERATIONS : Prints type, content
			case 5:
			case 6: 
			case 7: 
			case 8:
					printf("{<%s> %s} , ", tokenTypes[tok], yytext); 
					break; 
			// MISC. : prints content only 
			case 9:
			case 10: 
			case 11:
			case 12: 
					printf("{%s} , ", tokenTypes[tok]); 
					break; 
			default: printf("\n!*/$UNRECOGNIZED TOKEN&^#!\n");
		}  

	}

	printf("\n");
	return 0; 
}



















//
