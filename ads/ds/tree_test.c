#include <stdio.h>
#include <malloc.h>
typedef struct __node
{
  int data;
  struct __node *node_l;
  struct __node *node_r;
}tree;

tree *get_node()
{
    tree *tmp;
    tmp = (tree *)malloc(sizeof(tree));
    tmp->node_l = NULL;
    tmp->node_r = NULL;

    return tmp;
}

void print_tree(tree *root)
{
   printf("%d\n", root->data);
}

void tree_ins(tree **root, int data) // INSERT 진행중...
{
   tree *tmp;

   if(!(*root))
   {
    *root = get_node();
    (*root)->data = data;
   }



}

int main(void)
{
        int i;
        tree *root = NULL;
        int data[12] = {50, 20, 10, 40, 30, 35,
                        80, 90, 100, 60, 70, 75};
        for(i = 0; i < 1; i++)
                tree_ins(&root, data[i]);
        print_tree(root);

//        printf("\n");
//        tree_del(&root, 35);


#if 1
//      tree_del(&root, 90);
//      tree_del(&root, 50);
//      tree_del(&root, 20);
//      tree_del(&root, 80);
#endif
//        print_tree(root);
        return 0;
}

