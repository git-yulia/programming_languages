/**
Name : Yulia Maliauka
Date: March 8, 2017
Lab 7, Question 1
Professor Bieszczad & Professor Scrivnor
**/

#include "l7t1.h"

extern float sum_of_dollars;
extern float sum_of_numbers;

extern FILE *yyin;
extern char *yytext;

char *targetWords[NUM_OF_WORDS] = {"bank", "dollar", "finance",
 "budget", "fund", "stock", "bond", "invest"};

int main(int argc, char *argv[])
{
   yyin = freopen(argv[1], "r", stdin);

   WORD word = NO_TOK;

   // This while loop prints the values with tags.
   while((word = yylex()) != NO_TOK) {
      // if ((word > 0) && (word < NUM_OF_WORDS))
      switch(word) {
          // Cases 1 - 8: key words, print <!> word <!>
          case 1:
          case 2:
          case 3:
          case 4:
          case 5:
          case 6:
          case 7:
          case 8:
                 printf("<!> %s <!> ", targetWords[word-BANK]);
                 break;

          // Case 2: Print <$> money <$>
          case 9:
                 printf("<$> %s <$> ", yytext);
                 break;

          case 10:
                 printf("<#> %s <#> ", yytext);
                 break;

          // By default, print the text exactly as is.
          default:
                  printf("%s ", yytext);
                  break;

       } // end of switch
   } // end of while

   // Part II: Report findings.
   if (sum_of_dollars > 1000) {
       printf("\nVERY INTERESTING READING!");
       printf("\nReported sum of dollars: $%.2lf\n", sum_of_dollars);
   }
   // I'm using nested else ifs because there would be no need
   //   to scan the array unless the else is run.
  else {
      // Check if there are more than three keywords in the paper.
    int terms = 0; int i = 0;
     while (terms < 3 && i < 8) {
          if (frequencies[i] > 0) {
              terms++;
          }
        i++;
      }

      if (terms >= 3) {
          printf("\nPOTENTIALLY INTERESTING READING!");
          printf("\nReported sum of numbers: %.2lf", sum_of_numbers);
          printf("\nConcordance:\n");
          for (int i = 1; i <= 8; i++) {
              printf("%s: [%d] \n", targetWords[i - 1], frequencies[i]);
          }
      }
      else {
          printf("\nNo point in reading this trash.\n");
      }
  }









   return 0;
}

/**
int sum (int terms[8], int sum_of_terms) {


    return 0;
}
*/
