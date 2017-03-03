#include <stdio.h>

int main(int argc, char** argv) {
	unsigned int i = 1, j = 3, temp, cnt = 3;
	while(cnt <= 9) {
		temp = j;
		j = i + j;
		i = temp;
		printf("[%d] = %d\n", cnt ++, j);
	}
	printf("%dth value = %d\n", cnt - 1, j);

	return 0;
}