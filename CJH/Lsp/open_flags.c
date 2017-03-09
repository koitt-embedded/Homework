#include <stdio.h>
#include <fcntl.h>

#define		BUFSIZE		512

int main(int argc, char** argv) {
	int fd[5] = {0};
	char buf[BUFSIZE] = {0};

	// O_CREAT make file(if it doesn't exist)
	fd[0] = open("o_create.txt", O_CREAT);

	// O_EXCL 
	fd[1] = open("o_create.txt", O_EXCL);

	// O_EXCL 
	fd[2] = open("o_create.txt", O_CREAT | O_EXCL);

	// O_TRUNC
	fd[3] = open("o_trunc.txt", O_TRUNC);

	for(int i=0; i<4; i++) printf("fd value : %d\n", fd[i]);

	// O_EXCL 
	fd[4] = open("o_excl.txt", O_CREAT | O_EXCL);

	printf("fd value : %d\n", fd[4]);

	return 0;
}