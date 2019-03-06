/*

s-expressions calculator

program ::= program s-expr

s-expr ::= number | ( func s-expr ) | ( func s-expr s-expr )

number ::= [ + | - ] digit+ [ . digit+ ]

digit ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9

*/

%{
#include "cilisp.h"
%}

%union
{
   double dval;
   char *sval;
   struct ast_node *astNode;
};

%token <sval> FUNC
%token <dval> NUMBER
%token <sval> SYMBOL
%token LPAREN RPAREN EOL QUIT LET
%type <astNode> s_expr let_list let_elem

%%

program:/* empty */ {
                       printf("> ");
                    }
        | program s_expr EOL {
                              // printf("yacc: program expr\n");
                              printf("\n>> Result: %f", eval(0, $2));
                              freeNode($2);
                              printf("\n> ");
                           }
        ;

s_expr:
        NUMBER {
                  $$ = number($1);
              }
        | SYMBOL {
                  $$ = symbol($1);
          }
        | LPAREN LPAREN LET let_list RPAREN s_expr RPAREN {
                $$ = let_statement($4, $6);
                }
        | LPAREN FUNC s_expr RPAREN {
                                     // printf("yacc: LPAREN FUNC expr RPAREN\n");
                                     $$ = function($2, $3, 0);
                                     //printf("%s(%lf)", $2, $3);
                                  }
        | LPAREN FUNC s_expr s_expr RPAREN {
                                          // printf("LPAREN FUNC expr expr RPAREN\n");
                                          // $$ = calc($2, $3, $4);
                                          $$ = function($2, $3, $4);
                                       }
        | QUIT {
                  exit(0);
               }

        | error {
                        printf("error\n");
                    }
        ;

let_list:
  let_elem {
    $$ = let_list($1, 0);
  }
  | let_elem let_list  {
    $$ = let_list($1, $2);
  }
;

let_elem:
  LPAREN SYMBOL s_expr RPAREN {
    $$ = let_elem($2, $3);
  }
;



%%
