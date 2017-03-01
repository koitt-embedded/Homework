#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
	int arr[100] = {0}, lastPoint;
	srand(time(NULL));
	int i, debug = rand() % 100 + 1;
	for(i=0; i<debug; i++) {
		arr[i] = rand() % 4095 + 1;
		if(i == debug - 1) lastPoint = debug;
		printf("value : %d, [%d]\n", arr[i], i);
	}

	printf("leak : %d\n", 100 - lastPoint);
	return 0;
}