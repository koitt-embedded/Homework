#include <stdio.h>

int main(int argc, char** argv) {
	int* p[4];
	int test[5] = {10, 20, 30, 40, 50};
	int test2[2][5] = {{10, 20, 30,40, 50}, {60, 70, 80,90, 100}};
	int (*pp)[4] = test2;
	// int (*pp)[4] = test;
	printf("test2 addr : %p\n", &test2);
	printf("pp[0] val : %p\n", pp[0]);
	printf("test2[0][0] addr : %p\n", &test2[0][0]);
	printf("test2[0][0] val : %d\n", test2[0][0]);
	int i;
	for(i=0; i<5; i++) {
		if(i == 5) break ;
		p[i] = &test[i];
	}
	for(i=0; i<4; i++) {
		if(i < 2) {
			printf("(*pp)[%d] addr = %p\n", i, pp[i]);
			printf("(*pp)[%d] addr = %d\n", i, pp[i]);
			printf("(*pp)[%d] val = %d\n", i, *pp[i]);
		}
		// printf("p[%d] = %d\n", i, *p[i]);
	}
	return 0;
}