#include <stdio.h>

int main(int argc, char** argv) {
	char* str = "Pointer is Very Important";
	int i = 0, j = 0;
	while(str[i]) {
		if(str[i] >= 65 && str[i] <= 90) j ++;
		i ++;
	}
	printf("res = %d\n", j);

	return 0;
}