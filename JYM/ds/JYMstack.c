#include<stdio.h>
#include<stdlib.h>
#define EMPTY 0

typedef struct node{	//struct의 변수 이름이 node
        int data;
        struct node*link;
} stack;

stack *get_node(void)
{
        stack*tmp;
        tmp=(stack*)malloc(sizeof(stack));
        tmp->link=EMPTY;
        return tmp;
}

void push( stack **top , int data)	//main에서 포인터변수를 선언 하였고, 
				//그 main에서의 포인터의 주소를 받아와서 해야하기 때문에
				// 포인터의 포인터가 선언이 되는 것임.
{
        stack *tmp;
        tmp=*top;
        *top=get_node();
        (*top)->data=data;	
        (*top)->link=tmp;
}

int pop(stack **top)
{
        stack*tmp;
        int num;

        tmp=*top;
   if (*top == EMPTY)
        {
                printf("stack is EMPTY!!\n");
                return 0;
        }
        num=tmp->data;
        *top=(*top)->link;
        free(tmp);	//heap공간에 안쓰는 것들이 메모리 차지를 하기때문에 없애준다.
        return num;
}

int main(void)
{
        stack*top =EMPTY;
        push(&top,10);
        push(&top,20);
        push(&top,30);
        printf("%d\n",pop(&top));
        printf("%d\n",pop(&top));
        printf("%d\n",pop(&top));
        printf("%d\n",pop(&top));

        return 0;
}

