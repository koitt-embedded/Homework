#include <stdio.h>
#include <malloc.h>
#include <stdio.h>

#define LL 1
#define RR 2
#define LR 3
#define RL 4

#define _EMPTY 	0;

typedef struct NODE{
	int data;
	int lev;
	struct NODE*	l;
	struct NODE* 	r;
}NODE;

NODE *get_node();
void avl_ins();
int lev_modify();
int lev_chk();
NODE *rotation();
int rot_chk();
NODE *rot_ll();
NODE *rot_rr();
NODE *rot_lr();
NODE *rot_rl();




NODE *get_node(int data){
	NODE *node;
	node = (NODE *) malloc(sizeof(NODE));
	node -> data = data;
	node -> r = NULL;
	node -> l = NULL;
	node -> lev = 1;
	return node;
}
 
void avl_ins(NODE **root, int data)
{

	if(!(*root))
	{
		*root = get_node(data);
		return;
	}
	if((*root)->data > data)
		avl_ins(&(*root)->l, data);
	else
		avl_ins(&(*root)->r, data);
	printf("data = %d\n", (*root)->data);
	(*root)->lev = lev_modify((*root));
	printf("root lev = %d\n", (*root)->lev);
	int abs= lev_chk((*root));
	printf("abs = %d\n", abs);
	abs = (abs > 0) ? abs : -abs;
	if(abs > 1)
		(*root) = rotation((*root), rot_chk(*root, data));
}


int lev_modify(NODE *root)
{
	int l, r;

	r = root->r > 0 ? root->r->lev : 0;
	l = root->l > 0 ? root->l->lev : 0;

	if(l > r)
		return l + 1;

	return r + 1;
}

int lev_chk(NODE *root)
{
	int r = root->r > 0 ? root->r->lev : 0;
	int l = root->l > 0 ? root->l->lev : 0;
	return r - l;
}

int rot_chk(NODE *root, int data)
{
	if(lev_chk(root) < 0)
	{
		if(lev_chk(root->l) > -1 && root->l->data < data)
			return LR;
		return LL;
	}
	else
	{
		if(lev_chk(root->r) < 1 && root->r->data > data)
			return RL;
		return RR;
	}
	return 0;
}

NODE *rotation(NODE *root, int rot_chk)
{
	printf("rotation start\n");
	switch(rot_chk)
	{
		case 1:
			printf("1\n");
			root = rot_ll(root);
			break;
		case 2:
			printf("2\n");
			root = rot_rr(root);
			break;
		case 3:
			printf("3\n");
			root = rot_lr(root);
			break;
		case 4:
			printf("4\n");
			root = rot_rl(root);
			break;
	}
}

NODE *rot_ll(NODE *parent)
{
	printf("%p\n", parent);
	printf("11\n");
	NODE *child = parent->l;
	printf("111\n");
	parent->l = child->r;
	printf("1111\n");
	child->r = parent;
	return child;
}

NODE *rot_rr(NODE *parent)
{
	NODE *child = parent->r;
	parent->r = child->l;
	child->r = parent;
	return child;
}

NODE *rot_lr(NODE *parent)
{
	NODE *child = parent->l;
	parent->l = rot_ll(child);
	return rot_rr(parent);
}

NODE *rot_rl(NODE *parent)
{
	NODE *child = parent->l;
	parent->r = rot_ll(child);
	return rot_rr(parent);
}


void print_tree(NODE *tmp)
{
	if(!tmp) return;
	printf("%d ",tmp->data);
	print_tree(tmp->l);
	print_tree(tmp->r);
}

int main(void)
{
	NODE *top = 0;
	int i;
	int data[12] = {50,20,10,40,30,35,80,90,100,60,70,65};

	for(i = 0; i < 12; i++)
	{
		avl_ins(&top, data[i]);
	}
	print_tree(top);
	printf("\n");
}

