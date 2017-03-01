#include <stdio.h>

struct mStr {
	float one;
	float two;
};

int main(int argc, char** argv) {
	struct mStr test = {55, 77.77};
	float temp = test.one;
	test.one = test.two;
	test.two = temp;

	printf("one = %.2f, two = %.2f\n", test.one, test.two);

	return 0;
}