#include <stdio.h>
#include <stdlib.h>

#define MOU 10000
int org[MOU];

void biSearch(int *raw, int l, int u, int findValue)
{
    int temp = findValue;
    int left, right;
    if(l>u|l==u) {
        printf("not find %d\n", findValue);
        return;
    }
    
    if(temp == raw[u/2]) {
        printf("good luck!");
        left = l;
        right = u/2;
        temp = (raw[left]+raw[right-1])/2;
        biSearch(raw,left, right,temp);
    } else if(temp < raw[u/2]){
        left = u/2;
        right = u;
        biSearch(raw, left,right,temp);
    } else {
        left = l;
        right = u/2;
        biSearch(raw,left, right,temp);
    }
}
int myCount(const void *v1, const void *v2)
{
    return (*(int *)v1-*(int *)v2);
}
int main() 
{
    int data;
    int temp;
    int i = 0;

    while(scanf("%d", &data)!=EOF) {

        org[i++] = data;
    }
    qsort(org,i,sizeof(int),myCount);
    temp = (org[0]+org[i-1])/2;
    biSearch(org, 0, i,temp);

    return 0;
}
