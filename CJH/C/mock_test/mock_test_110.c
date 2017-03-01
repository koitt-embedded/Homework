#include <stdio.h>

#define inc_each(x, y) {x++; y++;}

int main(int argc, char** argv) {
	int x = 10, y = 5;
	// it's original code
	// if(x > y) inc_each(x, y);
	// fixes case 1
	if(x > y) inc_each(x, y)
	// fixes case 2
	if(x > y) {inc_each(x, y);}
	else x = y;

	// because macro function is just convert to own content

	printf("%d, %d\n", x, y);

	return 0;
}