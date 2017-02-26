#include <stdio.h>

#include <malloc.h>

typedef struct __node

{

  int data;

  struct __node *node_l;

  struct __node *node_r;

}tree;


void free_node(tree **root)

{


}


void tree_del(tree **root, int data)

{

/*

  tree *tmp; 


  if((*root)->data == data)

  {

    if(root->node_l != NULL && root->node_r != NULL)

    {

     tmp->node_l = (*root)->node_l;

     tmp->node_r = (*root)->node_r;

    }

    else if(root->node_l != NULL && root->node_r == NULL)

    {

     tmp->node_l == (*root)->node_l;  

    }

    else if(root->node_l == NULL && root->node_r != NULL)

    {

     tmp->node_r == (*root)->node_r;

    }

    else

    {

      printf("NO link node");

    }

   

   free(*head);     

     

     tmp = free_node(*root);

  }

  else if

  {

   if(root->node_l == NULL && root->node_r == NULL)

     return;

   if(root->node_l != NULL)

        print_tree(root->node_l);

   if(root->node_r != NULL)

        print_tree(root->node_r);

  }


*/

/*

 자식노드가 두개가 있는 경우- 

 삭제하려는 값이 왼쪽,오른쪽 중 어느곳에 있는지 파악하고

 왼쪽에 있으면 왼쪽값중 최대값을 삭제한 위치로 올리고

 오른쪽이면 오른쪽값중 최소값을 삭제한 위치로 올린다. 


 삭제한 노드와 끌어올리는 노드의 자식노드 값을 기억하고 함께 가져와 올려야한다

 -> 한번 쭉 탐색하고 최소값을 기억해야할 것 같은데..

*/

}


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


   if(root->node_l == NULL && root->node_r == NULL)

     return;

   if(root->node_l != NULL)

        print_tree(root->node_l);

   if(root->node_r != NULL)

        print_tree(root->node_r);

}


tree* tree_ins(tree **root, int data)

{

   tree *tmp;


   if(!(*root))

   {

    *root = get_node();

    (*root)->data = data;

   }

   else if((*root)->data > data)

   {

     (*root)->node_l = tree_ins(&(*root)->node_l,data);

   }

   else if((*root)->data < data)

   {

     (*root)->node_r = tree_ins(&(*root)->node_r,data);

   }

   else

     printf("tree error!\n");


   return *root;

}


int main(void)

{

        int i;

        tree *root = NULL;

        int data[12] = {50, 20, 10, 40, 30, 35,80, 90, 100, 60, 70, 75};

       // int data[9] = {50,30,41,37,38,80,70,100,90};

        for(i = 0; i < 12; i++)

             tree_ins(&root, data[i]);

        print_tree(root);


        printf("\n");

        tree_del(&root, 35);



#if 1

//      tree_del(&root, 90);

//      tree_del(&root, 50);

//      tree_del(&root, 20);

//      tree_del(&root, 80);

#endif

//        print_tree(root);

        return 0;

}

