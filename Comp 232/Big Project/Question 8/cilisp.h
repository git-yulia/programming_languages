#ifndef __cilisp_h_
#define __cilisp_h_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

#include "cilisp.tab.h"

int yyparse(void);
int yylex(void);
void yyerror(char *);

typedef enum { NUM_TYPE, SYMBOL_TYPE, FUNC_TYPE, LET_STATEMENT_TYPE, LET_LIST_TYPE, LET_ELEM_TYPE, CONDITIONAL_TYPE } AST_NODE_TYPE;

typedef struct
{
    double value;
} NUMBER_AST_NODE;

typedef struct
{
  char *type;
  char *symbolVal;
} SYMBOL_AST_NODE;

typedef struct
{
   char *name;
   struct ast_node *op1;
   struct ast_node *op2;
} FUNCTION_AST_NODE;

typedef struct
{
  struct ast_node *let_list;
  struct ast_node *s_expr;
} LET_STATEMENT_AST_NODE;

typedef struct
{
  struct ast_node *let_elem;
  struct ast_node *let_list;
} LET_LIST_AST_NODE;

typedef struct
{
  struct ast_node *symbol;
  struct ast_node *s_expr;
} LET_ELEM_AST_NODE;

typedef struct
{
  struct ast_node *comparator;
  struct ast_node *ifCase;
  struct ast_node *elseCase;
} CONDITIONAL_AST_NODE;

typedef struct ast_node
{
   AST_NODE_TYPE type;
   union
   {
      NUMBER_AST_NODE number;
      SYMBOL_AST_NODE symbolNode;
      FUNCTION_AST_NODE function;
      CONDITIONAL_AST_NODE conditional;
      LET_STATEMENT_AST_NODE let_statement;
      LET_LIST_AST_NODE let_list;
      LET_ELEM_AST_NODE let_elem;
   } data;
} AST_NODE;

typedef struct node {
  char *type;
  char *symbol;
  struct ast_node *s_expr;
  struct node *next;
} LIST_NODE;

AST_NODE *number(double value);
AST_NODE *symbol(char *type, char *symbolValue);
AST_NODE *function(char *funcName, AST_NODE *op1, AST_NODE *op2);
AST_NODE *let_elem(char *type, char *symbolValue, AST_NODE *s_expr);
AST_NODE *let_list(AST_NODE *let_elem, AST_NODE *let_list);
AST_NODE *let_statement(AST_NODE *let_list, AST_NODE *s_expr);
AST_NODE *conditional(AST_NODE *comparator, AST_NODE *ifCase, AST_NODE *elseCase);
LIST_NODE *listEval(LIST_NODE *aList, AST_NODE *let_list);
LIST_NODE *symbolFinder(LIST_NODE *aList, AST_NODE *p);
void freeNode(AST_NODE *p);

double eval(LIST_NODE *a_list, AST_NODE *p);

#endif
