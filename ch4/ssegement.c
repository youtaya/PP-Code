#include <stdio.h>
#include <stdlib.h>


#define N0 0x5F
#define N1 0x05
#define N2 0x76
#define N3 0x75
#define N4 0x2D
#define N5 0x79
#define N6 0x7B
#define N7 0x15
#define N8 0x7F
#define N9 0x3D


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

void display_segment(seg_map var)
{

	printf("var is: %d\n", var.value);
	int i;
	for(i=0;i<7;i++)
		printf("%d: ",var.bit_show[i]);
	printf("\n");

	{

        if(var.bit_show[2])
        	printf("%s\n"," ___");
        else
        	printf("%s\n","   ");
        if(var.bit_show[3])
        	printf("%c",'|');
        else
			printf("%c",' ');

        if(var.bit_show[1])
        	printf("%s","___");
        else
        	printf("%s","   ");;

        if(var.bit_show[4])
        	printf("%c\n",'|');
        else
			printf("%c\n",' ');

        if(var.bit_show[5])
        	printf("%c",'|');
        else
			printf("%c",' ');

        if(var.bit_show[0])
        	printf("%s","___");
        else
        	printf("%s","   ");;

        if(var.bit_show[6])
        	printf("%c\n",'|');
        else
			printf("%c\n",' ');		

	}
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

    for(i=0;i<test_len;i++)
    	display_segment(value[i]);

    free(value);
}
