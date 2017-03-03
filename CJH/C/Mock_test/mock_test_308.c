#include <stdio.h>

int main(int argc, char** argv) {
	int i = 1, j = 1, temp, cnt = 3, oddS = i + j, evenS = 0;
	while(cnt <= 30) {
		temp = j;
		j = i + j;
		i = temp;
		if(j % 2) oddS += j;
		else evenS += j;
		// printf("ddd : %d, %d\n", oddS, evenS);
		// printf("debug : %d[%d]\n\n", j, cnt ++);
		printf("%d\n", j);
		printf("%d\n", oddS);
		printf("%d\n\n", evenS);
		cnt ++;
	}
	printf("oddS - evenS = %d\n", oddS - evenS);

	return 0;
}