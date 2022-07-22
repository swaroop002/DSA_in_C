/******************************************************************************

        IMPLEMENTATION OF CIRCULAR QUEUE USING LINKED LIST
        
                      CIRCULAR LINKED LIST

*******************************************************************************/


#include "stdio.h"
#include "stdlib.h"
struct Node {
  int data;
  struct Node * next;
};
struct Node *start =NULL;

void enqueue_front(int a){
  struct Node *n =(struct Node *)calloc(1,sizeof(struct Node));
  struct Node *t =start;
  n->data=a;
  if(start==NULL){
    n->next=n;
    start=n;
  }
  else{
    while(t->next!=start){
      t=t->next;
    }
    t->next=n;
    n->next=start;
    start=n;
  }
}

void enqueue_rear(int a){
  struct Node *n =(struct Node *)calloc(1,sizeof(struct Node));
  struct Node *t =start;
  n->data=a;
  if(start==NULL){
    n->next=n;
    start=n;
  }
  else{
    while(t->next!=start){
      t=t->next;
    }
    t->next=n;
    n->next=start;
  }
}
int dequeue_front(){
  int del;
  struct Node *t =start;
  struct Node *p =start;
  if (start==NULL){
    printf("No Element in Linked List \n");
  }
  else{
    del=start->data;
    if(start->next==start){
      start=NULL;
      free(t);
    }
    else{
    while(t->next!=start){
      t=t->next;
    }
    start=start->next;
    t->next=start;
    free(p);
    }
  }
  return del;
}

int dequeue_rear(){
  int del;
  struct Node *t =start;
  struct Node *p =t;
  if (start==NULL){
    printf("No Element in Linked List \n");
  }
  else{
    del=t->data;
    if(t->next==start){
      start=NULL;
      free(t);
    }
    else{
    while(t->next!=start){
      p=t;
      t=t->next;
    }
    del=t->data;
    p->next=start;
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

    while(t->next!=start){
      printf("\t%d", t->data);
      t=t->next;
    }
    printf("%d\t", start->data);
  }
}
int main()
{
    int ch,el;
    do
    {
    printf("\nEnter Your Choice \n 1 : Enqueue From Front \n 2 : Enqueue From Rear \n 3 : Dequeue From Front \n 4 : Dequeue From Rear \n 5 : Display\n 6 : Exit\n");
    scanf("%d",&ch);
    switch(ch){
        case 1 :
        printf("Enter Element : ");
        scanf("%d",&el);
        enqueue_front(el);
        break;
        case 2 :
        printf("Enter Element : ");
        scanf("%d",&el);
        enqueue_rear(el);
        break;
        case 3:
        printf("\n Removed element from Front : %d",dequeue_front());
        break;
        case 4:
        printf("\n Removed element from Rear : %d",dequeue_rear());
        break;
        case 5:
        printf("\n Queue elements are : ");
        display();
        break;
        case 6:
        exit(0);
        default:
        printf("Invalid Option\n" );
    }
  }while(ch!=6);
    return 0;
}
