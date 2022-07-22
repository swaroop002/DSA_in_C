/******************************************************************************

        IMPLEMENTATION OF STACK USING LINKED LIST

*******************************************************************************/
#include "stdio.h"
#include "stdlib.h"
struct Node {
  int data;
  struct Node * next;
};
struct Node *start =NULL;

void push(int a){
  struct Node *n =(struct Node *)calloc(1,sizeof(struct Node));
  n->data=a;
  if(start==NULL){
    n->next=NULL;
    start=n;
  }
  else{
    n->next=start;
    start=n;
  }
}
int pop(){
  int del;
  struct Node *t =start;
  if (start==NULL){
    printf("No Element in Linked List \n");
  }
  else{
    del=t->data;
    if(start->next==NULL){
      start=NULL;
      free(t);
    }
    else{
    start=start->next;
    free(t);
    }
  }
  return del;
}

void display(){
  struct Node *t = start;
  if (start==NULL){
    printf("Linked List Empty\n");
  }
  else{
    printf("Elements are :\n");

    while(t!=NULL){
      printf("%d\t", t->data);
      t=t->next;
    }
  }
}
int peek(){
  struct Node *t = start;
  if (start==NULL){
    printf("Linked List Empty\n");
    return 0;
  }
  else{
    int el=t->data;
    return el;
  }
}
int main()
{
    int ch,el;
    printf("Implementation of stack using Linked List \n");
    do
    {
    printf("\nEnter Your Choice \n 1 : Push \n 2 : Pop \n 3 : Peek \n 4 : Display \n 5 : Exit\n");
    scanf("%d",&ch);
    switch(ch){
        case 1 :
        printf("Enter Element : ");
        scanf("%d",&el);
        push(el);
        break;
        case 2:
        printf("\n Removed element : %d",pop());
        break;
        case 3:
        printf("\n Value at top : %d",peek());
        break;
        case 4:
        printf("\n Stack elements are :");
        display();
        break;
        case 5:
        exit(0);
    }
    }while(ch!=5);
    return 0;
}
