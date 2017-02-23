#include<stdio.h>
#include<malloc.h>

struct aNode{
        int data;
        struct aNode *link;
};
typedef struct aNode Node;

void push(int data, Node **top)
{
        Node *tmp = *top;
        *top = (Node*)malloc(sizeof(Node));
        (*top) -> data = data;
        (*top) -> link = tmp;
        printf("정의가 구현된다!!:%d\n",data);

}
int pop (Node **top){
        if(!(*top))
        return -1;
        int num = (*top) -> data;
        Node *tmp =*top;
        *top = tmp ->link;
        free(tmp);
        return num;
}
int main(int argc, char **argv)
{
        Node *top=NULL;
        for(int i=0; i<10; i++)
{
        push((i+1)*10,&top);
}
        for(int i=0; i<10; i++)
        printf("%d\n : pop가 구현된다!!",pop(&top));
        return 0;
}
~                                   
