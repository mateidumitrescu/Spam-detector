#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <math.h>

#include "structure_t.h"

#include "utils.h"
#define S 256
#define E 11


void get_counter(int j, FILE *f, body_t *keyword)
{
    char str[S];
    int counter = 0;
    while(fscanf(f, "%s", str) && !feof(f)) {
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            if(isupper(str[i]))
                str[i] = tolower(str[i]);//making all the letters from the word small letters
        }
        if (strstr(str, keyword->name)) {
             keyword->count[j] += 1;
        }
    }
}
void search_in_files(int i, body_t *keyword)
{
    char email_file[S] = "data/emails/";
    char email_number[E];
    if (i == 0) {
        strcat(email_file, "0");
    } else {
        make_string(email_number, i);
        strcat(email_file, email_number);
    }
    FILE *f = fopen(email_file, "rt");
    if (!f)
    {
        fprintf(stderr, "Cannot open file\n");
        return;
    }
    reach_body(f);
    get_counter(i, f, keyword);//nr of appearences in email (i) of keyword
    fclose(f);

}

int number_of_keyw()
{
    FILE *f = fopen("data/keywords", "r");
    if (!f)
    {
        fprintf(stderr, "Cannot open file\n");
        return -1;
    }
    int nr_keywords;
    fscanf(f, "%d", &nr_keywords);

    fclose(f);

    return nr_keywords;
}

void get_keyword(char name[20], int n)
{
    FILE *f = fopen("data/keywords", "r");
    if (!f)//check if the file could be open
    {
        fprintf(stderr, "Cannot open file\n");
        return;
    }
    int i = 0;
    fscanf(f, "%s", name);
    while (i < n) {
        fscanf(f, "%s", name);
        i++;
    }
    fclose(f);
}