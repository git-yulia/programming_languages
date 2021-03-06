/*

s-expressions calculator

program ::= | program s_expr EOL
s_expr ::= number
| symbol
| ( func s_expr )
| ( func s_expr s_expr )
| ( ( let let_list ) s_expr )
let_list ::= let_elem | let_list let_elem
let_elem ::= ( symbol s_expr )
symbol ::= letter+
letter ::= [a-zA-Z]
func ::= neg|abs|exp|sqrt|add|sub|mult|div|remainder|log|pow|max|min|exp2|cbrt|hypot
number ::= [+|-]?digit+[.number+]
digit ::= [0-9]

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

%token <sval> SYMBOL FUNC TYPE
%token <dval> NUMBER
%token LPAREN RPAREN EOL QUIT LET
%type <astNode> s_expr let_list let_elem

%%

program: /* empty */ {
                       printf("> ");
                    }
        | program s_expr EOL {
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
                  $$ = symbol(0, $1);
          }
        | LPAREN LPAREN LET let_list RPAREN s_expr RPAREN {
                $$ = let_statement($4, $6);
                }
        | LPAREN FUNC s_expr RPAREN {
                                     $$ = function($2, $3, 0);
                                  }
        | LPAREN FUNC s_expr s_expr RPAREN {
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
  LPAREN TYPE SYMBOL s_expr RPAREN {
    $$ = let_elem($2, $3, $4);
  }
  | LPAREN SYMBOL s_expr RPAREN {
    $$ = let_elem(0, $2, $3);
  }
;



%%
