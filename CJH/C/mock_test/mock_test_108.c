#include <stdio.h>

int main(int argc, char** argv) {
	int num1 = 7, num2 = 4;
	printf("num1 << num2 = %d\n", num1 << num2);
	printf("num1 >> num2 = %d\n", num1 >> num2);
	printf("num1 & num2 = %d\n", num1 & num2);
	printf("num1 | num2 = %d\n", num1 | num2);
	printf("num1 ^ num2 = %d\n", num1 ^ num2);

	return 0;
}