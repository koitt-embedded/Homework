#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int arr[7];
	int i, sum = 0, size = sizeof(arr) / sizeof(int);
	float mean;
	for(i=0; i<size; i++) {
		printf("input %d : ", i);
		scanf("%d", &arr[i]);
	}
	for(i=0; i<size; i++) sum += arr[i];
	mean = sum / size;
	printf("mean : %.2f\n", mean);
	for(i=0; i<size; i++) if(arr[i] >= mean) printf("name : arr[%d](%d)\n", i, arr[i]);

	return 0;
}