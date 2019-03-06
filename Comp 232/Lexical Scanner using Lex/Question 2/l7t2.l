/**
Name : Yulia Maliauka 
Date : March 8, 2017 
Lab 7 Question 2 
Professor Bieszczad, Professor Scrivnor
**/ 

%option noyywrap

%{
#include "l7t2.h"
%}

num [0-9]+
id [A-PR-Za-pr-z0-9]+
whitespace [\n\t ]+

%%

{whitespace}

"if"      {return IF;}
"then"    {return THEN;}
"while"    {return WHILE;}
"do"    {return DO;}
"print"    {return PRINT;}

{num} {return NUMBER;}
{id} {return IDENTIFIER;}

"+"|"-" {return ADDOP;}
"*"|"/"|"%" {return MULTOP;}

"=" {return ASSIGNMENT;}
";" {return SCOLON;}
"(" {return LPAREN;}
")" {return RPAREN;}

%%