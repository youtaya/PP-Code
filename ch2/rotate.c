#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void rotate2(char *str, int n, int i)
{

}

void reverse(char *str, int start, int stop)
{
    int i,j;
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
    //not support this case:
    //char c[]={'a','b','c','d','e'};

    len = sizeof(a);
    rotate3(a, len, 3);
    for(i=0;i<len;i++)
	    printf("%c ",a[i]);
    printf("\n");

    len = sizeof(b);
    rotate3(b, len, 3);
    for(i=0;i<len;i++)
	    printf("%c ",b[i]);
    printf("\n");

    return 0;
}

