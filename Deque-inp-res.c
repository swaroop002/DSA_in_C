/******************************************************************************

        IMPLEMENTATION OF DOUBLE ENDED QUEUE WITH INPUT RESTRICTION

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define size 10
int x[size];
int front=-1;
int rear=-1;
void enqueue(int a){
    if (rear == size-1){
        printf("Full Queue");
    }
    else{
        if (front==-1){
            front=rear=0;
        }
        else{
            rear++;
        }
        x[rear]=a;

    }
}
int dequeue_front(){

  int del=-1;
  if(front== -1){
      printf("Empty Queue");
  }
  else{
      del=x[front];
      if (front==rear){
          front=rear=-1;
      }
      else{
          front++;
      }
  }
  return del;
}

int dequeue_rear(){
  int del=-1;
  if(rear== -1){
      printf("Empty Queue");
  }
  else{
      del=x[rear];
      if (front==rear){
          front=rear=-1;
      }
      else{
          rear--;
      }
  }
  return del;


}

void display(){
    int i;
    if(front== -1){
        printf("Empty Queue");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d\t",x[i]);
        }
    }
}
int main()
{
    int ch,el;
    do
    {
    printf("\nEnter Your Choice \n 1 : Enqueue \n 2 : Dequeue From Front \n 3 : Dequeue From Rear \n 4 : Display\n 5 : Exit\n");
    scanf("%d",&ch);
    switch(ch){
        case 1 :
        printf("Enter Element : ");
        scanf("%d",&el);
        enqueue(el);
        break;
        case 2:
        printf("\n Removed element from Front : %d",dequeue_front());
        break;
        case 3:
        printf("\n Removed element from Rear : %d",dequeue_rear());
        break;
        case 4:
        printf("\n Queue elements are : ");
        display();
        break;
        case 5:
        exit(0);
        default:
        printf("Invalid Option\n", );
    }
    }while(ch!=5);
    return 0;
}
