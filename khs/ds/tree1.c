#include <stdio.h>
#include <stdlib.h>

typedef  struct Tree
{
	int data;
	struct Tree *left;
	struct Tree *right;
} tree;

tree *get_node()
{
	tree *tmp;
	tmp = (tree *)malloc(sizeof(tree));
	tmp-> left = tmp-> right = NULL;
	return tmp;
}
void tree_ins(tree **root, int data)
{
	if(!(*root))
	{
		*root = get_node();
		(*root)-> data = data;
		return;
	}

	if(((*root)-> data) > data)
	{
		tree_ins(&((*root)-> left), data);
	}

	else tree_ins(&((*root)-> right), data);
}	

void print_tree(tree *root)
{
	while(root)
	{
		printf("%d\n", root -> data);
		print_tree(root-> left);
		print_tree(root-> right);

		return;
	}
}



int main(void)
{
	int i;
	int data[12] = {50, 20, 10, 40, 30, 35, 80, 90, 100, 60, 70, 75};

	tree *root;
	root = NULL;

	for(i = 0; i < 12; i++)	
	{
		tree_ins(&root, data[i]);
	}

	print_tree(root);

	return 0;
}
