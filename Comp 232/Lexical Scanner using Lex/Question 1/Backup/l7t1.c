/**
Name : Yulia Maliauka
Date: March 8, 2017
Lab 7, Question 1
Professor Bieszczad & Professor Scrivnor
**/

#include "l7t1.h"

extern int number_of_terms;
extern int sum_of_terms;

extern FILE *yyin;

char *targetWords[NUM_OF_WORDS] = {"bank", "dollar", "finance", "budget", "fund", "stock", "bond", "invest"};

int main(int argc, char *argv[])
{
   yyin = freopen(argv[1], "r", stdin);

   WORD word = NO_TOK;
   while((word = yylex()) != NO_TOK)
      if ((word > 0) && (word < NUM_OF_WORDS))
         printf("My word is %s", targetWords[word-BANK]);
}
