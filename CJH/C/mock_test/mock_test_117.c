#include <stdio.h>

int main(int argc, char** argv) {
	char arr[100];
	int i = 0;
	printf("input : ");
	scanf("%s", arr);
	while(arr[i]) {
		if(!((arr[i]) % 2)) putchar(arr[i]);
		i ++;
	}
	putchar('\n');
	return 0;
}