#include <stdio.h>
#include <stdlib.h>

struct t
{
        int data;
        struct t *R;
        struct t *L;
};typedef struct t tree;

tree *get_node(void)
{
        tree *tmp;
        tmp = (tree *)malloc(sizeof(tree));
        tmp -> R = NULL;
        tmp -> L = NULL;
        return tmp;
}

void tree_ins(tree **root, int data)
{
        if(!(*root))
        {
                *root = get_node();
                (*root) -> data = data;
                return ;
        }

        if((*root)->data > data)
        {
                tree_ins(&(*root)->L, data);
        }else{
                tree_ins(&(*root)->R, data);
        }
}

void print_tree(tree *root)
{
        if(root)
        {
                printf("data = %d\n",root->data);
                print_tree(root->L);
                print_tree(root->R);
        }
}

int main(void)
{
        int i;
        tree *root = NULL;

        int data[12] = {50, 20, 10, 40, 30, 35,
                         80, 90, 100, 60, 70, 75};

        for(i=0;i<12;i++)
        {
                tree_ins(&root, data[i]);
        }
        print_tree(root);
//      tree_del(&root, 35);
        return 0;
}
