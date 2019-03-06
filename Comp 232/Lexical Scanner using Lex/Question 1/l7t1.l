%option noyywrap
%option caseless

%{
   #include "l7t1.h"
   float sum_of_dollars;
   float sum_of_numbers;
%}

/* aliases */
digit [0-9]
number {digit}+[.]*{digit}*
other [A-Za-z0-9]+

/* matching rules */
%%

"bank"|"banks" {frequencies[BANK]++; return BANK;}
"dollar"|"dollars" {frequencies[DOLLAR]++; return DOLLAR;}
"finance"|"finances" {frequencies[FINANCE]++; return FINANCE;}
"budget"|"budgets" {frequencies[BUDGET]++; return BUDGET;}
"fund"|"funding"|"funds" {frequencies[FUND]++; return FUND;}
"stock"|"stocks" {frequencies[STOCK]++; return STOCK;}
"bond"|"bonds" {frequencies[BOND]++; return BOND;}
"invest"|"investing" {frequencies[INVEST]++; return INVEST;}

{number} {sum_of_numbers += strtod(yytext, NULL); return NUMBER;}
\${number} {sum_of_dollars += strtod(yytext+1, NULL); return MONEYS;}
{other} {return OTHER;}

%%
