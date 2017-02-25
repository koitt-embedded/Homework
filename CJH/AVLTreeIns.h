#ifndef _AVL_TREE
#define _AVL_TREE

#define			TRUE		1

struct mNode {
	int data;
	struct mNode* leftLink;
	struct mNode* rightLink;
	int lv;
};
typedef struct mNode Node;

Node* rotateRR(Node* node);
Node* rotateLL(Node* node);
Node* rotateRL(Node* node);
Node* rotateLR(Node* node);
void rotate(Node* node);
Node* renewLv(Node** stack, int size);
void lvModify(Node* node);
Node* getNode();
Node* insertNode(Node** pLink, int data);
void treeIns(int data, Node** mRoot);
void printTree(Node** mRoot);

#endif