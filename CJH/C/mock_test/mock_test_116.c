#include <stdio.h>

int my_function(int num1, int num2, int num3) {
	return num2 * num3 - num1;
}

int main(int argc, char** argv) {
	int result = 0;
	int num1 = 2, num2 = 3, num3 = 4;
	result = my_function(num1, num2, num3);
	printf("result = %d\n", result);

	return 0;
}