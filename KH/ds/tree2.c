#include <stdio.h>
#include <stdlib.h>

typedef struct t
{
	int data;
	int lev;
	struct t *l;
	struct t *r;
} tree;

int lev_chk(tree *root)
{
	int l, r;
	
	l = root->l > 0 ? root->l->lev : 0;
	r = root->r > 0 ? root->r->lev : 0;

	return r - l;
}

int lev_modify(tree *root)
{
	int l, r;
	
	l = root->l > 0 ? root->l->lev : 0;
	r = root->r > 0 ? root->r->lev : 0;

	if (l > r)
	{
		return l + 1;
	}

	return r + 1;
}

int rot_chk(tree *root, int data)
{
	if(lev_chk(root) > 0)
	{
		if(lev_chk(root->r) > -1 && root->r->data < data)
		{
			return 1;
		}
		
		return 3;
	}
	else
	{
		if(lev_chk(root->l) < 1 && root->l->data > data)
		{
			return 2;
		}

		return 4;
	}
}

tree *rotation(tree *root, int cas)
{
	tree *tmp;
        tree *tmp_fir;

        if(cas == 3)
        {
                tmp = root->r;
                root->r = root->r->l;
                root->r->r = tmp;
                tmp->l = NULL;
                cas = 1;
        }       
        else if(cas == 4)
        {
                tmp = root->l;
                root->l = root->l->r;
                root->l->l = tmp;
                tmp->r = NULL;
                cas = 2;
        }
        else if(cas == 1)
        {
                tmp = root;
                tmp_fir = root->r;
                root->r->l = root;
                tmp->r = NULL;
                return tmp_fir;
        }
        else if(cas == 2)
        {
                tmp = root;
                tmp_fir = root->l;
                root->l->r = root;
                tmp->l = NULL;
                return tmp_fir;
        }
}

tree *get_node(void)
{
	tree *tmp;
	tmp = (tree *)malloc(sizeof(tree));
	tmp->l = NULL;
	tmp->r = NULL;
	tmp->lev = 1;
	return tmp;
}

void tree_ins(tree **root, int data)
{
	int abs;
	if(!(*root))
	{
		*root = get_node();
		(*root)->data = data;
		return;
	}
	else if((*root)->data > data)
	{
		tree_ins(&(*root)->l, data);
	}
	else if((*root)->data < data)
	{
		tree_ins(&(*root)->r, data);
	}
	
	(*root)->lev = lev_modify(*root);
	abs = lev_chk(*root);
	abs = abs >= 0 ? abs: -abs;
	
	if(abs > 1)
	{
		*root = rotation(*root, rot_chk(*root, data));
	}
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

int main(void)
{
	int i;
	tree *root = NULL;
	int data[10] = {10, 11, 12, 13, 14, 15, 9, 8, 7, 6};

	for(i = 0; i < 10; i++)
	{
		tree_ins(&root, data[i]);
	}

	print_tree(root);

	return 0;
}

