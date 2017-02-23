#include <stdio.h>
#include <stdlib.h>

#define LL   -2
#define RR    2
#define LR   -3
#define RL    3

typedef struct node{
  int data;
  int lev;
  struct node *left;
  struct node *right;
}avl_tree;

void avl_ins(avl_tree **root, int data){
  int abs;
  if(!(*root)){
    *root = get_node();
    (*root)->data = data;
    return;
  }
}

int main(void){
  int i;
  int data[20] = {10,11,12,13,14,15,9,8,7,6,5,4,3,16,17,2,18,19,1,20};
  avl_tree *root = NULL;

  for(i=0; i<20; i++){
    avl_ins(&root, data[i]);
  }

  printf("after insertion \n");
  print_tree(root);

  return 0;
}
