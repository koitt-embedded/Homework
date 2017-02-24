#include <stdio.h>
#include <stdlib.h>

typedef struct t{
  int data;
  struct t *left;
  struct t *right;
}tree;

tree *get_node(){
  tree *tmp = (tree *)malloc(sizeof(tree));
  tmp->left = tmp->right = NULL;
  return tmp;
}

void tree_ins(tree **root, int data){
  if(!(*root)){
    *root = get_node();
    (*root)->data = data;
    return;
  }
  if((*root)->data > data){
    tree_ins(&(*root)->left, data);
  }else{
    tree_ins(&(*root)->right, data);
  }
}

void print_tree(tree *root){
  if(root){
    printf("data = %d \n", root->data);
    print_tree(root->left);
    print_tree(root->right);
  }
}

tree *chg_node(tree *root){
  tree *tmp = root;
  if(!(root->right)){
    root = root->left;
  }else if(!(root->left)){
    root = root->right;
  }
  free(tmp);
  return root;
}

tree *min_node(tree *root, int *num){
  if(root->left){
    root->left = min_node(root->left, num);
  }else{
    *num = root->data;
    root = chg_node(root);
  }
  return root;
}

void tree_del(tree **root, int data){
  int num;
 
  if(!(*root)){
    printf("tree is not Found~! \n");
    return;

  }else if((*root)->data > data){
    tree_del(&(*root)->left, data);
  }else if((*root)->data < data){
    tree_del(&(*root)->right, data);

  }else if((*root)->left && (*root)->right){
    (*root)->right = min_node((*root)->right, &num);
    (*root)->data = num;
  }else{
    *root = chg_node(*root);
  }
}

int main(void){
  int i;
  int data[12]={50,20,30,35,10,40,80,90,100,75,70,85};
  tree *root = NULL;

  for(i=0; i<12; i++){
    tree_ins(&root, data[i]);
  }

  print_tree(root);
  printf("===============\n");

  tree_del(&root, 20);
  print_tree(root);

  return 0;
}
