#include <stdio.h>
#include <stdlib.h>
#include "AVLTree.c"

int main(int argc, char** argv) {
	Node* root = NULL;
	int data[] = {50, 20, 10, 40, 30, 35, 80, 90, 100, 60, 70, 65};
	// int data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	// int data[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
	int i;
	for(i=0; i<sizeof(data) / sizeof(int); i++) treeIns(data[i], &root);
	printTree(&root);
	return 0;
}