#include <stdio.h>
#include <stdlib.h>

#define MOU 10000
int m[MOU/2],n[MOU/2];

int biSection(int *raw1,int *raw2, int left, int right, int old,int range)
{
    int i=0;
    int newl,newr;
    int *newD1,*newD2;
    int mid,newRange;
    newl=newr=0;
    newD1=malloc(sizeof(int)*range);
    newD2=malloc(sizeof(int)*range);


    if(0==left||0==right||0==range) {
        printf("miss %d\n",old);
        free(newD1);
        free(newD2);
        return 0;
    }else if(left<right){

        for(i=0;i<left;i++) {
            mid = old-range;
            if(raw1[i] < mid || raw1[i] == mid) {
                newD1[newl++] = raw1[i];
            }else {
                newD2[newr++] = raw1[i];
            }
        }
        newRange = range/2;
        biSection(&newD1[0],&newD2[0],newl,newr,mid,newRange);
    }else {
        for(i=0;i<right;i++) {
            mid = old+range;
            if(raw2[i] < mid || raw2[i] == mid) {
                newD1[newl++] = raw2[i];
            }else {
                newD2[newr++] = raw2[i];
            }
        }
        newRange = range/2;
        biSection(&newD1[0],&newD2[0],newl,newr,mid,newRange);
    }

    free(newD1);
    free(newD2);

    printf("finish or not!\n");
    return 0;
}

int main() 
{
    int data;
    int i,j,x;
    i = 0;
    j = 0;
    while(scanf("%d", &data)!=EOF) {
        if(data < MOU/2 || data == MOU/2) {
            m[i++] = data;
        }else {
            n[j++] = data;
        }
    }

    biSection(&m[0],&n[0],i,j,MOU/2,MOU/4);

    return 0;
}
