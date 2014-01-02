#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char* argv[])
{
	int whiteBean;
	int blackBean;

	whiteBean = atoi(argv[1]);
	blackBean = atoi(argv[2]);
	

	printf("black is %d, white is %d\n", whiteBean, blackBean);
	srand((int)time(0));
	colorLeft(whiteBean,blackBean);
	return 0;
}
