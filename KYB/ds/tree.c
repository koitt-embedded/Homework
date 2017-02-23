#include <stdio.h>
#include <stdlib.h>

struct node
{
        int data;
        struct node *link_S;
        struct node *link_L;
};typedef struct node tree;

tree *get_node()
{
        tree *tmp;
        tmp = (tree *)malloc(sizeof(tree));
        tmp ->link_S = NULL;
        tmp ->link_L = NULL;
        return tmp;
}

void tree_ins(tree **root, int data)
{
        if(!(*root))
        {
                *root = get_node();
                (*root)->data = data;
                return ;
        }
        if((*root)->data > data)
        {
                tree_ins(&(*root)->link_S, data);
        }else{
                tree_ins(&(*root)->link_L, data);
        }
}

void print_tree(tree *root)
{
        if(!(root))
        {
                return ;
        }
        printf("%d\n",root ->data);
        print_tree(root ->link_S);
        print_tree(root ->link_L);
}

int main(void)
{
        int i;
        tree *root = NULL;
        int data[12] = {50,20,10,40,30,35,80,90,100,60,70,75};

        for(i=0; i<12;i++)
        {
                tree_ins(&root, data[i]);
        }
        print_tree(root);
        return 0;
}

