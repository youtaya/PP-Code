#include <stdio.h>
#include <stdlib.h>

#define whiteBean 17
#define blackBean 17

void colorLeft(int w, int b)
{
	int choose;
	if(w==1) {
		printf("left is white\n");
		return;
	}
	if(b==1) {
		printf("left is black\n");
		return;
	}
	choose = rand()%3;
	switch(choose){
		case 0:
			// one white and one black
			b = b-1;
			colorLeft(w,b);
			break;
		case 1:
			// all black
			b = b-1;
			colorLeft(w,b);
			break;
		case 2:
			// all white
			w = w-2;
			b = b+1;
			colorLeft(w,b);
			break;

	}

}

int main()
{
	srand((int)time(0));
	colorLeft(whiteBean,blackBean);
	return 0;
}
