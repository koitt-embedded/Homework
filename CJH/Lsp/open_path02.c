#include <fcntl.h>
#include <stdio.h>

int main(int argc, char** argv) {
	char* path = "../Lsp/open_path_ex01.txt";
	char buf[64] = {0};
	read(open(path, O_CREAT | O_RDONLY), buf, 64);
	printf("%s\n", buf);

	return 0;
}