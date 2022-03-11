#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <math.h>

#include "structure_t.h"
#define S 256

int number_of_emails()
{

    int file_count = 0;
    DIR *dir_path;
    struct dirent *entry;

    dir_path = opendir("data/emails/");

    if(!dir_path)
    {
        //check if the directory could be open
        fprintf(stderr, "Cannot open directory!\n");
        return -1;
    }

    while ((entry = readdir(dir_path)) != NULL) {
        if (entry -> d_type == DT_REG) { //regular file
            file_count++;
        }
    }
    closedir(dir_path);

    return file_count;
}

void make_string(char str[], int num)
{
    int i, r, len = 0, n;
 
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        r = num % 10;
        num /= 10;
        str[len - (i + 1)] = r + '0';
    }
    str[len] = '\0';
}

int nr_of_digits(int n)
{
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

int length_of_line(FILE *f)
{
    int count;
    char c;

    count = 0;
    while (c != EOF && c != '\n')
    {
        c = fgetc(f);
        count++;
    }

    return count;
}

void reach_body(FILE *f)
{
    char str[S];
    char c;
    fscanf(f, "%s", str);
    while (strcmp(str, "Body:") != 0) {
        fscanf(f , "%s", str);
    }
    return;
}

int sum_of_counters(body_t *keyword, int nr_emails)
{
    int s = 0;
    for (int i = 0; i < nr_emails; i++)
        s += keyword->count[i];
    return s;
}

int all_counters(body_t *keyword, int nr_emails)
{
    int cnt = 0;
    for (int i = 0; i < nr_emails; i++)
        cnt += keyword->count[i];
    
    return cnt;
}

double stdev_for_kw(body_t *keyword, double m_a, int nr_emails)
{
    double stdev = 0;
    for (int i = 0; i < nr_emails; i++) {
        stdev += (keyword->count[i] - m_a) * (keyword->count[i] - m_a) / nr_emails;
    }

    return stdev;
}

