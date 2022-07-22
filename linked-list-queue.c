/******************************************************************************

        IMPLEMENTATION OF QUEUE USING LINKED LIST

*******************************************************************************/
#include "stdio.h"
#include "stdlib.h"
struct Node {
  int data;
  struct Node * next;
};

struct Node *start =NULL;

void enqueue(int a){
  struct Node *t =start;
  struct Node *n =(struct Node *)calloc(1,sizeof(struct Node));
  n->data=a;
  n->next=NULL;
  if(start==NULL){
    start=n;
  }
  else{
    while(t->next!=NULL){
      t=t->next;
    }
    t->next=n;
  }
}

int dequeue(){
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

int main()
{
    int ch,el;
    do
    {
    printf("\nEnter Your Choice \n 1 : Enqueue \n 2 : Dequeue \n 3 : Display \n 4 : Exit\n");
    scanf("%d",&ch);
    switch(ch){
        case 1 :
        printf("Enter Element : ");
        scanf("%d",&el);
        enqueue(el);
        break;
        case 2:
        printf("\n Removed element : %d",dequeue());
        break;
        case 3:
        printf("\n Queue elements are : ");
        display();
        break;
        case 4:
        exit(0);
    }
  }while(ch!=4);
    return 0;
}
