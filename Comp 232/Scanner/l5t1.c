/**
Name : Yulia Maliauka
Comp 232 - Programming Languages
Lab 5 Task 1 - Nested Cases
Professor Scrivnor/ Professor Bieszczad
February 22, 2017
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.c"

// DECLARATIONS
void printToken(TOKEN *t);

int main() {
  TOKEN *t;

  // Until the EOF, run scannerEC and print each token. 
  while ((t = scannerEC()) != NULL) {
    printToken(t);
  }

return 0;
}

void printToken(TOKEN *t) {
  // If our token only has a TYPE - only print the type.
  if (token_names[t->type] == "LPAREN" || token_names[t->type] == "RPAREN" || token_names[t->type] == "SEMICOLON" || token_names[t->type] == "MOD" || token_names[t->type] == "MULT" || token_names[t->type] == "MULT" || token_names[t->type] == "MINUS"|| token_names[t->type] == "PLUS" || token_names[t->type] == "MULT" || token_names[t->type] == "DIV") {
    printf("{<%s>}, ", token_names[t->type]);
  }
  else if (token_names[t->type] == "NUMBERTOKEN") {
    printf("{<%s>, %.1lf}, ", token_names[t->type], t->value);
  }
  // If our token has a type and a value - print both!
  else {
    printf("{<%s>, %s}, ", token_names[t->type], t->strVal);
  }
}