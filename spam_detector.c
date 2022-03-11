#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <math.h>

#include "utils.h"
#include "keyword_body.h"
#include "structure_t.h"


int main(void)
{
    int nr_emails, nr_keywords;
    nr_emails = number_of_emails();
    nr_keywords = number_of_keyw();
    FILE *out = fopen("statistics.out", "w");
    if (!out)
    {
        fprintf(stderr, "Cannot open file\n");
        return 0;
    }
    
    body_t *keyword;
    keyword = malloc(nr_keywords * sizeof(body_t));
    if (!keyword)
    {
        fprintf(stderr, "Malloc failed\n");
        return -1;
    }
    //index from 1, because the first line (0) is the number of keywords
    for (int i = 1; i < nr_keywords; i++)
    {
        int counter;
        get_keyword(keyword[i].name, i);
        //printf("%s\n", keyword[i].name);
        fprintf(out, "%s ", keyword[i].name);
        keyword[i].count = calloc(nr_emails, sizeof(int));
        for (int j = 0; j < nr_emails; j++) {
            search_in_files(j, &keyword[i]);
        }
        counter = all_counters(&keyword[i], nr_emails);
        double m_a = counter / nr_emails;
        keyword[i].stdev = stdev_for_kw(&keyword[i], m_a, nr_emails);
        fprintf(out, "%d ", counter);
        fprintf(out, "%.6f\n", keyword[i].stdev);
        free(keyword[i].count);
    }
    free(keyword);
    fclose(out);


    return 0;
}