/**
Name : Yulia Maliauka
BIG PROJECT Lab, Question 10: Final Boss
Professor Bieszczad, Professor Smith
April 12, 2017
*/

#include "cilisp.h"

#define MAX(op1, op2) ((op1) > (op2) ? op1 : op2)
#define MIN(op1, op2) ((op1) < (op2) ? op1 : op2)
enum {false, true};

int main(void)
{
    srand(time(NULL));
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
   char *funcs[] = { "neg", "abs", "exp", "sqrt", "add", "sub", "mult", "div", "remainder", "log", "pow", "max", "min", "exp2", "cbrt", "hypot", "print", "equal", "smaller", "larger", "rand", "read", ""};

   int i = 0;
   while (funcs[i][0] !='\0')
   {
      if (!strcmp(funcs[i], func))
         return i;

      i++;
   }
   yyerror("invalid function");
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

AST_NODE *symbol(char *type, char *symbolValue) {
  AST_NODE *p;
  size_t nodeSize;

  // allocate space for the fixed size and the variable part (union)
  nodeSize = sizeof(AST_NODE) + sizeof(SYMBOL_AST_NODE);
  if ((p = malloc(nodeSize)) == NULL)
      yyerror("out of memory");

  p->type = SYMBOL_TYPE;
  p->data.symbolNode.type = type;
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
    nodeSize = sizeof(AST_NODE) + sizeof(LET_STATEMENT_AST_NODE);
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
    nodeSize = sizeof(AST_NODE) + sizeof(LET_LIST_AST_NODE);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    p->type = LET_LIST_TYPE;
    p->data.let_list.let_elem = let_elem;
    p->data.let_list.let_list = let_list;

    return p;
}

/*
      Note:
      AST_NODE *let_elem() takes in char *type as a parameter, but does not add
      this value to the abstract syntax tree.
**/
AST_NODE *let_elem(char *type, char *symbolValue, AST_NODE *s_expr) {
    AST_NODE *p;
    size_t nodeSize;

    // allocate space for the fixed size and the variable part (union)
    nodeSize = sizeof(AST_NODE) + sizeof(LET_ELEM_AST_NODE);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

     p->type = LET_ELEM_TYPE;
     p->data.let_elem.symbol = symbol(type, symbolValue);
     p->data.let_elem.s_expr = s_expr;

    return p;
}

AST_NODE *s_expr_list(AST_NODE *s_expr_list, AST_NODE *s_expr) {
  AST_NODE *p;
  size_t nodeSize;

  // allocate space for the fixed size and the variable part (union)
  nodeSize = sizeof(AST_NODE) + sizeof(ARG_LIST_NODE);
  if ((p = malloc(nodeSize)) == NULL)
      yyerror("out of memory");

   p->type = ARG_LIST_TYPE;
   p->data.s_expr_list.s_expr_list = s_expr_list;
   p->data.s_expr_list.s_expr = s_expr;

  return p;
}

AST_NODE *arg_list(AST_NODE *symbol, AST_NODE *arg_list) {
  AST_NODE *p;
  size_t nodeSize;

  // allocate space for the fixed size and the variable part (union)
  nodeSize = sizeof(AST_NODE) + sizeof(S_EXPR_LIST_TYPE);
  if ((p = malloc(nodeSize)) == NULL)
      yyerror("out of memory");

   p->type = S_EXPR_LIST_TYPE;
   p->data.s_expr_list.s_expr_list = s_expr_list;
   p->data.s_expr_list.s_expr = s_expr;

  return p;
}

AST_NODE function_definition(AST_NODE *symbol, AST_NODE *arg_list, AST_NODE *s_expr) {
  AST_NODE *p;
  size_t nodeSize;

  // allocate space for the fixed size and the variable part (union)
  nodeSize = sizeof(AST_NODE) + sizeof(FUNCTION_DEFINITION_NODE);
  if ((p = malloc(nodeSize)) == NULL)
      yyerror("out of memory");

   p->type = FUNCTION_DEFINITION_TYPE;
   p->data.function_definition.symbol = symbol;
   p->data.function.definition.arg_list = arg_list;
   p->data.function_definition.s_expr = s_expr;

  return p;
}

AST_NODE *conditional(AST_NODE *comparator, AST_NODE *ifCase, AST_NODE *elseCase) {
  AST_NODE *p;
  size_t nodeSize;

  // allocate space for the fixed size and the variable part (union)
  nodeSize = sizeof(AST_NODE) + sizeof(CONDITIONAL_AST_NODE);
  if ((p = malloc(nodeSize)) == NULL)
      yyerror("out of memory");

  p->type = CONDITIONAL_TYPE;
  p->data.conditional.comparator = comparator;
  p->data.conditional.ifCase = ifCase;
  p->data.conditional.elseCase = elseCase;

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
  double returnVal;

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
    case 17: return ((op1 == op2) ? 1 : 0);
    case 18: return ((op1 < op2) ? 1 : 0);
    case 19: return ((op1 > op2) ? 1 : 0);
    case 20: return (rand() % 100);
    default: return 0;
  }
}

// PLEASE do not use symbolFinder to traverse a NULL aList. Thanks.
/**
  returns NULL if symbol was not found in list
  else returns pointer to LIST_NODE where item was found
*/
LIST_NODE *symbolFinder(LIST_NODE *aList, AST_NODE *p) {
    size_t nodeSize = sizeof(AST_NODE);
    LIST_NODE *found = malloc(nodeSize);
    found = NULL;

    // STEP 1: Cycle through the aList, looking for the symbol
    while ((strcmp(aList->symbol, p->data.symbolNode.symbolVal) != 0) && (aList->next != NULL)) {
        aList = aList->next;
    }

    // STEP 2: If the symbol was found, return true
    if (strcmp(aList->symbol, p->data.symbolNode.symbolVal) == 0) {
      found = aList;
    }

    return found;
}

LIST_NODE *listEval(LIST_NODE *aList, AST_NODE *let_list) {
  LIST_NODE *root;
  size_t nodeSize;
  int redeclaration = false;

  LIST_NODE *previousNode = malloc(nodeSize);

  // allocate space for the fixed size and the variable part (union)
  nodeSize = sizeof(AST_NODE) + sizeof(FUNCTION_AST_NODE);
  if ((root = malloc(nodeSize)) == NULL)
      yyerror("out of memory");

  // If the aList of this scope is not NULL, check if the symbol is already in the aList of this scope
  // Report a redefinition warning if so, and either:
  // 1. set the type to that of the original if the new type was left NULL
  // 2. cast as a new type, providing a warning or error if incompatible
  if ((aList != NULL) && (symbolFinder(aList, let_list->data.let_list.let_elem->data.let_elem.symbol) != NULL)) {
    redeclaration = true;
  }

  // Create the root node using the values in the left branch.
  // If the new node is a redeclaration, set its type to the one previously initialized
  if (redeclaration == true) {
    // Find the symbol in the aList
    while (strcmp(aList->symbol, let_list->data.let_list.let_elem->data.let_elem.symbol->data.symbolNode.symbolVal) != 0) aList = aList->next;

    if (let_list->data.let_list.let_elem->data.let_elem.symbol->data.symbolNode.type != NULL) {
      // If you are casting a symbol, display a warning.
      printf("\nWARNING: incompatible type assignment for variable <%s>", let_list->data.let_list.let_elem->data.let_elem.symbol->data.symbolNode.symbolVal);
      root->type = let_list->data.let_list.let_elem->data.let_elem.symbol->data.symbolNode.type;
    }
    else {
      root->type = aList->type;
    }
  }
  else {
    root->type = let_list->data.let_list.let_elem->data.let_elem.symbol->data.symbolNode.type;
  }
  // Set symbol
  root->symbol = let_list->data.let_list.let_elem->data.let_elem.symbol->data.symbolNode.symbolVal;
  // Set s_expr
  root->s_expr = let_list->data.let_list.let_elem->data.let_elem.s_expr;
  // Set next to NULL
  root->next = NULL;

  previousNode = root;

  while (let_list->data.let_list.let_list != NULL) {
    // Branch to the right node of the AST
    let_list = let_list->data.let_list.let_list;

    // Are we redeclaring a symbol?
    if ((aList != NULL) && (symbolFinder(aList, let_list->data.let_list.let_elem->data.let_elem.symbol) != NULL)) {
      redeclaration = true;
    }
    else {
      redeclaration = false;
    }


    // STEP 1: Create a new node, and fill in its values.
    LIST_NODE *currentNode = malloc(nodeSize);

    if (redeclaration == true) {
      // Find the symbol in the aList
      while (strcmp(aList->symbol, let_list->data.let_list.let_elem->data.let_elem.symbol->data.symbolNode.symbolVal) != 0) aList = aList->next;

      if (let_list->data.let_list.let_elem->data.let_elem.symbol->data.symbolNode.type != NULL) {
        // If you are casting a symbol, display a warning.
        printf("\nWARNING: incompatible type assignment for variable <%s>", let_list->data.let_list.let_elem->data.let_elem.symbol->data.symbolNode.symbolVal);
        currentNode->type = let_list->data.let_list.let_elem->data.let_elem.symbol->data.symbolNode.type;
      }
      else {
        currentNode->type = aList->type;
      }
    }
    else {
      currentNode->type = let_list->data.let_list.let_elem->data.let_elem.symbol->data.symbolNode.type;
    }

    //currentNode->type = let_list->data.let_list.let_elem->data.let_elem.symbol->data.symbolNode.type;
    currentNode->symbol = let_list->data.let_list.let_elem->data.let_elem.symbol->data.symbolNode.symbolVal;
    currentNode->s_expr = let_list->data.let_list.let_elem->data.let_elem.s_expr;

    // STEP 2: Point node.next -> this new node we just created.
    previousNode->next = currentNode;

    // STEP 3: Set the node to node.next for when we loop again
    previousNode = currentNode;
  }

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

  // CONDITIONALS
  else if (p->type == CONDITIONAL_TYPE) {
    if (eval(aList, p->data.conditional.comparator) != 0) return eval(aList, p->data.conditional.ifCase);
    return eval(aList, p->data.conditional.elseCase);
  }

  // PRINT function
  else if (p->type == FUNC_TYPE && strcmp(p->data.function.name, "print") == 0) {
    printf("\n%.2lf", eval(aList, p->data.function.op1));
    return 0;
  }

  // READ function
  else if (p->type == FUNC_TYPE && strcmp(p->data.function.name, "read") == 0) {
      printf("\n>>");
      char ret[11];
      fgets(ret, 10, stdin);
      //puts(ret);
      double returnVal = strtod(ret, NULL);
      return returnVal;
  }

  // REPLACE symbol type with number value, and return it just like a number
  else if (p->type == SYMBOL_TYPE) {
      aList = symbolFinder(aList, p);

      // If a symbol is not defined correctly, report an error.
      if ((aList == NULL) || (aList->type == NULL)) {
        printf("\nERROR: Use of undeclared symbol <%s>\n", p->data.symbolNode.symbolVal);
        exit(1);
      }

      // Cast as either an int or real
      if (strcmp(aList->type, "int") == 0) return (int)(eval(aList, aList->s_expr));
      else return (eval(aList, aList->s_expr));
  }

  else if (p->type == LET_STATEMENT_TYPE) {
      return eval((listEval(aList, p->data.let_statement.let_list)),(p->data.let_statement.s_expr));
  }

  // if p is a function, or s_expr, calculate the result using recursive calls.
  else {
    return (calc(p->data.function.name, eval(aList, p->data.function.op1), eval(aList, p->data.function.op2)));
  }
}









//
