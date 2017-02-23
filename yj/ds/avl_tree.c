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

avl_tree *get_node(void){
  avl_tree *tmp;
  tmp = (avl_tree *)malloc(sizeof(avl_tree));
  tmp->left = tmp->right = NULL;
  tmp->lev = 1;
  return tmp;
}

int lev_chk(avl_tree *root){
  int r = root->right > 0 ? root->right->lev : 0;
  int l = root->left > 0 ? root->left->lev : 0;
}

int lev_modify(avl_tree *root){
  int r = root->right > 0 ? root->right->lev : 0;
  int l = root->left > 0 ? root->left->lev : 0;

  if(l > r){
    return l + 1;
  }
  return r + 1;
}

avl_tree *ll_rot(avl_tree *p, avl_tree *c){
  p->left = c->right;
  c->right = p;
  p->lev = lev_modify(p);
  c->lev = lev_modify(c);
  return c;
}

avl_tree *rr_rot(avl_tree *p, avl_tree *c){
  p->right = c->left;
  c->left = p;
  p->lev = lev_modify(p);
  c->lev = lev_modify(c);
  return c;
}

avl_tree *lr_rot(avl_tree *p, avl_tree *c){
  c = rr_rot(c, c->right);
  return ll_rot(p, c);
}

avl_tree *rl_rot(avl_tree *p, avl_tree *c){
  c = ll_rot(c, c->left);
  return rr_rot(p,c);
}

avl_tree *rotation(avl_tree *root, int ret){
  switch(ret){
    case LL:
	return ll_rot(root, root->left);
    case LR:
	return lr_rot(root, root->left);
    case RR:
	return rr_rot(root, root->right);
    case RL:
	return rl_rot(root, root->right);
  }
}

int rot_chk(avl_tree *root, int data){
  if(lev_chk(root) < 0){ 
    if(lev_chk(root->left) > -1 && root->left->data < data){
      return LR;
    }
    return LL;
  }
  else{
    if(lev_chk(root->right) < 1 && root->right->data > data){
      return RL;
    }
    return RR;
  }
  return 0;
}

void avl_ins(avl_tree **root, int data){
  int abs;
  if(!(*root)){
    *root = get_node();
    (*root)->data = data;
    return;
  }if((*root)->data > data){
    avl_ins(&(*root)->left, data);
  }else{
    avl_ins(&(*root)->right, data);
  }
  (*root)->lev = lev_modify(*root);
  abs = lev_chk(*root);
  abs = (abs > 0) ? abs : -abs;
  if(abs > 1){
    *root = rotation(*root, rot_chk(*root, data));
  }
}

void print_tree(avl_tree *root){
  if(root){
    printf("data = %4d", root->data);
    if(root->left){
      printf(", left = %4d", root->left->data);
    }else{
      printf(", left = NULL");
    }
    if(root->right){
      printf(", right = %4d\n", root->right->data);
    }else{
      printf(", right = NULL \n");
    }
    print_tree(root->left);
    print_tree(root->right);
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
