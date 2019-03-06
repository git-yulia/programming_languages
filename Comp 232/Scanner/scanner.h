//
//  scanner.h
//
//  Created by Bieszczad, A.J. on 2/21/13.
//  Copyright (c) 2013 CSUCI. All rights reserved.
//

typedef enum {
   INVALID_TOKEN = 0,
   NUMBERTOKEN, // 1
   IDENTTOKEN,  // 2
   ASSIGNMENT,  // 3
   SEMICOLON,   // 4
   LPAREN,      // 5
   RPAREN,      // 6
   PLUS,        // 7
   MINUS,       // 8
   MULT,        // 9
   DIV,         // 10
   MOD,         // 11
   REPEAT,      // 12
   PRINT,       // 13
   END_OF_INPUT_TOKEN // 14
} TOKEN_TYPE;

typedef struct token
{
   TOKEN_TYPE type;

   union {
      char *strVal;
      double value; 
   }; 
} TOKEN;

char *token_names[] = {"INVALID_TOKEN", "NUMBERTOKEN",  "IDENTTOKEN",  "ASSIGNMENT",   "SEMICOLON", "LPAREN",   "RPAREN",   "PLUS",   "MINUS",   "MULTIPLY",   "DIV",   "MOD",   "REPEAT",   "PRINT",   "END_OF_INPUT_TOKEN", }; 

// TOKEN *scanner();

#define BUF_SIZE 128
#define MAX_LINE_LENGTH 256