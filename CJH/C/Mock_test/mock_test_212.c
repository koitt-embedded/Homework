#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	char arr[10];
	char* cPointer = (char *)calloc(10, sizeof(char));
	int i = 0;

	while(*(cPointer + i)) {
		arr[i] = *(cPointer + i);
		i ++;
		putchar(arr[i]);
	}
	putchar('\n');

	return 0;
}