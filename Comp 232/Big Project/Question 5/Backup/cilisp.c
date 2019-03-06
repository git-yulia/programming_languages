/**
Name : Yulia Maliauka
BIG PROJECT Lab, Question 5
Professor Bieszczad, Professor Smith
March 27, 2017
*/

#include "cilisp.h"

#define MAX(op1, op2) ((op1) > (op2) ? op1 : op2)
#define MIN(op1, op2) ((op1) < (op2) ? op1 : op2)

int main(void)
{
    yyparse();
    return 0;
}

void yyerror(char *s)
{
    fprintf(stderr, "%s\n", s);
}

// find out which function it is
int resolveFunc(char *func)
{
   char *funcs[] = { "neg", "abs", "exp", "sqrt", "add", "sub", "mult", "div", "remainder", "log", "pow", "max", "min", "exp2", "cbrt", "hypot", ""};

   int i = 0;
   while (funcs[i][0] !='\0')
   {
      if (!strcmp(funcs[i], func))
         return i;

      i++;
   }
   yyerror("invalid function"); // paranoiac -- should never happen
   return -1;
}

// create a node for a number
AST_NODE *number(double value)
{
    AST_NODE *p;
    size_t nodeSize;

    // allocate space for the fixed sie and the variable part (union)
    nodeSize = sizeof(AST_NODE) + sizeof(NUMBER_AST_NODE);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    p->type = NUM_TYPE;
    p->data.number.value = value;

    return p;
}

AST_NODE *symbol(char *symbolValue) {
  AST_NODE *p;
  size_t nodeSize;

  // allocate space for the fixed size and the variable part (union)
  nodeSize = sizeof(AST_NODE) + sizeof(FUNCTION_AST_NODE);
  if ((p = malloc(nodeSize)) == NULL)
      yyerror("out of memory");

  p->type = SYMBOL_TYPE;
  p->data.symbolNode.symbolVal = symbolValue;

  return p;
}

// create a node for a function
AST_NODE *function(char *funcName, AST_NODE *op1, AST_NODE *op2)
{
    AST_NODE *p;
    size_t nodeSize;

    // allocate space for the fixed size and the variable part (union)
    nodeSize = sizeof(AST_NODE) + sizeof(FUNCTION_AST_NODE);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    p->type = FUNC_TYPE;
    p->data.function.name = funcName;
    p->data.function.op1 = op1;
    p->data.function.op2 = op2;

    return p;
}

AST_NODE *let_statement(AST_NODE *let_list, AST_NODE *s_expr) {
    AST_NODE *p;
    size_t nodeSize;

    // allocate space for the fixed size and the variable part (union)
    nodeSize = sizeof(AST_NODE) + sizeof(FUNCTION_AST_NODE);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    p->type = LET_STATEMENT_TYPE;
    p->data.let_statement.let_list = let_list;
    p->data.let_statement.s_expr = s_expr;

    return p;
}

AST_NODE *let_list(AST_NODE *let_elem, AST_NODE *let_list) {
    AST_NODE *p;
    size_t nodeSize;

    // allocate space for the fixed size and the variable part (union)
    nodeSize = sizeof(AST_NODE) + sizeof(FUNCTION_AST_NODE);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    p->type = LET_LIST_TYPE;
    p->data.let_list.let_elem = let_elem;
    p->data.let_list.let_list = let_list;

    return p;
}

AST_NODE *let_elem(char *symbolValue, AST_NODE *s_expr) {
    AST_NODE *p;
    size_t nodeSize;

    // allocate space for the fixed size and the variable part (union)
    nodeSize = sizeof(AST_NODE) + sizeof(FUNCTION_AST_NODE);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

     p->type = LET_ELEM_TYPE;
     p->data.let_elem.symbol = symbol(symbolValue);
     p->data.let_elem.s_expr = s_expr;

    return p;
}

// free a node
void freeNode(AST_NODE *p)
{
    if (!p)
       return;

    if (p->type == FUNC_TYPE)
    {
        free(p->data.function.name);
        freeNode(p->data.function.op1);
        freeNode(p->data.function.op2);
    }

    free (p);
}

double calc(char *func, double op1, double op2)
{
  int operation = resolveFunc(func);

  switch (operation) {
    case 0: return (op1 * -1.0);
    case 1: return fabs(op1);
    case 2: return exp(op1);
    case 3: return sqrt(op1);
    case 4: return (op1 + op2);
    case 5: return (op1 - op2);
    case 6: return (op1 * op2);
    case 7: return (op1 / op2);
    case 8: return ((int)op1 % (int)op2);
    case 9: return ((op1 == 10) ? (log10(op2)) : (log(op2)));
    case 10: return (pow(op1, op2));
    case 11: return MAX(op1, op2);
    case 12: return MIN(op1, op2);
    case 13: return exp2(op1);
    case 14: return cbrt(op1);
    case 15: return hypot(op1, op2);
    default: return 0;
  }
}

LIST_NODE *listEval(AST_NODE *let_list) {
  LIST_NODE *root;
  size_t nodeSize;

  // allocate space for the fixed size and the variable part (union)
  nodeSize = sizeof(AST_NODE) + sizeof(FUNCTION_AST_NODE);
  if ((root = malloc(nodeSize)) == NULL)
      yyerror("out of memory");

  // Create and set root node
  root->symbol = let_list->data.let_list.let_elem->data.let_elem.symbol->data.symbolNode.symbolVal;
  root->s_expr = NULL;

  printf("\nCreated root node of name %s", let_list->data.let_list.let_elem->data.let_elem.symbol->data.symbolNode.symbolVal);

  while (let_list->data.let_list.let_list != NULL) {
    printf("\nAnd another one.");
    let_list = let_list->data.let_list.let_list; // Branch to the right node
  }

  printf("\nCreated root node of name %s", root->symbol);

  return root;
}

double eval(LIST_NODE *aList, AST_NODE *p)
{
  // if p is null, goodbye
  if (p == NULL) {
    return 0;
  }

  // BASE CASE: if p is a number
  else if (p->type == NUM_TYPE) {
    return p->data.number.value;
  }

  // REPLACE symbol type with number value, and return it just like a number
  else if (p->type == SYMBOL_TYPE) {
      printf("\n[Compiler found symbol %s.]", p->data.symbolNode.symbolVal);

      // traverse the a-list looking for the symbol or report an error and exit(1)
      return 0;
  }

  else if (p->type == LET_STATEMENT_TYPE) {
      // Create the associative list first, using the let_list nodes
      listEval(p->data.let_statement.let_list);

      // Evaluate the functions that need the aList by returning: eval(list, p->s_expr)
      return 0;
  }

  // if p is a function, or s_expr, calculate the result using recursive calls.
  else {
    printf("\n[Compiler call: else. p->type is %s]", p->data.function.name);
    return (calc(p->data.function.name, eval(aList, p->data.function.op1), eval(aList, p->data.function.op2)));
  }
}









//
