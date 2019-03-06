/**
Name : Yulia Maliauka
Date: March 8, 2017
Lab 7, Question 1
Professor Bieszczad & Professor Scrivnor
**/

#ifndef __l7t1_h_
#define __l7t1_h_

#include <stdio.h>

#define NUM_OF_WORDS 8
typedef enum {
    NO_TOK=0,
    BANK,
    DOLLAR,
    FINANCE,
    BUDGET,
    FUND,
    STOCK,
    BOND,
    INVEST,
    MONEYS,
    NUMBER,
    OTHER
} WORD;

// This array contains the frequencies of the terms.
int frequencies[9];

// int sum(int[8], int);
// function computing a sum of all element of an array
// the second parameter is the size of the array

int yylex(void);

#endif
