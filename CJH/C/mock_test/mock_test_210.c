#include <stdio.h>

int main(int argc, char** argv) {
	int arr1[3][3] = {{1, 3, 6}, {7, 1, 9}, {3, 7, 5}};
	int arr2[3][3] = {{3, 5, 7}, {9, 1, 8}, {5, 1, 2}};
	int max = -1, i, j, sum1 = 0, sum2 = 0;
	for(i=0; i<3; i++)
		for(j=0; j<3; j++)
			if(arr1[i][j] + arr2[i][j] > max) max = arr1[i][j] + arr2[i][j];
	printf("max = %d\n", max);

	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			sum1 += arr1[i][j];
			sum2 += arr2[i][j];
		}
	}

	printf("larger = %s %d\n", sum1 > sum2 ? "sum1" : "sum2", sum1 > sum2 ? sum1 : sum2);

	return 0;
}