/**
Name: Yulia Maliauka
Date: March 3, 2017
Lab 6 Task 1 (out of 1)
Professor AJ Bieszczad, Professor Scrivnor
*/

// main.c : this file runs the parser, and prints the tree

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

char *node_types[] = {"1", "IDENTIFIER", "NUMBER", "EXPR", "TERM",
 "ASSIGN_STMT", "REPEAT_STMT", "PRINT_STMT", "FACTOR", "ADDOP", "MULTOP",
 "PROGRAM", "STATEMENT"};

AST_NODE *print_program(AST_NODE *currentNode);

int main(void) {
  AST_NODE *fullProgram = program();

  printf("\n\nSTARTING at root node program()");
  print_program(fullProgram);

  printf("\n\nParse successful.\n\n");
}

AST_NODE *print_program(AST_NODE *currentNode) {
  if (currentNode->left_node != NULL) {
    printf("\n<-Going left! Current node is %s", node_types[currentNode->left_node->type]);

    // Reporting data of node, if any.
    if (currentNode->left_node->type == NUMBER) {
      printf(", data: %.1lf", currentNode->left_node->data.number);
    }
    else if (currentNode->left_node->type == IDENTIFIER) {
      printf(", data: '%s'", currentNode->left_node->data.identifier);
    }

    print_program(currentNode->left_node);
  }
  if (currentNode->right_node != NULL) {
    printf("\n->Going right! (Back to root node %s.) Current node is %s", node_types[currentNode->type], node_types[currentNode->right_node->type]);
    print_program(currentNode->right_node);
  }

  return currentNode;
}
