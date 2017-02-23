#include <stdio.h>
#include <malloc.h>

typedef struct tree
{
        int data;
        struct tree *left,*right;
}tree

tree *get_node()
{
        tree *tmp = 0;
        tmp = (tree *)malloc(sizeof(tree));
        tmp -> left = 0;
        tmp -> right = 0;
        return tmp;
}

void tree_ins(tree **root,int data)
{
        if(!(*root))
        {
                *root = get_node();
                (*root)->data=data;
                return ;
        }
        if(((*root)->data)>data)
        {
                tree_ins(&((*root)->left),data);
        }
        else if(((*root)->data)<data)
        {
                tree_ins(&((*root)->right),data);
        }
}

void print_tree(tree *root)
{
        if(root)
        {
                printf("%d\n",root->data);
                print_tree(root->left);
                print_tree(root->right);
        }
}

int main(void)
{
        tree *root = 0;
        int i;
        int data[12]={50,20,30,45,40,65,70,75,85,80,90};

        for(i=0;i<12;i++)
        {
                tree_ins(&root,data[i]);
        }
        print_tree(root);
        return 0;
}
