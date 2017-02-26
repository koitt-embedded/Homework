#include <stdio.h>
#include <stdlib.h>
#include "AVLTreeDel.c"

int main(int argc, char** argv) {
	Node* root = NULL;
	int data[] = {50, 20, 10, 40, 30, 35, 80, 90, 100, 60, 70, 65};
	int delData[] = {10, 40, 100, 30, 60, 50, 80, 65, 70};
	int i;
	for(i=0; i<sizeof(data) / sizeof(int); i++)	 treeIns(data[i], &root);
	printTree(&root);
	printf("---------------------------------------------\n");
	for(i=0; i<sizeof(delData) / sizeof(int); i++) treeDel(delData[i], &root);
	printTree(&root);
	return 0;
}