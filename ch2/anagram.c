#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int len;
    char *orig;
    char *review;
}word_item;

int compare(const void *v1, const void *v2)
{
    return (*(char *)v1-*(char *)v2);
}

char * sign_word(char *word)
{
    qsort(word,strlen(word)-1,sizeof(char),compare);
    return word;
}

void sign_phase(char **param_data,int param_len)
{

    FILE *fp, *fp_obj;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen(param_data[param_len-1],"r");
    if(fp == NULL) 
        exit(EXIT_FAILURE);

    fp_obj = fopen("dict_obj","w");
    if(fp_obj == NULL)
        exit(EXIT_FAILURE);

    while((read = getline(&line, &len, fp)) != -1) {
        fprintf(fp_obj, "%s", line);
        fprintf(fp_obj, "%s", sign_word(line));
    }

    fclose(fp);
    fclose(fp_obj);
}

void sort_phase()
{
    FILE *fp_obj;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    word_item dict_word[24];

    fp_obj = fopen("dict_obj","w");
    if(fp_obj == NULL)
        exit(EXIT_FAILURE);

    while((read = getline(&line, &len, fp)) != -1) {

    }

    fclose(fp_obj);
}

int main(int argc, char* argv[])
{

    int param_len = argc;
    if(argc != 2)
        printf("not contain dictionary..\n");


    sign_phase(argv,param_len);


    return 0;
}
