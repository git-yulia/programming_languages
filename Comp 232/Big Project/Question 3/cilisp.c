#include "cilisp.h"

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

void translate(AST_NODE *p)
{
  // If p is null, you have reached the end of a branch. 
  if (p == NULL) {
    return; 
  }

  // If P is a number, you have reached a leaf. Print the leaf. 
  else if (p->type == NUM_TYPE) {
    printf("%f", p->data.number.value);
  }
  // OR you have reached another function or operation. 
  else { 
    // Acquire the value of the function type as an integer. 
    int funcType = resolveFunc(p->data.function.name); 

    // If function is add, sub, mult, or div: 
    if (funcType >= 4 && funcType <= 7) {
      // Print out the first operand 
      printf("(");
      translate(p->data.function.op1); 
      
      // Print out the operator - INFIX NOTATION FOR ARITHMETIC 
      switch (funcType) {
        case 4: printf(" + "); break; 
        case 5: printf(" - "); break;
        case 6: printf(" * "); break; 
        case 7: printf(" / "); break; 
      }

      // Print out the second operand 
      translate(p->data.function.op2);
      printf(")");
    }

   else {
      // PREFIX - print out the operator first, then the operands. 
      printf("%s(", p->data.function.name);
      translate(p->data.function.op1);
      printf(" ");
      if (p->data.function.op2 != NULL) printf(", "); 
      translate(p->data.function.op2);
      printf(")");
   }

  }

}  

