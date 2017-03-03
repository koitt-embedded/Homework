#include <stdio.h>

void (* signal(int signum, void (*handler)(int)))(int);
void testOutputFunc(int arg1);

int main(int argc, char** argv) {
	// void (* signal(int signum, void (*handler)(int)))(int);
	// --> void (*)(int) signal(int signum, void (* handler)(int));
	int signum = 200;
	printf("arg1, signum = %d, arg2 functionPointer = %p\n\n", signum, testOutputFunc);
	signal(signum, testOutputFunc)(signum);
	return 0;
}

void (* signal(int signum, void (*handler)(int)))(int) {
	int arg1 = 100;
	printf("I'm void (* signal(int signum, void (*handler)(int)))(int), arg1 signum = %d, arg2 funtionPointer = %p\n", signum, handler);
	printf("to send arg1 = %d\n\n", arg1);
	handler(arg1);
	return handler;
}

void testOutputFunc(int arg1) {
	printf("\nI'm testOutputFunc, arg1 = %d\n", arg1);
	if(arg1 == 200) printf("And I called again!\n");
}