#include <stdio.h>
#include <stdlib.h>

#define	BLACK	0
#define RED	1

typedef struct _rb_tree rb_tree;
typedef struct _rb_node rb_node;

// RBT 노드
struct _rb_node
{
	int data;
	int color;

	rb_node *left;
	rb_node *right;
	rb_node *parent;
};

// RBT 틀
struct _rb_tree
{
	rb_node *root;
	rb_node *nil;
};

void rb_left_rot(rb_tree **tree, rb_node *x)
{
	rb_node *y;
	rb_node *nil = (*tree)->nil;

	y = x->right;
	x->right = y->left;

	if (y->left != nil)
		y->left->parent = x;

	y->parent = x->parent;

	if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	y->left = x;
	x->parent = y;
}

void rb_right_rot(rb_tree **tree, rb_node *y)
{
	rb_node *x;
	rb_node *nil = (*tree)->nil;

	x = y->left;
	y->left = x->right;

	if (nil != x->right)
		x->right->parent = y;

	x->parent = y->parent;

	if (y->parent->left == y)
		y->parent->left = x;
	else
		y->parent->right = x;

	x->right = y;
	y->parent = x;
}

/*
	생성한 노드가 rb_tree의 어디에 저장돼야 할지 찾고 해당 위치에 저장하는 함수
*/
// tree = RB 전체 트리, z = rb_tree_ins에 서 data를 저장하기 위해 새로 생성한 노드
void rb_tree_ins_helper(rb_tree **tree, rb_node *z)
{
	rb_node *x;
	rb_node *y;
	// nil 노드 참조할 임시 변수
	rb_node *nil = (*tree)->nil;

	// 새로 생성한 노드의 좌우측 링크 값에 nil 노드 설정
	z->left = z->right = nil;
	// y는 RB 트리의 루트
	y = (*tree)->root;
	// x는 RB 트리 루트의 좌측 (더미 노드)
	x = (*tree)->root->left;

	// 다음 값이 있으면
	while (x != nil)
	{
		// 루트를 다음 값으로 갱신(그곳으로 옮겨감)
		y = x;

		// 트리의 기존 노드의 data 값이 저장될 data 값보다 크다면
		if (x->data > z->data)
			// 저장될 노드가 x보다 좌측 서브 트리에 저장돼야 한다.
			x = x->left;
		// 저장될 data 값이 크다면
		else
			// 저장될 노드가 x보다 우측 서브 트리에 저장돼야 한다.
			x = x->right;
	}

	// y는 nil인 x의 부모이므로 z가 y의 자식으로 들어감
	z->parent = y;

	// RB 트리의 루트와 y가 같거나 : 여기서 y -> left에 z를 넣는 이유는 위에서 더미 노드에 root -> left를 줬기 때문?
	// y(부모)의 data가 생성한 노드의 data보다 크면 y -> left에 생성한 노드(z) 대입
	if (((*tree)->root == y) || (y->data > z->data))
		y->left = z;
	// 아니라면 y -> right에 생성한 노드 주소 저장
	else
		y->right = z;
}

/*

*/
rb_node* rb_tree_ins(rb_tree **tree, int data)
{

	rb_node *y;
	rb_node *x;
	rb_node *tmp;

	// rb_node를 하나 생성하고 x에 참조케 함
	x = (rb_node *)malloc(sizeof(rb_node));
	// 생성한 노드에 입력받은 data를 저장
	x->data = data;

	// 생성한 노드 x를 트리에 저장하는 함수 호출
	rb_tree_ins_helper(tree, x);

	// 
	tmp = x;
	// 생성한 노드의 색은 빨간색
	x->color = RED;

	// 생성한 노드의 부모가 빨간색이라면 이벤트 발생(색 변환 또는 회전)
	while (x->parent->color)
	{
		// x의 부모가 할아버지의 왼쪽 노드라면
		if (x->parent == x->parent->parent->left)
		{
			// y는 x의 삼촌이고 부모의 반대쪽 노드 주소를 대입.
			y = x->parent->parent->right;

			// 삼촌이 빨간색이라면
			if (y->color)
			{
				// 색변환

				// 부모를 검은색으로 바꾸고
				x->parent->color = BLACK;
				// 삼촌도 검은색으로 바꾸고
				y->color = BLACK;
				// 할아버지의 색을 빨간색으로
				x->parent->parent->color = RED;
				// 체크를 위해 x를 x의 할아버지로 바꿈
				x = x->parent->parent;
			}
			// 
			else
			{
				if (x->parent->right == x)
				{
					x = x->parent;
					rb_left_rot(tree, x);
				}

				x->parent->color = BLACK;
				x->parent->parent->color = RED;

				rb_right_rot(tree, x->parent->parent);
			}
		}
		else
		{
			y = x->parent->parent->left;

			if (y->color)
			{
				x->parent->color = BLACK;
				y->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
			}
			else
			{
				if (x->parent->left == x)
				{
					x = x->parent;

					rb_right_rot(tree, x);
				}

				x->parent->color = BLACK;
				x->parent->parent->color = RED;

				rb_left_rot(tree, x->parent->parent);
			}
		}
	}

	(*tree)->root->left->color = BLACK;

	return tmp;
}

/*
	rb_node를 하나 만들고, data 0, color BLACK인 nil 노드로써 사용. 이 노드가 가리킬 수 있는 모든 포인터에는 자신(nil)을 참조
	rb_tree를 하나 만들고 nil 멤버 변수에 nil 역할로 만든 노드를 참조케 함
	rb_tree의 root에 할당 할 값을 하나 할당하고 초기화 함(가리키는 값 nil 노드, color BLACK, data 0)
*/
rb_tree* rb_tree_create(void)
{
	// 생성한 rbtree를 참조할 변수
	rb_tree *rbtree;
	// nil 노드와 root 노드 초기화 도와줄 임시 변수
	rb_node *tmp;

	// rbtree 데이터 생성, 할당 및 rbtree 변수가 가리키게 함
	rbtree = (rb_tree *)malloc(sizeof(rb_tree));

	// tmp와 rbtree의 nil에 rb_node(nil 노드) 생성 및 할당하여 가리키게 함
	tmp = rbtree->nil = (rb_node *)malloc(sizeof(rb_node));
	// nil 노드를 가리키는 tmp의 parent, left, right를 모두 nil 노드를 가리키게 함(모두 nil 노드를 가지고 있는 것)
	tmp->parent = tmp->left = tmp->right = tmp;
	// nil 노드의 색은 검정
	tmp->color = BLACK;
	// nil 노드의 data는 0
	tmp->data = 0;

	// root 역할의 rb_node를 생성 및 할당하고 tmp와 rbtree의 root가 가리키게 함
	tmp = rbtree->root = (rb_node *)malloc(sizeof(rb_node));
	// 생성한 root 노드의 parent, left, right에 nil node를 가리키게 함(세 노드가 nil node를 가지고 있음)
	tmp->parent = tmp->left = tmp->right = rbtree->nil;
	// root 노드의 색은 검정
	tmp->color = BLACK;
	// root 노드의 data는 0
	tmp->data = 0;

	// 생성한 트리 반환
	return rbtree;
}

void rb_tree_inorder_print(rb_tree *tree, rb_node *x)
{
	rb_node *nil = tree->nil;
	rb_node *root = tree->root;

	if (x != tree->nil)
	{
		rb_tree_inorder_print(tree, x->left);

		printf("Data = %4i ", x->data);
		printf("Left Data = ");

		if (x->left == nil)
			printf("NULL ");
		else
			printf("%4i ", x->left->data);

		printf("Right Data = ");

		if (x->right == nil)
			printf("NULL ");
		else
			printf("%4i ", x->right->data);

		printf("Parent Data = ");

		if (x->parent == root)
			printf("NULL ");
		else
			printf("%4i ", x->parent->data);

		printf("Color = %4i\n", x->color);

		rb_tree_inorder_print(tree, x->right);
	}
}

void rb_tree_print(rb_tree *tree)
{
	rb_tree_inorder_print(tree, tree->root->left);
}

int data_test(int num1, int num2)
{
	if (num1 > num2)
		return 1;
	else if (num1 < num2)
		return -1;
	else
		return 0;
}

rb_node *rb_tree_find(rb_tree *tree, int data)
{
	int tmp;

	rb_node *x = tree->root->left;
	rb_node *nil = tree->nil;

	if (x == nil)
		return 0;

	tmp = data_test(x->data, data);

	while (tmp != 0)
	{
		if (x->data > data)
			x = x->left;
		else
			x = x->right;

		if (x == nil)
			return 0;

		tmp = data_test(x->data, data);
	}

	return x;
}

rb_node *rb_tree_successor(rb_tree *tree, rb_node *x)
{
	rb_node *y;
	rb_node *nil = tree->nil;
	rb_node *root = tree->root;

	if (nil != (y = x->right))
	{
		while (y->left != nil)
			y = y->left;
		return y;
	}
	else
	{
		y = x->parent;

		while (y->right == x)
		{
			x = y;
			y = y->parent;
		}

		if (y == root)
			return nil;

		return y;
	}
}

void rb_tree_delete_fixup(rb_tree *tree, rb_node *x)
{
	rb_node *root = tree->root->left;
	rb_node *w;

	while ((!x->color) && (root != x))
	{
		if (x->parent->left == x)
		{
			w = x->parent->right;

			if (w->color)
			{
				w->color = BLACK;
				x->parent->color = RED;
				rb_left_rot(&tree, x->parent);
				w = x->parent->right;
			}

			if ((!w->right->color) && (!w->left->color))
			{
				w->color = RED;
				x = x->parent;
			}
			else
			{
				if (!w->right->color)
				{
					w->left->color = BLACK;
					w->color = RED;
					rb_right_rot(&tree, w);
					w = x->parent->right;
				}

				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				rb_left_rot(&tree, x->parent);
				x = root;
			}
		}
		else
		{
			w = x->parent->left;

			if (w->color)
			{
				w->color = BLACK;
				x->parent->color = 1;
				rb_right_rot(&tree, x->parent);
				w = x->parent->left;
			}

			if ((!w->right->color) && (!w->left->color))
			{
				w->color = RED;
				x = x->parent;
			}
			else
			{
				if (!w->left->color)
				{
					w->right->color = BLACK;
					w->color = RED;
					rb_left_rot(&tree, w);
					w = x->parent->left;
				}

				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				rb_right_rot(&tree, x->parent);
				x = root;
			}
		}
	}

	x->color = BLACK;
}

void rb_tree_delete(rb_tree *tree, rb_node *z)
{
	rb_node *y;
	rb_node *x;
	rb_node *nil = tree->nil;
	rb_node *root = tree->root;

	y = ((z->left == nil) || (z->right == nil)) ? z : rb_tree_successor(tree, z);
	x = (y->left == nil) ? y->right : y->left;

	if (root == (x->parent = y->parent))
		root->left = x;
	else
	{
		if (y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;
	}
	if (y != z)
	{
		if (!(y->color))
			rb_tree_delete_fixup(tree, x);

		y->left = z->left;
		y->right = z->right;
		y->parent = z->parent;
		y->color = z->color;
		z->left->parent = z->right->parent = y;

		if (z->parent->left == z)
			z->parent->left = y;
		else
			z->parent->right = y;

		free(z);
	}
	else
	{
		if (!(y->color))
			rb_tree_delete_fixup(tree, x);

		free(y);
	}
}

// 메인
int main(void)
{
	int i;
	int data[20] = { 3, 7, 10, 12, 14, 15, 16, 17, 19, 20, 21, 23, 26, 28, 30, 35, 38, 39, 41, 47 };

	// rb_tree 참조 변수
	rb_tree *rbtree = NULL;
	/// 트리에 특정 값 찾을 때 그 값을 갖고 있는 노드를 반환 받을 변수
	rb_node *find = NULL;

	// rb_tree 참조 변수에 생성한 re_tree를 참조케 함
	rbtree = rb_tree_create();

	/*
	   for (i = 1; i < 8; i++)
	   RBTree_ins(&rbtree, i);
	 */


	for (i = 0; i < 20; i++) rb_tree_ins(&rbtree, data[i]);

	rb_tree_print(rbtree);

	find = rb_tree_find(rbtree, 3);

	if (find)
		printf("Get Data at 0x%x\n", find);
	else
		printf("No Data in rb_tree\n");

	rb_tree_delete(rbtree, find);

	rb_tree_print(rbtree);

	return 0;
}