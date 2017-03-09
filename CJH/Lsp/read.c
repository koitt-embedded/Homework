#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define		BUFSIZE		1024
#define		EMPTY		0

int main(int argc, char** argv) {
	int fd, rSize;
	char buf[BUFSIZE] = {EMPTY};
	fd = open("./read.txt", O_RDONLY);
	rSize = read(fd, buf, BUFSIZE);
	buf[rSize - 1] = EMPTY;
	printf("%s\n", buf);
	printf("file size : %d\n", rSize);
	close(fd);

	return 0;
}