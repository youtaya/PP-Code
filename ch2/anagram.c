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

void sign_phase(word_item *dict_word, int *word_num, char **param_data,int param_len)
{

    FILE *fp/*, *fp_obj*/;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int index = *word_num;
    fp = fopen(param_data[param_len-1],"r");
    if(fp == NULL) 
        exit(EXIT_FAILURE);

    /*
    fp_obj = fopen("dict_obj","w");
    if(fp_obj == NULL)
        exit(EXIT_FAILURE);
    */

    while((read = getline(&line, &len, fp)) != -1) {
        dict_word[index].len = read; 
        dict_word[index].orig = (char *)malloc(sizeof(char)*read);
        dict_word[index].review = (char *)malloc(sizeof(char)*read);
        strncpy(dict_word[index].orig,line,read);
        strncpy(dict_word[index].review,sign_word(line),read);
        index++;

        //fprintf(fp_obj, "%s", line);
        //fprintf(fp_obj, "%s", sign_word(line));

    }

    *word_num = index;

    fclose(fp);
    /*
    fclose(fp_obj);
    */
}

int compare2(const void *v1, const void *v2)
{
    word_item *w1 = (word_item *)v1;
    word_item *w2 = (word_item *)v2;

    int nsize = (w1->len > w2->len)?w1->len:w2->len;
    return strncmp(w1->review,w2->review,nsize);
}
void sort_phase(word_item *dict_word, int index)
{
    qsort(dict_word,index,sizeof(word_item),compare2);
}

void anagram_phase(word_item *dict_word, int index, char **param_data, int param_len)
{

    int i;
    int count = 0;
    FILE *fp;
    int  nsize = strlen(param_data[param_len-1])+sizeof(char)*4;
    char * out_name = (char *)malloc(nsize);
    memset(out_name, 0, nsize);
    strncpy(out_name,param_data[param_len-1],strlen(param_data[param_len-1]));
    strcat(out_name,".out");
    fp = fopen(out_name,"w");

    if(fp == NULL) 
        exit(EXIT_FAILURE);


    char *temp = dict_word[0].review;
    for(i=0;i<index;i++)
    {

        if(strcmp(temp, dict_word[i].review) < 0)
        {
            fprintf(fp, "count is %d\n", count);
            fprintf(fp, "%s", dict_word[i].orig);
            temp = dict_word[i].review;
            count = 1;
        }else {

            fprintf(fp, "%s", dict_word[i].orig);
            count++;
        }

    }


    fclose(fp);
    free(out_name);
}

void free_dict(word_item *dict_word, int index)
{
    int i = 0;
    for(i=0;i<index;i++)
    {
        free(dict_word[i].orig);
        dict_word[i].orig = NULL;
        free(dict_word[i].review);
        dict_word[i].review = NULL;
    }
}

int main(int argc, char* argv[])
{

    word_item dict_word[128];
    int index = 0;
    int param_len = argc;
    if(argc != 2)
        printf("not contain dictionary..\n");


    sign_phase(dict_word, &index, argv, param_len);
    sort_phase(dict_word, index);
    anagram_phase(dict_word, index, argv, param_len);

    free_dict(dict_word,index);
    return 0;
}
