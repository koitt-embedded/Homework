#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *left;
  struct node *right;
};typedef struct node Tree;

Tree *get_node(){
  Tree *tmp;
  tmp = (Tree *)malloc(sizeof(Tree));
  tmp->left = NULL;
  tmp->right = NULL;
  return tmp;
}

void tree_ins(Tree **root, int data){
  if(!(*root))
  {
    *root = get_node();
    (*root)->data = data;
    return;
  }
  if( ((*root)->data) > data )
  {
    tree_ins( &(*root)->left , data);
  }
  else
  {
    tree_ins( &(*root)->right , data);
  }
}

void print_tree(Tree *root)
{
	if(root != NULL);
	{
		printf("%d\n",root ->data);
		print_tree(root ->left);
		print_tree(root ->right);
	}
}

int main(void){
	int i;
	Tree *root = NULL;
	int data[12] = {50,20,10,40,30,35,80,90,100,60,70,75};

	for(i=0; i<10; i++){
	tree_ins(&root, data[i]);
 	 }
	print_tree(root); 

  return 0;

}

