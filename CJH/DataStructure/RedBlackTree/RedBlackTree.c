#include <stdio.h>
#include <stdlib.h>
#include "RedBlackTree.h"

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

// 0 RED
// 1 BLACK

void compareColor(Node** stack, int size) {
	int i = 0;
	Node* p = NULL, u = NULL;
	while(TRUE) {
		if(!stack[size + (i - 1)] -> color) {
			if(stack[size + (i - 2)] -> leftLink == stack[size + (i - 1)]) {
				p = stack[size + (i - 2)] -> leftLink;
				u = stack[size + (i - 2)] -> rightLink;
			}else if(stack[size + (i - 2)] -> rightLink == stack[size + (i - 1)]) {
				p = stack[size + (i - 2)] -> rightLink;
				u = stack[size + (i - 2)] -> leftLink;
			}
			if(u && !c -> color) {
				stack[size + (i - 2)] -> leftLink -> color = BLACK;
				stack[size + (i - 2)] -> rightLink -> color = BLACK;
				stack[size + (i - 2)] = !(size + (i - 2)) ? BLACK : RED;
			}else {
				if(stack[size + (i - 2)] -> leftLink == p) {
					if(p -> leftLink == stack[size + i]) rotateLL(stack[size + (i - 2)]);
					else rotateLR(stack[size + (i - 2)]);
				}else {
					if(p -> rightLink == stack[size + i]) rotateRR(stack[size + (i - 2)]);
					else rotateRL(stack[size + (i - 2)]);
				}
			}
		}
	}
}

Node* getNode() {
	Node* temp = (Node *)malloc(sizeof(Node));
	temp -> leftLink = NULL;
	temp -> rightLink = NULL;
	temp -> color = RED;
	return temp;
}

Node* insertNode(Node** pLink, int data) {
	*pLink = getNode();
	(**pLink).data = data;
	return *pLink;
}

void treeIns(int data, Node** mRoot) {
	if(*mRoot) {
		Node* stack[100];
		Node* curNode = *mRoot;
		int i = 0;
		while(TRUE) {
			stack[i] = curNode;
			Node* tempP;
			if(data > curNode -> data) {
				if(curNode -> rightLink) curNode = curNode -> rightLink;
				else {
					stack[++ i] = insertNode(&curNode -> rightLink, data);
					compareColor(stack, i);
					break ;
				}
			}else if(data < curNode -> data) {
				if(curNode -> leftLink) curNode = curNode -> leftLink;
				else {
					stack[++ i] = insertNode(&curNode -> leftLink, data);
					compareColor(stack, i);
					break ;
				}
			}else break ;
			i ++;
		}
	}else {
		insertNode(mRoot, data);
		(*mRoot) -> color = BLACK;
	}
}

int findMaxAtLeftSubTree(Node** stack, int* mSize) {
	int i = 0, data, size = *mSize;
	while(TRUE) {
		if(stack[size + i] -> rightLink) {
			stack[size + (i + 1)] = stack[size + i] -> rightLink;
			i ++;
			continue ;
		}else if(!i) stack[size + (i - 1)] -> leftLink = stack[size + i] -> leftLink ? stack[size + i] -> leftLink : NULL;
		else stack[size + (i - 1)] -> rightLink = stack[size + i] -> leftLink ? stack[size + i] -> leftLink : NULL;
		data = stack[size + i] -> data;
		free(stack[size + i]);
		stack[size + i] = NULL;
		*mSize += i - 1;
		return data;
	}
}

int findMaxAtRightSubTree(Node** stack, int* mSize) {
	int i = 0, data, size = *mSize;
	while(TRUE) {
		if(stack[size + i] -> leftLink) {
			stack[size + (i + 1)] = stack[size + i] -> leftLink;
			i ++;
			continue ;
		}
		else if(!i) stack[size + (i - 1)] -> rightLink = stack[size + i] -> rightLink ? stack[size + i] -> rightLink : NULL;
		else stack[size + (i - 1)] -> leftLink = stack[size + i] -> rightLink ? stack[size + i] -> rightLink : NULL;
		data = stack[size + i] -> data;
		free(stack[size + i]);
		stack[size + i] = NULL;
		*mSize += i - 1;
		return data;
	}
}

void treeDel(int data, Node** mRoot) {
	if(*mRoot) {
		Node* stack[100];
		Node* node = *mRoot;
		Node* tempP;
		int i = 0, j = 0, newData;
		while(TRUE) {
			stack[i] = node;
			if(data > node -> data && node -> rightLink) node = node -> rightLink;
			else if(data < node -> data && node -> leftLink) node = node -> leftLink;
			else if(data == node -> data){
				if(node -> leftLink) {
					stack[++ i] = node -> leftLink;
					newData = findMaxAtLeftSubTree(stack, &i);
				}else if(node -> rightLink) {
					stack[++ i] = node -> rightLink;
					newData = findMaxAtRightSubTree(stack, &i);
				}else {
					if(stack[i - 1] -> leftLink == node) stack[i - 1] -> leftLink = NULL;
					else stack[i - 1] -> rightLink = NULL;
					stack[i] = NULL;
					i --;
					free(node);
					for(j = i; j>=0; j --) lvModify(stack[j]);
					tempP = renewLv(stack, i);
					if(tempP) rotate(tempP);
					break ;
				}
				node -> data = newData;
				for(j = i; j>=0; j --) lvModify(stack[j]);
				tempP = renewLv(stack, i);
				if(tempP) rotate(tempP);
				break ;
			}else break ;
			i ++;
		}
	}
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