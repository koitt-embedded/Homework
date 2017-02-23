/*
	AVL Tree의 조건과 구현
	AVL Tree는 해당 노드의 좌우측 서브 트리 높이의 차가 1보다 작거나 같아야 한다.
	만약 좌우 서브트리 높이의 차이가 2 이상 벌어지면 AVL Tree가 아니므로 조정이 필요하다.

	트리의 모든 노드들은 lv이라는 자신 노드의 양 서브트리 높이의 차를 갖고 있는다.
	트리의 삽입 또는 삭제 연산 시 삽입, 또는 삭제를 위해 거쳐간 특정 노드들(삽입, 삭제 되는 노드의 조상 노드들)
	만 변화가 일어난다.
	따라서 노드의 삽입 시 해당 노드가 거치는 모든 구간의 조상들을 임시 저장소에 담고
	삽입, 삭제 후 해당 조상들의 모든 lv 값을 조정한다.
	lv 값 조정 시 역순으로 조상들의 조상으로 거슬러 올라가므로, 저장소의 최초 노드부터 시작하여 최신 값으로 조정하여 올라가게 된다.
	이때 그 다음 노드는 왼쪽, 오른쪽 서브트리로 최신값으로 조정된 노드의 lv와 삽입, 삭제에 관련되지 않은 노드의 lv를 받게 되므로
	두 lv의 차가 곧 최신 lv 값임을 알 수 있다.
*/

#include <stdio.h>
#include <stdlib.h>

#define			TRUE		1

struct mNode {
	int data;
	struct mNode* leftLink;
	struct mNode* rightLink;
	int lv;
};
typedef struct mNode Node;

Node* getNode();
void treeIns(int data, Node** root);
void printTree(Node** root);

void insertNode(Node** pLink, int data) {
	*pLink = getNode();
	(**pLink).data = data;
}

Node* lvModify(Node** stack, int limit, int rev) {
	Node* recentlyUnbalanceNode = NULL;
	int i = 0;

	for(limit; limit>=0; limit--, i++) {
		printf("stack[%d] -> data : %d\n", i, stack[limit] -> data);
		printf("stack[%d] -> left : %p\n", i, stack[limit] -> leftLink);
		printf("stack[%d] -> right : %p\n", i, stack[limit] -> rightLink);
		stack[limit] -> lv = i + 1;
		int res = (stack[limit] -> leftLink ? stack[limit] -> leftLink -> lv : 0)
			- (stack[limit] -> rightLink ? stack[limit] -> rightLink -> lv : 0)
			+ rev;
		printf("res : %d\n", res);
		if((res > 1 || res < -1) && !(recentlyUnbalanceNode)) recentlyUnbalanceNode = i > 0 ? stack[i-1] : stack[i];
		printf("height %d\n", stack[i] -> lv);
		// (*stack[i]) -> lv =
		// 	((*stack[i]) -> leftLink ? (*stack[i]) -> leftLink -> lv : 0)
		// 	- ((*stack[i]) -> rightLink ? (*stack[i]) -> rightLink -> lv : 0);
		// if(*stack[i] -> lv > 1 && !(recentlyUnbalanceNode)) recentlyUnbalanceNode = i > 0 ? *stack[i-1] : *stack[i];
	}
	printf("recently %p\n", recentlyUnbalanceNode);
	return recentlyUnbalanceNode;
}

int nullToZero(Node* node) {
	return node ? node -> lv : 0;
}

void rotateRR(Node* node) {
	Node* cur = node -> rightLink;
	Node temp = *node;
	*node = *cur;
	*cur = temp;

	printf("\nnode %p\n", node);
	printf("node l %p\n", node -> leftLink);
	printf("node r %p\n\n", node -> rightLink);

	printf("cur %p\n", cur);
	printf("cur l %p\n", cur -> leftLink);
	printf("cur r %p\n\n", cur -> rightLink);

	printf("node -right %p\n", node -> rightLink);
	printf("node -right l %p\n", node -> rightLink -> leftLink);
	printf("node -right r %p\n\n", node -> rightLink -> rightLink);

	// printf("node - right %d\n", node -> rightLink -> data);
	// node -> leftLink = cur;
	// cur -> rightLink = node -> rightLink;
	// printf("cur right leaf %d\n", cur -> rightLink -> data);

	// Node* right = NULL;
	// right = node -> rightLink;
	// node -> rightLink = right -> leftLink;
	// right -> leftLink = node;

	// node -> rightLink = node -> rightLink;
	// Node* temp = node -> rightLink;
	// node -> rightLink = node -> rightLink -> leftLink;
	// temp -> leftLink = node;
	// Node temp1 = NULL;
	// Node* temp2 = NULL;
	// printf("node1 : %d\n", node -> data);
	// temp1 = *node; // par 주소
	// printf("node2 : %d\n", temp1.data);
	// *node = *(node -> rightLink); // par 구조체에 par의 오른쪽 자식의 구조체 대입
	// printf("node222 : %d\n", temp1.data);
	// printf("node3 : %d\n", node -> data);
	// temp2 = node -> leftLink; // par의 오른쪽 자식의 왼쪽 link
	// printf("node4 : %d\n", temp2);
	// node -> leftLink = &temp1; // par의 오른쪽 자식의 left에 par 주소
	// printf("node5 : %d\n", node -> leftLink -> data);
	// temp1 -> rightLink = temp2; // par의 오른쪽 link에 par의 오른쪽 자식의 왼쪽 link

}

void rotateLL(Node* node) {

}

void rotateRL(Node* node) {

}

void rotateLR(Node* node) {

}

void rotate(Node* par, int rev) {
	// int jud = ((*par) -> leftLink ? (*par) -> leftLink -> lv : 0)
	// 			-  ((*par) -> leftLink ? (*par) -> rightLink -> lv : 0);
	int jud = nullToZero(par -> leftLink) - nullToZero(par -> rightLink) + rev;
	printf("jud %d \n", jud);
	if(jud > 0) {
		// Node* leftLink = (*par) -> leftLink;
		int temp = nullToZero(par -> leftLink -> leftLink) - nullToZero(par -> leftLink -> rightLink) + rev;
		if(temp > 0) rotateLL(par);
		else rotateLR(par);
	}else {
		int temp = nullToZero(par -> rightLink -> leftLink) - nullToZero(par -> rightLink -> rightLink) + rev;
		printf("temp%d\n", temp);
		if(temp > 0) rotateRL(par);
		else rotateRR(par);
	}
}

int main(int argc, char** argv) {
	Node* root = NULL;
	// int data[] = {50, 20, 10, 40, 30, 35, 80, 90, 100, 60, 70, 65};
	int data[] = {10, 20, 30};
	int i;
	for(i=0; i<3; i++) treeIns(data[i], &root);
	printTree(&root);
	return 0;
}

Node* getNode() {
	Node* temp = (Node *)malloc(sizeof(Node));
	temp -> leftLink = NULL;
	temp -> rightLink = NULL;
	temp -> lv = 0;
	return temp;
}

void treeIns(int data, Node** mRoot) {
	if(*mRoot) {
		int i = 0;
		Node* stack[100];
		Node* node = *mRoot;
 
		while(TRUE) {
		printf("-------------create node----------------\n");
		printf("----------data : %d--------------\n", data);
			stack[i] = node;
			Node* temp = NULL;
			if(data > node -> data) {
				if(node -> rightLink) {
					printf("here1\n");
					node = node -> rightLink;
				}else {
					printf("here2\n");
					insertNode(&node -> rightLink, data);
					printf("abc %d\n", stack[i] -> data);
					temp = lvModify(stack, i, -1);
					if(temp) rotate(temp, -1);
					return ;
				}
			}else if(data < node -> data) {
				if(node -> leftLink) {
					node = node -> leftLink;
				}else {
					insertNode(&node -> leftLink, data);
					temp = lvModify(stack, i, 1);
					if(temp) rotate(temp, 1);
					return ;
				}
			}
			else {
				printf("already exgist\n");
				return ;
			}
			i ++;
		}

		// if(root -> data > data) treeIns(data, &root -> leftLink);
		// else if(root -> data < data) treeIns(data, &root -> rightLink);
		// else printf("already exgist\n");
	}else {
		printf("-------------create node----------------\n");
		printf("----------data : %d--------------\n", data);
		insertNode(mRoot, data);
		printf("root tree ::: %p\n", *mRoot);
		printf("\n\n\n\n");
	}
}

void printTree(Node** mRoot) {
	Node* root = *mRoot;
	if(!root) return ;
	else {
		printf("node LV : %d\t", root -> lv);
		printf("node data : %d\t", root -> data);
		printf("node ADDR : %p\t", root);
		printf("node LEFT link : %p\t", root -> leftLink);
		printf("node RIGHT link  %p\n", root -> rightLink);
		if(root -> leftLink) printTree(&root -> leftLink);
		if(root -> rightLink) printTree(&root -> rightLink);
	}
}