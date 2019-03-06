/**
Name : Yulia Maliauka
Comp 232 - Programming Languages
Professor Scrivnor/Professor Bieszczad
February 22, 2017
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include "scanner.h"

enum {false, true}; // for booleans

int isKeyword(char *in) {
  return (!strcmp("print", in) || strcmp("repeat", in));
}

char readNextChar() {
  return getc(stdin);
}


TOKEN *scannerEC(void) { 
  // slide 20 of the lecture notes
  int state = 1;

  TOKEN *t = malloc(sizeof(TOKEN));
  char ch;
  // char *strValChar = malloc(sizeof(TOKEN)); 
  char *temp = malloc(sizeof(TOKEN));
  char *string = malloc(sizeof(TOKEN));

  // INITIALIZING ERROR VARIABLES
  t->type = INVALID_TOKEN; 
  t->strVal = "Invalid Token"; 
  t->value = 0; 
  // end of initialization

  while (state > 0) { 
    if (state == 1 && (ch = getc(stdin)) == EOF) return NULL; // If input is ctrl+D, end process. 

    // This method captures whitespace, puts it in a jar, and floats it away into the abyss. 
    while (ch == ' ' || ch == '\n') {
      ch = getc(stdin); 
    }
    // End of whitespace catcher. 

    //  printf("\nState is %d, ch is %c\n", state, ch);

    switch (state) {
      // CASE 1: Base case, or "Start" node.
      case 1 :
        switch (ch) {
          case '/' : state = 2; break; // Could be comment, block comment, or multop. 
          case '(' : t->type = LPAREN; return t; 
          case ')' : t->type = RPAREN; return t;
          case '+' : t->type = PLUS; return t; 
          case '-' : t->type = MINUS; return t; 
          case '=' : t->type = ASSIGNMENT; return t; 
          case '*' : state = 3; break; // Could be multop, block comment. 
          case '%' : t->type = MOD; return t;  
          case ';' : t->type = SEMICOLON; return t;
          case '0'...'9' : t->type = NUMBERTOKEN; state = 4; break; 
          case 'a'...'z' : t->type = IDENTTOKEN; t-> value = ch; return t;// state = 5; break; 
          default: return t; // Invalid token 
        } break; 
      // CASE 2: ch is '/'
      case 2 : 
        switch (ch = readNextChar()) { 
          case '/': printf("\ncomment\n"); state = 1; break; // This is a comment; do nothing. 
          case '*': printf("\ncomment\n"); state = 1; break; // This is a comment; do nothing. 
          case '0'...'9': ungetc(ch, stdin); t->type = DIV; return t; 
        } break; 
      // CASE 3 : ch is '*'
      case 3 :
        switch (ch = readNextChar()) {
          case '/': printf("\ncomment\n"); state = 1; break; // This is a comment, do nothing. 
          case '0'...'9': ungetc(ch, stdin); t->type = MULT; return t; 
        } break; 
      // CASE 4: ch is a number
      case 4 : 
        ungetc(ch, stdin);
        int numberOfPlaces = 0; 
        int digits[20]; 
        int val = 0; int tensPower = 1; 
        while ((ch = readNextChar()) < 58 && ch > 47) {
          digits[numberOfPlaces] = (int)(ch - '0'); 
          numberOfPlaces++;
        }
        ungetc(ch, stdin); // put the non-digit character back in the stream. 
        for (int i = numberOfPlaces - 1; i >= 0; i--) {
          val += digits[i] * tensPower; 
          tensPower *= 10; 
        }
        t->value = val; 
        state = 1; 
        return t;
      break; 
      // CASE 5: ch is alphanumeric (an ID)
      /**
      case 5 : 
        ungetc(ch, stdin); 
        int i = 0; 
        while (isalnum(ch = readNextChar()) == 1) {
          string[i] = ch;   
          printf("string[i]=%c", string[i]);
          i++; 
        }
        ungetc(ch, stdin); // put the non-digit character back in the stream. 
        //for (int i = numberOfPlaces - 1; i >= 0; i--) {

        //}
        // strcat(string, "what");

        t->strVal = "hello"; 
        state = 1; 
        return t;
      break; 
      */ 
       
    }
  }

  return t;
}