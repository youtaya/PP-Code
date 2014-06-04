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

int omax(int v1, int v2)
{
	return ((v1-v2)>0?v1:v2);
}

int emax(int vv, int v3, int v4)
{
	int tmp;

	tmp = (vv-v3)>0?vv:v3;
	tmp = (tmp-v4)>0?tmp:v4;
	return tmp;
}

int maxsum(int left, int right)
{
	int m;
	int sum, tmp;
	int lmax, rmax;
	int i = 0;
	

	if(left>right)
		return 0;

	if(left == right)
		return omax(0,vect[left]);

	printf("(1)left : %d, right : %d\n", left, right);
	m = (left+right)/2;

	lmax = sum = 0;
	for(i=m;i>=left;i--)
	{
		sum += vect[i];
		lmax = omax(lmax, sum);
	}

	rmax = sum = 0;

	for(i=m+1;i<=right;i++)
	{
		sum += vect[i];
		rmax = omax(rmax, sum);
	}
	printf("(2)left : %d, right : %d\n", lmax, rmax);

	return emax(lmax+rmax, maxsum(left, m), maxsum(m+1,right));

}


void divide_conquer()
{
	int res = maxsum(0,len-1);
	printf("result is %d\n", res);

}
void scan_throgh()
{
	int i;
	int maxsofar = 0;
	int maxending = 0;

	for(i=0;i<len;i++)
	{
		maxending = omax(maxending+vect[i], 0);
		maxsofar = omax(maxsofar, maxending);
	}

	printf("maxsofar: %d, maxending: %d\n", maxsofar, maxending);
}

int main()
{
	divide_conquer();
	scan_throgh();
    return 0;
}
