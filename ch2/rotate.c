/*
 * rotate.c
 *
 *  Created on: 2013-12-18
 *      Author: youtaya
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

typedef enum {
	forward,
	backward,
}direct;

void rotate(char *str, int n, int i)
{
    char temp0,temp;
    int k, j;
    int loop = n/i;
    int left = n%i;
    //printf("loop number is %d\n", loop);
    temp0 = str[0];
    for(k=0;k<i;k++)
    {
	temp = str[k];
	for(j=0;j<loop;j++)
	{
	    if((k+(j+1)*i)%n < i)
	    {
		if(left > 0)
		{
		    str[(k+j*i)%n] = temp0;
		    temp0 = temp;
		}else {
		    str[(k+j*i)%n] = temp;
		}

	    }else {
		str[(k+j*i)%n] = str[(k+(j+1)*i)%n];
	    }

	    if ((left > 0) && (j == loop-1) && (k == 0)/*((k+(j+2)*i)%n == (i-1))*/) {

		str[(k+(j+1)*i)%n] = str[(k+(j+2)*i)%n];
	    }
	}
    }


}

void swap(char *str,int waitLen, int left, int right, int start, int range, int stop, int dir)
{
	int i;
	char temp;

	if(1 == waitLen||0 == left||0 == right)
		return;

	for(i=0;i<range;i++)
	{
		temp = str[start+i];
		str[start+i] = str[stop-range+1+i];
		str[stop-range+1+i] = temp;
	}

	waitLen = waitLen-range;

	switch(dir)
	{
	case backward:
		left = range;
		right = waitLen-range;
		stop = stop-range;
		break;
	case forward:
		left = waitLen-range;
		right = range;
		start = start+range;
		break;
	}

	if(right > left)
	{
		dir = backward;
		range = left;
	}else {
		dir = forward;
		range = right;
	}

	printf("params: %d, %d, %d, %d, %d, %d, %d\n", waitLen, left, right, start, range, stop, dir);
	swap(str, waitLen, left, right, start, range, stop, dir);
}
void rotate2(char *str, int n, int i)
{
	int left = i;
	int right = n-i;
	int stop = n-1;
	int start, range;
	direct dir;

	assert(right > left);

	start = 0;
	range = left;
	dir = backward;

	swap(str, n, left, right, start, range, stop, dir);
}

void reverse(char *str, int start, int stop)
{
    int j;
    int len = stop-start;
    int range = len/2;
    char temp;
    for(j=0;j<range;j++)
    {
	temp = str[start+j];
	str[start+j] = str[stop-1-j];
	str[stop-1-j] = temp;
    }

}
void rotate3(char *str, int n, int i)
{
    reverse(str,0,i);
    reverse(str,i,n);
    reverse(str,0,n);
}

int main(int argc, char* argv[])
{
    int i;
    int len;
    char a[]={'a','b','c','d','e','f','g'};
    char b[]={'a','b','c','d','e','f','g','h','i'};

    len = sizeof(a);
    rotate2(a, len, 3);
    for(i=0;i<len;i++)
	    printf("%c ",a[i]);
    printf("\n");

    len = sizeof(b);
    rotate2(b, len, 3);
    for(i=0;i<len;i++)
	    printf("%c ",b[i]);
    printf("\n");

    return 0;
}

