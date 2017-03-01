#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
	int arr[20];
	int i, even = 0, odd = 0;
	srand(time(NULL));
	for(i=0; i<20; i++) {
		arr[i] = rand() % 100 + 1;
		// debug
		printf("%d\t", arr[i]);
	}
	printf("\n");

	for(i=0; i<20; i++) {
		if(arr[i] % 2) odd += arr[i];
		else even += arr[i];
	}
	printf("even sum = %d, odd sum = %d\n", even, odd);

	return 0;
}