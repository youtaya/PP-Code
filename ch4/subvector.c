#include <stdio.h>
#include <stdlib.h>

int vect[] = {12, -24, 31, -27, 11, 33, -24, 56, -9, -13, 8, 19, 22, -17, 9, 10};
int len = sizeof(vect)/sizeof(int);


void find_sub_vector()
{
	int i,j,k;
	int sum,tmp;
	tmp = 0;
	for(i=0;i<len;i++)
	{
		sum = 0;
		
		for(j=0;j<i;j++)
		{
			for(k=j;k<i;k++)
			{

				sum += vect[k];
				printf("start : [%d], end : [%d], sum : %d\n", j, i, sum);
			}

			tmp = (sum>tmp)?sum:tmp;
			sum = 0;
		}
		
	}

	printf("sub vector max is %d\n", tmp);
}


int main()
{
	find_sub_vector();
    return 0;
}
