#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define			BUFSIZE			1024
#define			ERROR			-1
#define			TRUE			1

int strSize(char* str) {
	int i, len = 0;
	for(i=0; str[i]; i++) len += 1;
	return len;
}

void strCopyFromIndex(int index, char* raw, char* new) {
	int i, j = 0, size = strSize(raw);
	for(i=index; raw[i]; i++) *(new + j++) = raw[i];
}

int findFirstIndexToCompare(char* beChanged, char* toChange) {
	int i, j, flag = 0;
	for(i=0; beChanged[i]; i++) {
		for(j=0; toChange[j]; j++) {
			if(beChanged[i + j] != toChange[j]) flag = 1;
			if(flag) break;
		}
		if(!flag) return i;
		flag = 0;
	}
	return ERROR;
}

int findFirstIndexToCompareInPatterns(char* beChanged, char* toChange, char* patterns) {
	int i, j, k, flag = 0, pFlag = 0;
	char* tempToChange = toChange;
	// int sumSize = strSize(tempToChange) + strSize(patterns);
	for(i=0; beChanged[i]; i++) {
		for(j=0; toChange[j]; j++) {
			if(beChanged[i + j] != toChange[j]) {
				flag = 1;
				for(k=0; k<patterns[i]; k++) if(beChanged[i + j] == *(patterns + k)) pFlag = 1;
				if(pFlag) flag = 0;
			}
			if(flag) break;
		}
		if(!flag && beChanged[i + j] == beChanged[strSize(beChanged)]) return i;
		flag = 0;
	}
	return ERROR;
}

void makePattern(char* change, char* raw) {
	int i, j, size = strSize(change), index;
	int pattern[2] = {44, 46};
	for(i=0, index=0; i<size-1; i++) {
		change[index] = raw[i];
		for(j=1; j<rand()%5+1; j++) change[index + j] = pattern[rand() % 2];
		index += j;
	}
	change[index] = raw[i];
}

void openFile(char* read, char* write, int* fdin, int* fdout) {
	*fdin = open(read, O_RDONLY);
	*fdout = open(write, O_WRONLY | O_CREAT | O_TRUNC, 0644);
}

void newStr(char* raw, char* test, char* change, int startIndex) {
	int i, j;
	int testSize = strSize(test), changeSize = strSize(change);
	int subVal = testSize - changeSize;
	int maxSize = subVal >=0 ? testSize : changeSize;
	// char temp[BUFSIZE]; // F
	char temp[BUFSIZE] = {0};
	strCopyFromIndex(startIndex + testSize, raw, &temp);
	int tempSize = strSize(temp);
	for(i=0; i<maxSize; i++) raw[startIndex + i] = change[i];
	for(j=0; j<tempSize; j++) raw[startIndex + i + j] = temp[j];
}

int overwriteMatchesP(int fdin, int fdout, char* test, char* change, char* patterns) {
	int nread, startIndex;
	char tempBuf[BUFSIZE] = {0}, newString[BUFSIZE] = {0};
	while((nread = read(fdin, tempBuf, BUFSIZE)) > 0) {
		int i = 0;
		while(TRUE) {
			startIndex = findFirstIndexToCompareInPatterns(tempBuf, test, patterns);
			char tempChange[BUFSIZE] = {0};
			strCopyFromIndex(0, change, &tempChange);
			makePattern(&tempChange, change);
			printf("%d\n", startIndex);
			if(startIndex != ERROR) newStr(&tempBuf, test, tempChange, startIndex);
			else break;
		}
		write(fdout, tempBuf, strSize(tempBuf));
	}
}

int main(int argc, char** argv) {
	int fdin, fdout;
	int bufSize = BUFSIZE;
	int hi, index;
	char buf[BUFSIZE];
	char* test = "FPGA";
	char* change = "DSP";
	char* patterns = ".,";
	srand(time(NULL));

	openFile("data dumy result.txt", "data dumy result 2.txt", &fdin, &fdout);
	overwriteMatchesP(fdin, fdout, test, change, patterns);

	return 0;
}