/**
Name: Yulia Maliauka
Date: March 3, 2017
Lab 6 Task 1 (out of 1)
Professor AJ Bieszczad, Professor Scrivnor
*/

// parser.c : this file parses the code and creates an AST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

TOKEN *scannerAdHoc();
TOKEN *currentToken;

/**
// root of all programs
*/
AST_NODE *program() {
  currentToken = malloc(sizeof(TOKEN));
  AST_NODE *node = malloc(sizeof(AST_NODE));

  // Create the left tree.
  node->type = PROGRAM;
  node->left_node = statement();

  // If there are still more tokens to parse, create a right tree.
  if ((currentToken = scannerAdHoc()) != NULL) {
    ungetToken(&currentToken);
    node->right_node = program();
  }

  return node;
}

/**
// statements include assignStmt, printStmt, repeatStmt
*/
AST_NODE *statement() {
  AST_NODE *node = malloc(sizeof(AST_NODE));
  node->type = STATEMENT;

  if ((currentToken = scannerAdHoc()) == NULL) error();
  // If the token is an identifier, run <assignStmt>
  if (currentToken->type == IDENTTOKEN) {
    node->left_node = assignStmt(currentToken);
  }
  // If the token is <repeat>
  else if (currentToken->type == REPEAT) {
    node->left_node = repeatStmt(currentToken);
  }
  // If the token is <print>
  else if (currentToken->type == PRINT) {
    node->left_node = printStmt(currentToken);
  }
  else {
    error(); // error if the first token is not a statement
  }

  return node;
}

/**
// example: a = 5; error if no semicolon or equals sign
*/
AST_NODE *assignStmt(TOKEN *currToken) {
  AST_NODE *node = malloc(sizeof(AST_NODE));
  node->type = ASSIGN_STMT;

  node->left_node = id(currentToken);

  expect(ASSIGNMENT);

  if ((currentToken = scannerAdHoc()) == NULL) error();
  node->right_node = expr(currentToken);

  printf("\nfuncProg : funcAssign: ID(%s) to INT(%.1lf)", node->left_node->data.identifier, node->right_node->left_node->left_node->left_node->data.number);

  expect(SEMICOLON);

  return node;
}

/**
// example: repeat(3) a + b;
*/
AST_NODE *repeatStmt(TOKEN *currToken) {
  AST_NODE *node = malloc(sizeof(AST_NODE));
  node->type = REPEAT_STMT;


  expect (LPAREN);
  if ((currentToken = scannerAdHoc()) == NULL) error();
  node->left_node = expr(currentToken);
  expect(RPAREN);
  node->right_node = statement();

  return node;
}

/**
// example: print Hello;
*/
AST_NODE *printStmt(TOKEN *currToken) {
  AST_NODE *node = malloc(sizeof(AST_NODE));
  node->type = PRINT_STMT;
  if ((currentToken = scannerAdHoc()) == NULL) error();

  node->left_node = expr(currentToken);
  expect(SEMICOLON); // before branch because it's our next token

  return node;
}

/**
// example: 7
*/
AST_NODE *expr(TOKEN *currToken) {
  AST_NODE *node = malloc(sizeof(AST_NODE));
  node->type = EXPR;

  node->left_node = term(currentToken);

  if ((currentToken = scannerAdHoc()) == NULL) error();

  if (currentToken->type == PLUS || currentToken->type == MINUS) {
    if ((currentToken = scannerAdHoc()) == NULL) error();
    node->right_node = expr(currentToken);
  }
  else {
    ungetToken(&currentToken);
  }

  return node;
}

/**
// example: 7 * b
*/
AST_NODE *term(TOKEN *currToken) {
  AST_NODE *node = malloc(sizeof(AST_NODE));
  node->type = TERM;

  node->left_node = factor(currentToken);

  if ((currentToken = scannerAdHoc()) == NULL) error();
  if (currentToken->type == MULT || currentToken->type == DIV) {
    if ((currentToken = scannerAdHoc()) == NULL) error();
    node->right_node = term(currentToken);
  }
  else {
    ungetToken(&currentToken);
  }

  return node;
}

/**
// example: -9
*/
AST_NODE *factor(TOKEN *currToken) {
  AST_NODE *node = malloc(sizeof(AST_NODE));
  node->type = FACTOR;

  if (currentToken->type == IDENTTOKEN) {
    node->left_node = id(currentToken);
  }
  else if (currentToken->type == NUMBERTOKEN) {
    node->left_node = number(currentToken);
  }
  else if (currentToken->type = LPAREN) {
    node->left_node = expr(currentToken = scannerAdHoc());
    expect(RPAREN);
  }

  return node;
}

/**
// example: Hello
*/
AST_NODE *id(TOKEN *currToken) {
  AST_NODE *node = malloc(sizeof(AST_NODE));
  node->type = IDENTIFIER;

  // Recording the data inside the current token
  strcpy(node->data.identifier, currentToken->strVal);

  return node;
}

/**
// example: 12
*/
AST_NODE *number(TOKEN *currToken) {
  AST_NODE *node = malloc(sizeof(AST_NODE));
  node->type = NUMBER;

  // Recording the data inside the current token
  sscanf(currentToken->strVal, "%lf", &node->data.number);

  return node;
}

/**
// reports an error and closes the program if code does not follow grammar.
*/
void error() {
  printf("\nParser error. Returned (1)\n");
  exit(1);
}

/**
// reports an error if necessary. calls error()
*/
void expect(int tokenType) {
  currentToken = scannerAdHoc();
  if ((currentToken == NULL) || (tokenType != currentToken->type)) error();
}
