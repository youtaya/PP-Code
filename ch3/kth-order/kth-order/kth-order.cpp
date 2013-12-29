// kth-order.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/*
** equation : a[n] = c[1]a[n-1]+c[2]a[n-2]+c[3]a[n-3]+...+c[k]a[n-k]+c[k+1]
*/

typedef struct {
	int k;
	int m;
	int *c;
	int *a;
} var_factor;

//for example: k=5 kth order
void withArray(int k, int *c, int *a, int m)
{
	/*
	int k = 5;
	int c[7] = {0,1,2,3,4,5,6};
	int a[14] = {0,7,8,9,10,11};
	int m  = 13;
	*/
	int i;
	int *out = (int *)malloc(sizeof(int)*m);
	memset(out, 0, sizeof(int)*m);

	for(i=0;i<k;i++)
	{
		out[i] = a[i];
	}
	for(i=5;i<13;i++) {
		out[i] = c[0]*out[i-1]+c[1]*out[i-2]+c[2]*out[i-3]+c[3]*out[i-4]+c[4]*out[i-5]+c[5];
		printf("%d: %d\n",i+1, out[i]);
	}

	free(out);
}
void withoutArray(int k, int *c, int *a, int m)
{
	int i,j;
	var_factor vf;
	vf.k = k;
	vf.m = m;
	vf.c = (int *)malloc(sizeof(int)*(k+1));
	memset(vf.c, 0, sizeof(int)*(k+1));
	vf.a = (int *)malloc(sizeof(int)*m);
	memset(vf.a, 0, sizeof(int)*m);

	for(i=0;i<k;i++)
	{
		vf.a[i] = a[i];
	}
	for(i=0;i<(k+1);i++)
	{
		vf.c[i] = c[i];
	}

	for(i=k;i<m;i++)
	{
		for(j=0;j<k;j++)
		{
			vf.a[i] += c[j]*vf.a[i-1-j];
		}
		vf.a[i] += vf.c[k];
	}

	for(i=0;i<m;i++)
	{
		printf("%d : %d\n",i+1,vf.a[i]);
	}

	free(vf.c);
	free(vf.a);

}

int _tmain(int argc, _TCHAR* argv[])
{
	int k = 5;
	int c[6] = {1,2,3,4,5,6};
	int a[5] = {7,8,9,10,11};
	int m  = 13;	
	withArray(k,c,a,m);
	withoutArray(k,c,a,m);
	return 0;
}

