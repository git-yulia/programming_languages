%option noyywrap

%{
    #include "cilisp.h"
%}

digit [0-9]
number -?{digit}+(\.{digit}+)?
type "int"|"real"
func "neg"|"abs"|"exp"|"sqrt"|"add"|"sub"|"mult"|"div"|"remainder"|"log"|"pow"|"max"|"min"|"exp2"|"cbrt"|"hypot"|"print"|"equal"|"smaller"|"larger"|"rand"|"read"
letter [a-zA-Z]
symbol {letter}+

%%

{number}    {
                yylval.dval = strtod(yytext, NULL);
                return NUMBER;
            }

"quit"      { return QUIT; }

"let"       { return LET; }

"cond"      { return COND; }

"'"         { return APOSTROPHE; }

{type}      {
                yylval.sval = (char *) malloc(strlen(yytext)*sizeof(char));
                strcpy(yylval.sval, yytext);
                return TYPE;
            }

{func}      {
                yylval.sval = (char *) malloc(strlen(yytext)*sizeof(char));
                strcpy(yylval.sval, yytext);
                return FUNC;
            }

{symbol}    {
                yylval.sval = (char *) malloc(strlen(yytext)*sizeof(char));
                strcpy(yylval.sval, yytext);
                return SYMBOL;
            }

"("         {
                return LPAREN;
            }

")"         {
                return RPAREN;
            }

"\n"        {
                return EOL;
            }

[ \t]       ; /* skip whitespace */

.

%%
