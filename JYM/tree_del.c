nclude<stdio.h>
#include<stdlib.h>

typedef struct node
{
        int data;
        struct node*link_I;
        struct node*link_R;
}tree;

tree *get_node(void){
        tree * tmp;
        tmp = (tree*)malloc(sizeof(tree));
        tmp->link_I= NULL;
        tmp->link_R= NULL;
        return tmp;

}


void tree_ins (tree **root , int data)
{



        if(!(*root))
        {
                *root=get_node();
                (*root)->data=data;
                return ;
        }
                if((*root)->data>data)
                {
                        tree_ins(&(*root)->link_I ,data);
                }
                else
                {
                        tree_ins(&(*root)->link_R ,data);
                }

        return ;
}
void print_tree ( tree *root)
{
        if(!(root))
        {
                return ;
        }
        printf("%d\n",root->data);
        print_tree(root->link_I);
        print_tree(root->link_R);

}
tree *chg_node(void)
{
	tree*tmp;
	tmp=root;
	if(!(root)->link_I)
		root=root->link_R;
	else(!(root)->link_R)
		root=root->link_I;	
	return root;
}
tree *min_node(tree *root , int *data)
{	
	if(root->link_I)
	{
		*data = min_node(root->link_I , data);
	}
	else
		*data=root->data; 
		root= chg_node(root);
	free(tmp);
	return root;
}
void tree_del(tree **root, int data)
{
	int num;
	tree*tmp;
	if(!(*root))
	{
		return;
	}
	else if((*root)->data > data)
	{
		tree_del(&(*root)->link_I , data);
	}
	else if((*root)->data < data)
	{
		tree_del(&(*root)->link_R , data);
	}
	else if((*root)->link_I  && (*root)->link_R)
	{
		(*root)->R=min_node((*root)->R , &num);
		(*root)->data = num;
	} 
}
int main(void)
{
        int i;
        tree *root =NULL;
        int data[]={50,20,10,40,30,35,80,90,100,60,70,75};

        for(i=0;i<12;i++)
        {
                tree_ins(&root,data[i]);
        }
        print_tree(root);
        	
	tree_del(&root,35);
	tree_del(&root,90);
	tree_del(&root,50);        
	return 0;
        }

