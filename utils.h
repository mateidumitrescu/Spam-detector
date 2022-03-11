#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include "structure_t.h"

//function to count the number of files from the emails directory
int number_of_emails();

//function to convert an integer to a string
void make_string(char str[], int num);

//function to get the nr of digits of a number
int nr_of_digits(int n);

//function to get the size of one line in the file
int length_of_line(FILE *f);

//function to reach "Body:" in file
void reach_body(FILE *f);

//function to get the sum of all counters
int sum_of_counters(body_t *keyword, int nr_emails);

//function to calculate the total of appereances of keyword in emails
int all_counters(body_t *keyword, int nr_emails);

//function to get the stdev for keyword
double stdev_for_kw(body_t *keyword, double m_a, int nr_emails);

#endif