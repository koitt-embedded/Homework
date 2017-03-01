#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	char* raw = "What doesn't kill me makes me strong";
	char* test = "me";
	int i = 0, j = 0, flag = 0, temp, count = 0;
	while(raw[i]) {
		temp = i;
		while(test[j]) if(raw[temp + j] != test[j ++]) flag = 1;
		if(!flag) count ++;
		i ++;
		j = 0;
		flag = 0;
	}
	printf("counted = %d\n", count);

	return 0;
}