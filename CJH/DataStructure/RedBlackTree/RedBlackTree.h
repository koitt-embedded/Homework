#ifndef _AVL_TREE
#define _AVL_TREE

#define			TRUE		1
#define			RED			0
#define			BLACK		1

struct mNode {
	int data;
	struct mNode* leftLink;
	struct mNode* rightLink;
	int color;
};
typedef struct mNode Node;

Node* rotateRR(Node* node);
Node* rotateLL(Node* node);
Node* rotateRL(Node* node);
Node* rotateLR(Node* node);
void rotate(Node* node);
void compareColor(Node** stack, int size);
Node* getNode();
Node* insertNode(Node** pLink, int data);
void treeIns(int data, Node** mRoot);
void printTree(Node** mRoot);
int findMaxAtLeftSubTree(Node** stack, int* size, int* color);
int findMaxAtRightSubTree(Node** stack, int* size, int* color);
void treeDel(int data, Node** mRoot);

#endif