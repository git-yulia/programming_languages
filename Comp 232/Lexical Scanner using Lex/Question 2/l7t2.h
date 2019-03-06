/**
Name : Yulia Maliauka 
Date : March 8, 2017 
Lab 7 Question 2 
Professor Bieszczad, Professor Scrivnor
**/ 

#ifndef l7t2_h_
#define l7t2_h_

#include <stdio.h>

typedef enum {
   // KEYWORDS
   IF = 258, 
   THEN,         
   WHILE,   
   DO,       
   PRINT, 
   //
   // ALPHANUMERICS
   NUMBER,     
   IDENTIFIER,
   //  
   // OPERATIONS
   ADDOP, 
   MULTOP, 
   //
   // MISC. 
   ASSIGNMENT, 
   SCOLON,
   LPAREN, 
   RPAREN
   //
} TOKEN;

#endif