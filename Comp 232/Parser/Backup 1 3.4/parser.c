#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

TOKEN *scannerAdHoc();
TOKEN *currentToken;

TOKEN *scanner() {
  TOKEN *token = (TOKEN*) malloc(sizeof(TOKEN));
  token = scannerAdHoc();

  return token;
}

AST_NODE *program() {
  currentToken = malloc(sizeof(TOKEN));

  AST_NODE *node = malloc(sizeof(AST_NODE));
  node->type = PROGRAM;
  node->left_node = statement();

  if (node->left_node != NULL) {
    node->right_node = program();
  }

  return node;
}

AST_NODE *statement() {

  AST_NODE *node = malloc(sizeof(AST_NODE));
  node->type = STATEMENT;
  currentToken = scanner();

  if (currentToken->type == 2) {
    node->left_node = id(currentToken);
  }

  return NULL;
}

AST_NODE *assignStmt(TOKEN *currToken) {

  return NULL;
}

AST_NODE *repeatStmt(TOKEN *currToken) {

  return NULL;
}

AST_NODE *printStmt(TOKEN *currToken) {

  return NULL;
}

AST_NODE *expr(TOKEN *currToken) {

  return NULL;
}

AST_NODE *term(TOKEN *currToken) {

  return NULL;
}

AST_NODE *factor(TOKEN *currToken) {

  return NULL;
}

AST_NODE *id(TOKEN *currToken) {
printf("\nhey whats up");
  return NULL;
}

AST_NODE *number(TOKEN *currToken) {

  return NULL;
}

void error() {

}
