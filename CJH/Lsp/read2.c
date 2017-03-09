#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define		BUFSIZE		32
#define		EMPTY		0

int main(int argc, char** argv) {
	int fd, rSize, sum = 0;
	char buf[BUFSIZE] = "\0";
	fd = open("./read2.txt", O_RDONLY);
	while((rSize = read(fd, buf, BUFSIZE - 1)) > 0) {
		printf("%s", buf);
		memset(buf, EMPTY, BUFSIZE);
		// buf[rSize] = EMPTY;
		// buf[rSize + 1] = EMPTY;
		sum += rSize;
	}
	printf("file size : %d\n", sum);
	close(fd);

	return 0;
}