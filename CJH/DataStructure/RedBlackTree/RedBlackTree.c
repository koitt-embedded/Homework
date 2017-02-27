#include <stdio.h>
#include <stdlib.h>
#include "RedBlackTree.h"

Node* rotateRR(Node* node) {
	printf("RR\n");
	Node* child = node -> rightLink;
	Node temp = *node;
	*node = *(node -> rightLink);
	*child = temp;
	child -> rightLink = node -> leftLink;
	node -> leftLink = child;
	return node;
}

Node* rotateLL(Node* node) {
	printf("LL\n");
	Node* child = node -> leftLink;
	Node temp = *node;
	*node = *(node -> leftLink);
	*child = temp;
	child -> leftLink = node -> rightLink;
	node -> rightLink = child;
	return node;
}

Node* rotateRL(Node* node) {
	printf("RL\n");
	rotateLL(node -> rightLink);
	return rotateRR(node);
}

Node* rotateLR(Node* node) {
	printf("LR\n");
	rotateRR(node -> leftLink);
	return rotateLL(node);
}

// 0 RED
// 1 BLACK

void compareColor(Node** stack, int size) {
	printf("stack size : %d\n", size);
	for(int j=0; j<=size; j ++) printf("stack[%d] color is %d\n", j, stack[j] -> color);
	int i = 0;
	Node* p = NULL;
	Node* u = NULL;
	while(size - i > 0) {
		printf("size - i >= 0\n");
		printf("size ::: %d\n", stack[size - i] -> data);
		printf("size 2 ::: %d\n", stack[size - (i + 1)] -> data);
		if(!stack[size - (i + 1)] -> color && !stack[size - i] -> color) {
			if(stack[size - (i + 2)] -> leftLink == stack[size - (i + 1)]) {
				printf("leftLink ==\n");
				p = stack[size - (i + 2)] -> leftLink;
				u = stack[size - (i + 2)] -> rightLink;
			}else if(stack[size - (i + 2)] -> rightLink == stack[size - (i + 1)]) {
				printf("rightLink ==\n");
				p = stack[size - (i + 2)] -> rightLink;
				u = stack[size - (i + 2)] -> leftLink;
			}
			if(u && !u -> color) {
				printf("uncle is exist and color red\n");

				printf("root : %d\n", stack[size - (i + 2)] -> leftLink -> color);
				printf("root : %d\n", stack[size - (i + 2)] -> rightLink -> color);
				printf("root : %d\n", stack[size - (i + 2)] -> color);
				stack[size - (i + 2)] -> leftLink -> color = BLACK;
				stack[size - (i + 2)] -> rightLink -> color = BLACK;
				stack[size - (i + 2)] -> color = !(size - (i + 2)) ? BLACK : RED;
				i ++;
				printf("root : %d\n", stack[size - (i + 2)] -> leftLink -> color);
				printf("root : %d\n", stack[size - (i + 2)] -> rightLink -> color);
				printf("root : %d\n", stack[size - (i + 2)] -> color);
			}else {
				Node* tempP = NULL;
				printf("uncle is not exist\n");
				if(stack[size + (i - 2)] -> leftLink == p) {
					if(p -> leftLink == stack[size + i]) tempP = rotateLL(stack[size - (i + 2)]);
					else tempP = rotateLR(stack[size - (i + 2)]);
				}else {
					if(p -> rightLink == stack[size - i]) tempP = rotateRR(stack[size - (i + 2)]);
					else tempP = rotateRL(stack[size - (i + 2)]);
				}
				printf("rotattion root : %d\n", tempP -> color);
				printf("rotattion root : %d\n", tempP -> leftLink -> color);
				printf("rotattion root : %d\n", tempP -> rightLink -> color);
				tempP -> color = BLACK;
				tempP -> leftLink -> color = RED;
				tempP -> rightLink -> color = RED;
				printf("rotattion root : %d\n", tempP -> color);
				printf("rotattion root : %d\n", tempP -> leftLink -> color);
				printf("rotattion root : %d\n", tempP -> rightLink -> color);
				i += 2;
				stack[size - i] = tempP;
				continue ;
			}
		}else {
			printf("break;\n");
			break;
		}
		i ++;
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
				printf("data : %d\t cur data > node-data (node data : %d)\n", data, curNode -> data);
				if(curNode -> rightLink) curNode = curNode -> rightLink;
				else {
					stack[++ i] = insertNode(&curNode -> rightLink, data);
					compareColor(stack, i);
					break ;
				}
			}else if(data < curNode -> data) {
				printf("data : %d\t cur data < node-data (node data : %d)\n", data, curNode -> data);
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
	printTree(mRoot);
}

int findMaxAtLeftSubTree(Node** stack, int* mSize, int* color) {
	int i = 0, data, size = *mSize;
	while(TRUE) {
		if(stack[size + i] -> rightLink) {
			stack[size + (i + 1)] = stack[size + i] -> rightLink;
			i ++;
			continue ;
		}else if(!i) stack[size + (i - 1)] -> leftLink = stack[size + i] -> leftLink ? stack[size + i] -> leftLink : NULL;
		else stack[size + (i - 1)] -> rightLink = stack[size + i] -> leftLink ? stack[size + i] -> leftLink : NULL;
		data = stack[size + i] -> data;
		*color = stack[size + i] -> color;
		free(stack[size + i]);
		stack[size + i] = NULL;
		*mSize += i - 1;
		return data;
	}
}

int findMaxAtRightSubTree(Node** stack, int* mSize, int* color) {
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
		*color = stack[size + i] -> color;
		free(stack[size + i]);
		stack[size + i] = NULL;
		*mSize += i - 1;
		return data;
	}
}

void treeDel(int data, Node** mRoot) {
	if(*mRoot) {
		Node* stack[100];
		Node* p = NULL;
		Node* node = *mRoot;
		Node* tempP;
		int i = 0, j = 0, newData, color;
		while(TRUE) {
			stack[i] = node;
			if(data > node -> data && node -> rightLink) node = node -> rightLink;
			else if(data < node -> data && node -> leftLink) node = node -> leftLink;
			else if(data == node -> data){
				p = stack[i - 1];
				if(node -> leftLink) {
					stack[++ i] = node -> leftLink;
					newData = findMaxAtLeftSubTree(stack, &i, &color);
				}else if(node -> rightLink) {
					stack[++ i] = node -> rightLink;
					newData = findMaxAtRightSubTree(stack, &i, &color);
				}else {
					if(stack[i - 1] -> leftLink == node) stack[i - 1] -> leftLink = NULL;
					else stack[i - 1] -> rightLink = NULL;
					stack[i] = NULL;
					i --;
					free(node);
					compareColor(stack, i);
					break ;
				}
				node -> data = newData;
				if(node -> color && !color) node -> color = BLACK;
				else if(node -> color && color) {
					Node* b = NULL;
					if(p -> leftLink == node) {
						b = p -> rightLink;
						b -> color = BLACK;
						node -> color = RED;
						rotateLL(p);
						if(!(p -> leftLink -> color) || !(p -> rightLink -> color)) p -> color = BLACK;
					}else {
						b = p -> leftLink;
						b -> color = BLACK;
						node -> color = RED;
						rotateRR(p);
						if(!(p -> leftLink -> color) || !(p -> rightLink -> color)) p -> color = BLACK;
					}
					else b = p -> leftLink;
					if(!b -> color) {
						b -> color = BLACK;
						node -> color = RED;
						ro
					}
				}
				compareColor(stack, i);
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
		printf("node COLOR : %d\t", root -> color);
		printf("node data : %d\n", root -> data);
		printf("node LEFT data : %d\t", root -> leftLink ? root -> leftLink -> data : -1);
		printf("node RIGHT data  %d\n\n\n\n", root -> rightLink ? root -> rightLink -> data : -1);
		if(root -> leftLink) printTree(&root -> leftLink);
		if(root -> rightLink) printTree(&root -> rightLink);
	}
}