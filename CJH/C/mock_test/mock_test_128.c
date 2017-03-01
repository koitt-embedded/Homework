#include <stdio.h>

int main(int argc, char** argv) {
	int first = 5, second = 15;
	int* i_am_pointer = &first;

	*i_am_pointer += second;
	i_am_pointer = &second;
	*i_am_pointer = first - *i_am_pointer;
	i_am_pointer = &first;
	*i_am_pointer = *i_am_pointer - second;

	printf("first = %d, second = %d\n", first, second);

	return 0;
}