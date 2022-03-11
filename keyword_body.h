#ifndef KEYWORD_BODY_H
#define KEYWORD_BODY_H

#include <stdio.h>
#include "structure_t.h"

//function to get the stdev and the counter for each keyword in the file
//that we're working with
void get_counter(int j, FILE *f, body_t *keyword);

//function to get the name of the file that we're working with and search
//and open it
void search_in_files(int i, body_t *keyword);

//function to get the number of keywords that
//we're working with
int number_of_keyw();

//function to get the "n" keyword from list
void get_keyword(char name[20], int n);


#endif