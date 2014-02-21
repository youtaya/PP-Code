#include <stdio.h>
#include <stdlib.h>


typedef struct segment_map {
    int value;
    int bit_show[7];
}seg_map;

seg_map smap[] = {
    {0, {1,0,1,1,1,1,1}},
    {1, {0,0,0,0,1,0,1}},
    {2, {1,1,1,0,1,1,0}},
    {3, {1,1,1,0,1,0,1}},
    {4, {0,1,0,1,1,0,1}},
    {5, {1,1,1,1,0,0,1}},
    {6, {1,1,1,1,0,1,1}},
    {7, {0,0,1,0,1,0,1}},
    {8, {1,1,1,1,1,1,1}},
    {9, {0,1,1,1,1,0,1}},
};

int test_data[] = {6,5,5,3,5};


typedef struct secondLine {
	int vertical1;
	int horital;
	int vertical2;
}secLine;

typedef struct wholeHouse {
	int line0;
	secLine *line12;
} wholeHs;

void printVertical(int v) 
{
	if(v)
		printf("%c",'|');
	else
		printf("%c",' ');
}

void printHorizontal(int v)
{
	if(v)
		printf("%s","___");
	else
		printf("%s","   ");	
}

void print210(int *v1)
{
	int i;
	
	for(i=0;i<5;i++)
	{
		printf("%c", ' ');
		printHorizontal(v1[i]);

		printf("\t");
	}

	printf("\n");

}

void print3456(secLine *v1)
{
	int i;
	for(i=0;i<5;i++)
	{

		printVertical(v1[i].vertical1);

		printHorizontal(v1[i].horital);

		printVertical(v1[i].vertical2);

		printf("\t");

	}
	printf("\n");
}
void printWhoHs(wholeHs *whole)
{
	int i,j;
	for(i=0;i<5;i++)
	{
		printf("%c", ' ');
		printHorizontal(whole[i].line0);

		printf("\t");
	}
	printf("\n");

	for(j=0;j<2;j++)
	{
		for(i=0;i<5;i++)
		{

			printVertical(whole[i].line12[j].vertical1);

			printHorizontal(whole[i].line12[j].horital);

			printVertical(whole[i].line12[j].vertical2);

			printf("\t");
		}
		printf("\n");
	}
			
}

void display_segment3(seg_map *var)
{

	int i,j;
	int seg_table[7] = {2,3,1,4,5,0,6};

	wholeHs *whl = (wholeHs *)malloc(sizeof(wholeHs)*5);
	memset(whl,0,sizeof(wholeHs)*5);
	for(i=0;i<5;i++)
	{
		whl[i].line12 = (secLine *)malloc(sizeof(secLine)*2);
	}

	for(i=0;i<5;i++)
	{
		memset(whl[i].line12,0,sizeof(secLine)*2);
	}

	for(i=0;i<5;i++)
	{
		whl[i].line0 = var[i].bit_show[2];
		whl[i].line12[0].vertical1 = var[i].bit_show[3];
		whl[i].line12[0].horital = var[i].bit_show[1];
		whl[i].line12[0].vertical2 = var[i].bit_show[4];
		whl[i].line12[1].vertical1 = var[i].bit_show[5];
		whl[i].line12[1].horital = var[i].bit_show[0];
		whl[i].line12[1].vertical2 = var[i].bit_show[6];
	}



	printWhoHs(whl);
	for(i=0;i<5;i++)
	{
		free(whl[i].line12);
	}
	free(whl);
}

void display_segment2(seg_map *var)
{

	int i,j;
	int seg_table[7] = {2,3,1,4,5,0,6};

	secLine **sl = (secLine **)malloc(sizeof(secLine *)*2);
	sl[0] = (secLine *)malloc(sizeof(secLine)*5);
	sl[1] = (secLine *)malloc(sizeof(secLine)*5);

	memset(sl[0],0,sizeof(secLine)*5);
	memset(sl[1],0,sizeof(secLine)*5);

	int line0[5];
	for(i=0;i<5;i++)
	{
		line0[i] = var[i].bit_show[2];
	}
	for(j=0;j<2;j++)
	{
		for(i=0;i<5;i++)
		{
			sl[j][i].vertical1 = var[i].bit_show[seg_table[j*3+1]];
			sl[j][i].horital = var[i].bit_show[seg_table[j*3+2]];
			sl[j][i].vertical2 = var[i].bit_show[seg_table[j*3+3]];
		}
	}

	print210(line0);

	print3456(sl[0]);
	print3456(sl[1]);

	free(sl[0]);
	free(sl[1]);
	free(sl);
}
void test_display()
{
	printf("%s\n"," ___");
	printf("%s\n","|___|");
	printf("%s\n","|___|");
}
void main()
{
    seg_map *value = (seg_map *)malloc(sizeof(seg_map)*5);
    memset(value, 0, sizeof(seg_map)*5);

    int test_len = sizeof(test_data)/sizeof(int);

    int i,j;
    for(i=0;i<test_len;i++)
    {

        value[i].value = test_data[i];
        for(j=0;j<7;j++)
        {
        	value[i].bit_show[j] = smap[test_data[i]].bit_show[j];
        }
    }

    /*
    for(i=0;i<test_len;i++)
    	display_segment(value[i]);
    */

    display_segment3(value);

    free(value);
}
