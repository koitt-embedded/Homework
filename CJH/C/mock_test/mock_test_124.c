#include <stdio.h>

int main(int argc, char** argv) {
	int temp = 13;
	int* one = &temp;
	int** two = &one;
	int*** three = &two;
	int**** four = &three;

	printf("%d\n", ****four);

	****four = ****four + 1;

	printf("%d\n", ****four);

	return 0;
}