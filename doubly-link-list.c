/******************************************************************************

        IMPLEMENTATION OF DOUBLY LINKED LIST

*******************************************************************************/
#include "stdio.h"
#include "stdlib.h"
struct Node{
  int data;
  struct Node * next;
  struct Node * prev;
};
struct Node *start=NULL;

void insert_node_front(int a){
  struct Node *n=(struct Node *)calloc(1,sizeof(struct Node));
  n->data=a;
  n->prev=NULL;
  if(start==NULL){
    n->next=NULL;
    start=n;
  }
  else{
    start->prev=n;
    n->next=start;
    start=n;
  }
}

void insert_node_rear(int a){
  struct Node *n=(struct Node *)calloc(1,sizeof(struct Node));
  struct Node *t=start;
  n->data=a;
  n->next=NULL;
  if(start==NULL){
    n->prev=NULL;
    start=n;
  }
  else{
    while(t->next!=NULL){
      t=t->next;
    }
    t->next=n;
    n->prev=t;
  }
}

void insert_node_at(int a,int pos){
  if (pos==0){
    insert_node_front(a);
  }
  else{
  struct Node *n=(struct Node *)calloc(1,sizeof(struct Node));
  struct Node *t=start;
  n->data=a;
  for (int i = 0; i < pos; i++) {
    t=t->next;
  }
  n->prev=t->prev->next;
  n->next=t;
  t->prev->next=n;
  t->prev=n;
  }
}

int delete_node_front() {
  struct Node *t=start;
  int del=-1;
  if(start==NULL){
    printf("No Element present in List\n");
  }
  else{
    del=start->data;
    if(start->next==NULL){
      start=NULL;
      free(t);
    }
    else{
      start=start->next;
      start->prev=NULL;
      free(t);
    }
  }
  return del;
}
int delete_node_rear(){
  struct Node *t=start;
  int del=-1;
  if(start==NULL){
    printf("No Element present in List\n");
  }
  else{
    if(start->next==NULL){
      del=start->data;
      start=NULL;
      free(t);
    }
    else{
      while (t->next!=NULL) {
        t=t->next;
      }
      del=t->data;
      t->prev->next=NULL;
      free(t);
    }
  }

  return del;
}
int delete_node_at(int pos){
  int del=-1;
  struct Node *t =start;
  if (start==NULL){
    printf("Linked List Empty \n");
    return del;
  }
  else if (pos==0){
    del=delete_node_front();
    return del;
  }
  else{
    for (int i = 0; i < pos; i++) {
      t=t->next;
    }
    if (t->next==NULL){
      del=delete_node_rear();
      free(t);
      return del;
    }
    else{
      del=t->data;
      t->prev->next=t->next;
      t->next->prev=t->prev;
      free(t);
      return del;
    }
    }
  }
void delete_node(int a){
  struct Node *t =start;
  if (start==NULL){
    printf("Linked List Empty \n");
  }
  else{
    while (t!=NULL) {
      if(t->data==a){
        if(t->prev==NULL && t->next==NULL){
          start=NULL;
          free(t);
        }
        else if(t->prev==NULL && t->next!=NULL){
            start=t->next;
            start->prev=NULL;
          }
          else if(t->next==NULL){
              t->prev->next=NULL;
              free(t);
            }
          else{
            t->prev->next=t->next;
            t->next->prev=t->prev;
            free(t);
          }
          break;
      }
      else{
        t=t->next;
      }
    }
  }
}

void forward_traverse(){
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

void reverse_traverse(){
  struct Node *t = start;
  if (start==NULL){
    printf("Linked List Empty\n");
  }
  else{
    printf("Elements are :\n");

    while(t->next!=NULL){
      t=t->next;
    }
    while(t!=NULL){
      printf("%d\t", t->data);
      t=t->prev;
    }
  }
}

void search(int a){
  struct Node *t =start;
  if (start==NULL){
    printf("Linked List Empty \n");
  }
  else{
    while(t!=NULL){
      if(t->data==a){
        printf("Element present in List \n");
        break;
      }
      else{
        t=t->next;
      }
    }
    if(t==NULL){
      printf("Element not present in List\n" );
    }
  }
}
int main()
{
    int ch,el,pos;
    printf("Linked List \n");
    do
    {
    printf("\nEnter Your Choice \n 1 : Insert Node From Front \n 2 : Insert Node From Rear \n 3 : Insert Node at Position \n 4 : Delete Node From Front \n 5 : Delete Node From Rear \n 6 : Delete Node at Position \n 7 : Delete Node \n 8 : Forward Traverse \n 9 : Reverse Traverse \n 10 : Search for Element \n 11 : Exit\n");
    scanf("%d",&ch);
    switch(ch){
        case 1 :
        printf("Enter Element : ");
        scanf("%d",&el);
        insert_node_front(el);
        break;
        case 2 :
        printf("Enter Element : ");
        scanf("%d",&el);
        insert_node_rear(el);
        break;
        case 3 :
        printf("Enter Position : ");
        scanf("%d",&pos);
        printf("Enter Element : ");
        scanf("%d",&el);
        insert_node_at(el,pos);
        break;
        case 4:
        printf("\n Removed element from Front : %d",delete_node_front());
        break;
        case 5:
        printf("\n Removed element from Rear : %d",delete_node_rear());
        break;
        case 6:
        printf("Enter Position : ");
        scanf("%d",&pos);
        printf("\n Removed element from Position : %d",delete_node_at(pos));
        break;
        case 7:
        printf("Enter Element : ");
        scanf("%d",&el);
        delete_node(el);
        break;
        case 8:
        forward_traverse();
        break;
        case 9:
        reverse_traverse();
        break;
        case 10:
        printf("Enter Element to Search: ");
        scanf("%d",&el);
        search(el);
        break;
        case 11:
        exit(0);
        default:
        printf("Invalid Option\n" );
    }
  }while(ch!=12);
    return 0;
}
