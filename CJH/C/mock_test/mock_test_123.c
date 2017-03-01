#include <stdio.h>

int main(int argc, char** argv) {
	char charac;
	printf("input : ");
	scanf("%c", &charac);
	charac ^= 32;
	putchar(charac);
	putchar('\n');

	return 0;
}