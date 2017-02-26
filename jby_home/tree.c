#include <stdio.h>
#include <stdlib.h>

typedef struct t
{
	int data;
	struct t *l;
	struct t *r;
} tree;

tree *get_node(void)
{
	tree *tmp = (tree *)malloc(sizeof(tree));
	tmp->l = NULL;
	tmp->r = NULL;
	return tmp;
}

void tree_ins(tree **root, int data)
{
	if(!(*root))
	{
		*root = get_node();
		(*root)->data = data;
		return;
	}
	if((*root)->data > data)
		tree_ins(&(*root)->l, data);
	else
		tree_ins(&(*root)->r, data);
}

void print_tree(tree *root)
{
	if(root)
	{
		printf("data = %d\n", root->data);
		print_tree(root->l);
		print_tree(root->r);
	}
}

tree *chg_node(tree *root)
{
	tree *tmp;
	tmp = root;
	if(!root->r)
		root = root->l;
	else if(!root->l)
		root = root->r;
	free(tmp);
	return root;
}

tree *min_node(tree *root, int *data)
{
	if(root->l)
		root->l = min_node(root->l, data);
	else
	{
		*data = root->data;
		root = chg_node(root);
	}
	return root;
}

void tree_del(tree **root, int data)
{
	int num;
	tree *tmp;
	if(!(*root))
	{
		printf("Not Found\n");
		return;
	}
	else if((*root)->data > data)
		tree_del(&(*root)->l, data);
	else if((*root)->data < data)
		tree_del(&(*root)->r, data);
	else if((*root)->l && (*root)->r)
	{
		(*root)->r = min_node((*root)->r, &num);
		(*root)->data = num;
	}
	else
		*root = chg_node(*root);
}

int main(void)
{
	int i;
	tree *root = NULL;
	int data[12] = {50, 20, 10, 40, 30, 35,
			80, 90, 100, 60, 70, 75};

	for(i = 0; i < 12; i++)
		tree_ins(&root, data[i]);

	print_tree(root);
	printf("\n");

	tree_del(&root, 35);
#if 1
	tree_del(&root, 90);
	tree_del(&root, 50);
	tree_del(&root, 20);
	tree_del(&root, 80);
#endif
	print_tree(root);

	return 0;
}






