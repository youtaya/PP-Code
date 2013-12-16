#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char maptab[] = {
 0x01,
 0x02,
 0x04,
 0x08,
 0x10,
 0x20,
 0x40,
 0x80
};

#define alloer 100000000/8
char store[alloer];
char from[alloer];
char to[alloer];

int main()
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i;
    int j;
    int temp;
    int top=0;
    clock_t start, finish;
    double duration;
    for(i=0;i<alloer;i++) {
        if(store[i]!=0) {
            from[i] = top;
            to[top] = i;
            store[i] = 0;
            top++;
        }
    }

    for(i=0;i<alloer;i++) {
        if(to[i]!=0)
            printf("to %d is %d\n", i, to[i]);
    }

    fp = fopen("dump","r");
    if (fp == NULL) 
        exit(EXIT_FAILURE);

    start = clock();
    while((read = getline(&line, &len, fp)) != -1) {
        //printf("received line of length %zu : \n", read);
        //printf("%s", line);

        temp = 0;
        /*
        for(i=0;i<read;i++) {
            temp = temp*10+(*(line+i) - '0');
        }
        */
        temp = atoi(line);
        //printf("temp is %d\n", temp);

        store[temp/8] = store[temp/8]|maptab[temp%8];
        //printf("index is %d, value is %x\n", temp/8, store[temp/8]);
        
    }

    if(line)
        free(line);
    fclose(fp);


    /*
    for(i=0;i<alloer;i++) {
        if(store[i]!=0)
            printf("store is %d\n", store[i]);
    }
    */
    fp = fopen("clean", "w");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    for(i=0;(i<alloer);i++) {
        if(store[i]!=0) {
            for(j=0;j<8;j++) {
                temp = 0;
                if(maptab[j]&store[i]) {
                    temp = j+i*8;
                    fprintf(fp, "%d\n",temp);
                }
            }
        }
    }

    finish = clock();
    duration = (double)(finish-start)/CLOCKS_PER_SEC;
    printf("%f seconds\n", duration);

    fclose(fp);
    return 0;
}
