#include <stdio.h>
#include <stdlib.h>

struct node
{
        int data;
        struct node *left;
        struct node *right;
};typedef struct node Tree;

Tree *get_node()
{
        Tree *tmp;
        tmp=(Tree *)malloc(sizeof(Tree));
        tmp ->left=NULL;
        tmp ->right=NULL;
        return tmp;
}

void tree_ins(Tree **root, int data)
{
        if(!(*root))
        {
                *root=get_node();
                (*root) ->data=data;
                return;
        }
        if((*root) ->data >data)
                tree_ins(&(*root) ->left,data);
        else
                tree_ins(&(*root) ->right,data);
}

void print_tree(Tree *root)
{
        if(root !=NULL)
        {
                printf("%d\n",root ->data);
                print_tree(root ->left);
                print_tree(root ->right);
        }
}

void *chg_node(Tree *root)
{
        Tree *tmp;
        tmp=root;
        if(!root ->right)
                root=root ->left;
        else if(!root->left)
                root = root->right;
        free(tmp);
        return root;
}

Tree *min_node(Tree *root, int *data)
{
        if(root->left)
                root->left = min_node(root->left, data);
        else
        {
                *data = root->data;
                root = chg_node(root);
        }
        return root;
}

void tree_del(Tree **root, int data)
{
        int num;
        Tree *tmp;
        if(!(*root))
        {
                printf("Not Found\n");
                return;
        }
        else if((*root)->data > data)
                tree_del(&(*root)->left, data);
        else if((*root)->data < data)
                tree_del(&(*root)->right, data);
        else if((*root)->left && (*root)->right)
        {
                (*root)->right = min_node((*root)->right, &num);
                (*root)->data = num;
        }
        else
                *root = chg_node(*root);
}

int main(void)
{
        Tree *root=NULL;
        int i;
        int data[12]={50,20,10,40,30,35,80,90,100,60,70,75};

        for(i=0;i<11;i++)
        {
                tree_ins(&root,data[i]);
        }

        print_tree(root);

        tree_del(&root, 35);
        tree_del(&root, 90);
        tree_del(&root, 50);
        tree_del(&root, 20);
        tree_del(&root, 80);

        print_tree(root);
        return 0;
}


