#include <stdio.h>
#include <stdlib.h>

typedef struct t{
        int data;
        struct t*l;
        struct t*r;
}tree;

tree *get_node(){
        tree *tmp = NULL;
        tmp = (tree *)malloc(sizeof(tree));
        tmp->l = tmp->r = NULL;
        return tmp;
}

void tree_ins(tree **root, int data){
        if(!(*root)){
                *root = get_node();
                (*root)->data = data;
                return;
        }

        if(((*root)->data) > data){
                tree_ins(&((*root)->l), data);
        }
        else{
                tree_ins(&((*root)->r),data);
        }
}

void print_tree(tree *root){
        while(root){
        printf("%d\n", root->data);
        print_tree(root->l);
        print_tree(root->r);

        return;
        }
}

int main(void){
        int i;
        int data[12] = {50, 20, 10, 40, 30, 35, 80, 90, 100, 60, 70, 75};
        tree *root = NULL;

        for(i=0; i<12; i++){
                tree_ins(&root, data[i]);
        }

        print_tree(root);

        return 0;
}
