#include <stdio.h>
#include <stdlib.h>

int vect[] = {12, -24, 31, -27, 11, 33, -24, 56, -9, -13, 8, 19, 22, -17, 9, 7};
int len = sizeof(vect)/sizeof(int);


void find_sub_vector_01()
{
	int i,j,k;
	int sum,tmp;
	int count = 0;
	tmp = 0;
	for(i=0;i<len;i++)
	{
		sum = 0;
		
		for(j=i;j<len;j++)
		{
			for(k=i;k<j;k++)
			{

				sum += vect[k];						
			}

			printf("start : [%d], end : [%d], sum : %d\n", i, (j-1), sum);
			count++;
			tmp = (sum>tmp)?sum:tmp;
			sum = 0;
		}
		
	}

	printf("%d steps to cal: sub vector max is %d\n", count, tmp);
}

void find_sub_vector_02()
{
	int i,j,k;
	int sum,tmp;
	int count = 0;
	tmp = 0;
	for(i=0;i<len;i++)
	{
		sum = 0;
		
		for(j=i;j<len;j++)
		{

			sum += vect[j];		

			printf("start : [%d], end : [%d], sum : %d\n", i, j, sum);
			count++;
			tmp = (sum>tmp)?sum:tmp;
		}
		
	}

	printf("%d steps to cal: sub vector max is %d\n", count, tmp);
}

void find_sub_vector_03()
{
	int i,j,k;
	int sum,tmp;
	int count = 0;
	tmp = 0;
	int curmax[len];

	curmax[-1] = 0;
	for(i=0;i<len;i++)
		curmax[i] = curmax[i-1]+vect[i];

	for(i=0;i<len;i++)
	{
		
		for(j=i;j<len;j++)
		{

			sum = curmax[j] - curmax[i-1];		

			printf("start : [%d], end : [%d], sum : %d\n", i, j, sum);
			count++;
			tmp = (sum>tmp)?sum:tmp;
		}
		
	}

	printf("%d steps to cal: sub vector max is %d\n", count, tmp);
}

int main()
{
	find_sub_vector_01();
	find_sub_vector_02();
	find_sub_vector_03();
    return 0;
}
