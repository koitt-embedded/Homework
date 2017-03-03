#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct mNode {
	int data;
	struct mNode* link;
};
typedef struct mNode Node;

void push(int data, Node** root);
void display(int data);
int pop(Node** root);
Node* getNode(void);

int main(int argc, char** argv) {
	Node* root = NULL;
	int i;
	srand(time(NULL));
	for(i=0; i<20; i++) push(rand() % 100 + 1, &root);
	putchar('\n');
	for(i=0; i<21; i++) display(pop(&root));
	return 0;
}

void push(int data, Node** root) {
	Node* post = *root;
	*root = getNode();
	(*root) -> link = post;
	(*root) -> data = data;
	display((*root) -> data);
}

Node* getNode(void) {
	return (Node *)calloc(1, sizeof(Node));
}

int pop(Node** root) {
	Node* temp = *root;
	int data;
	if((*root) -> link) data = (*root) -> data;
	else return -1;
	*root = (*root) -> link;
	free(temp);
	return data;
}

void display(int data) {
	printf("Node Data : %d\n", data);
}