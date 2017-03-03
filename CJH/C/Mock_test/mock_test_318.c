#include <stdio.h>

#define		SEQUENCE		0
#define		FIBO			1

int main(int argc, char** argv) {
	int i = 3, j = 1, k = 1, temp, l = 5;
	int sum[2];
	sum[SEQUENCE] = 1;
	sum[FIBO] = 1;
	while(i <= 40) {
		temp = k;
		k = k + j;
		j = temp;
		l += 2;
		if(i % 2) sum[SEQUENCE] += l;
		if(!(i % 2)) sum[FIBO] += k;
		i ++;
	}
	printf("sum = %d\n", sum[SEQUENCE] + sum[FIBO]);
	
	return 0;
}