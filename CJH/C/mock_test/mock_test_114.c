#include <stdio.h>

int main(int argc, char** argv) {
	int number = 1;
	for(;;) {
		printf("number = %d\n", number);
		number += number;
		if(number >= 1000) break;
	}
	return 0;
}