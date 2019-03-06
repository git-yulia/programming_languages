#include "cilisp.h"
#include <math.h> 

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

int resolveFunc(char *func)
{
   char *funcs[] = { "neg", "abs", "exp", "sqrt", "add", "sub", "mult", "div", "remainder", "log", "pow", "max", "min", ""};
   
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
    case 9: return (log10(op1)); 
    case 10: return (pow(op1, op2)); 
    case 11: return MAX(op1, op2); 
    case 12: return MIN(op1, op2); 
    case 13: return NULL; 
  }
}  
