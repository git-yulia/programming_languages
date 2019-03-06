#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

char *token_names[] = {"INVALID_TOKEN", "NUMBERTOKEN",  "IDENTTOKEN",  "ASSIGNMENT",   "SEMICOLON", "LPAREN",   "RPAREN",   "PLUS",   "MINUS",   "MULTIPLY",   "DIV",   "MOD",   "REPEAT",   "PRINT",   "END_OF_INPUT_TOKEN"};

AST_NODE *print_program(AST_NODE *currentNode);

int main(void) {
  AST_NODE *currentNode = program();
  print_program(currentNode);

  /**
  AST_NODE *fullProgram = program();
  print_program(fullProgram);
  */
}

AST_NODE *print_program(AST_NODE *currentNode) {
  if (currentNode != NULL) {
    printf("\nCurrent node is %s", token_names[currentNode->type]);
    print_program(currentNode->left_node);
  }



  /**
      Check if the current node is empty / null.
      Display the data part of the root (or current node).
      Traverse the left subtree by recursively calling the pre-order function.
      Traverse the right subtree by recursively calling the pre-order function.
  */
  return currentNode;
}
