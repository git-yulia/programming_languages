%option noyywrap

%{
   #include "l7t1.h"
   int number_of_terms = 0;
   int sum_of_terms = 0;
   int totalDollars = 0;
%}

/* aliases */
digit [0-9]
number {digit}

/* matching rules */
%%

"bank" {/* match action */ return BANK;}
"dollar" {return DOLLAR;}

\${number} {totalDollars += strtod(yytext+1, NULL);}

%%
