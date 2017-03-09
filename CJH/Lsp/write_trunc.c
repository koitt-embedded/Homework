#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define		BUFSIZE		8
#define		EMPTY		0

int main(int argc, char** argv) {
	int rFd, wFd, rSize, wSize, sum = 0;
	char buf[BUFSIZE] = {EMPTY};
	rFd = open("./read2.txt", O_RDONLY);
	wFd = open("./write.txt", O_WRONLY | O_TRUNC, 0644);
	while((rSize = read(rFd, buf, BUFSIZE - 1)) > EMPTY) {
		wSize = write(wFd, buf, rSize);
		memset(buf, EMPTY, BUFSIZE);
		sum += wSize;
	}
	close(rFd);
	close(wFd);
	return 0;
}