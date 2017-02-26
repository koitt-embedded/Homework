#include <stdio.h>
#include <stdlib.h>
#include "AVLTreeIns.h"

Node* rotateRR(Node* node) {
	Node* child = node -> rightLink;
	Node temp = *node;
	*node = *(node -> rightLink);
	*child = temp;
	child -> rightLink = node -> leftLink;
	node -> leftLink = child;
	return node;
}

Node* rotateLL(Node* node) {
	Node* child = node -> leftLink;
	Node temp = *node;
	*node = *(node -> leftLink);
	*child = temp;
	child -> leftLink = node -> rightLink;
	node -> rightLink = child;
	return node;
}

Node* rotateRL(Node* node) {
	rotateLL(node -> rightLink);
	return rotateRR(node);
}

Node* rotateLR(Node* node) {
	rotateRR(node -> leftLink);
	return rotateLL(node);
}

void rotate(Node* node) {
	int res;
	Node* c;
	res = (node -> leftLink ? node -> leftLink -> lv + 1 : 0)
			- (node -> rightLink ? node -> rightLink -> lv + 1 : 0);
	if(res > 0) {
		c = node -> leftLink;
		res = (c -> leftLink ? c -> leftLink -> lv + 1 : 0)
			- (c -> rightLink ? c -> rightLink -> lv + 1 : 0);
		if(res > 0) node = rotateLL(node);
		else node = rotateLR(node);
	}else {
		c = node -> rightLink;
		res = (c -> leftLink ? c -> leftLink -> lv + 1 : 0)
			- (c -> rightLink ? c -> rightLink -> lv + 1 : 0);
		if(res > 0) node = rotateRL(node);
		else node = rotateRR(node);
	}
	lvModify(node -> leftLink);
	lvModify(node -> rightLink);
	lvModify(node);
}

Node* renewLv(Node** stack, int size) {
	Node* p = NULL;
	int i = 0, dir;
	stack[size] -> lv = i;
	i ++; size --;
	for(size; size>=0; size--, i++) {
		int res = (stack[size] -> leftLink ? stack[size] -> leftLink -> lv + 1 : 0)
			- (stack[size] -> rightLink ? stack[size] -> rightLink -> lv + 1 : 0);
		if((res > 1 || res < -1) && !(p)) p = stack[size];
		if(i < stack[size] -> lv) break ;
		stack[size] -> lv = i;
	}
	return p;
}

void lvModify(Node* node) {
	int left = node -> leftLink ? node -> leftLink -> lv + 1 : 0;
	int right = node -> rightLink ? node -> rightLink -> lv + 1 : 0;
	if(left > right) node -> lv = left;
	else node -> lv = right;
}

Node* getNode() {
	Node* temp = (Node *)malloc(sizeof(Node));
	temp -> leftLink = NULL;
	temp -> rightLink = NULL;
	temp -> lv = 0;
	return temp;
}

Node* insertNode(Node** pLink, int data) {
	*pLink = getNode();
	(**pLink).data = data;
	return *pLink;
}

void treeIns(int data, Node** mRoot) {
	Node* stack[100];
	if(*mRoot) {
		int i = 0;
		Node* curNode = *mRoot;
		while(TRUE) {
			stack[i] = curNode;
			Node* tempP;
			if(data > curNode -> data) {
				if(curNode -> rightLink) curNode = curNode -> rightLink;
				else {
					stack[++ i] = insertNode(&curNode -> rightLink, data);
					tempP = renewLv(stack, i);
					if(tempP) rotate(tempP);
					break ;
				}
			}else if(data < curNode -> data) {
				if(curNode -> leftLink) curNode = curNode -> leftLink;
				else {
					stack[++ i] = insertNode(&curNode -> leftLink, data);
					tempP = renewLv(stack, i);
					if(tempP) rotate(tempP);
					break ;
				}
			}else break ;
			i ++;
		}
	}else insertNode(mRoot, data);
}

void printTree(Node** mRoot) {
	Node* root = *mRoot;
	if(!root) return ;
	else {
		printf("node LV : %d\t", root -> lv);
		printf("node data : %d\n", root -> data);
		printf("node LEFT data : %d\t", root -> leftLink ? root -> leftLink -> data : -1);
		printf("node RIGHT data  %d\n\n\n\n", root -> rightLink ? root -> rightLink -> data : -1);
		if(root -> leftLink) printTree(&root -> leftLink);
		if(root -> rightLink) printTree(&root -> rightLink);
	}
}