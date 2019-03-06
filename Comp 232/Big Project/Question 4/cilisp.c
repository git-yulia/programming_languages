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
   yyerror("invalid function"); // paranoic -- should never happen
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

// create a node for a function
AST_NODE *function(char *funcName, AST_NODE *op1, AST_NODE *op2)
{
    AST_NODE *p;
    size_t nodeSize;

    // allocate space for the fixed sie and the variable part (union)
    nodeSize = sizeof(AST_NODE) + sizeof(FUNCTION_AST_NODE);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    p->type = FUNC_TYPE;
    p->data.function.name = funcName;
    p->data.function.op1 = op1;
    p->data.function.op2 = op2;

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
    case 16: return 0; 
  }
}

double eval(AST_NODE *p)
{
  // if p is null, goodbye 
  if (p == NULL) {
    return 0; 
  }

  // BASE CASE: if p is a number, return double value 
  else if (p->type == NUM_TYPE) {
    return p->data.number.value; 
  }

  // if p is a function, calculate the result using recursive calls. 
  else {
    return (calc(p->data.function.name, eval(p->data.function.op1), eval(p->data.function.op2)));
  }

}  

