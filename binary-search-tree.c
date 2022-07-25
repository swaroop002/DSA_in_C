/******************************************************************************

                      IMPLEMENTATION OF BINARY SEARCH TREE

*******************************************************************************/

#include "stdio.h"
#include "stdlib.h"
struct Node {
  int data;
  struct Node * left;
  struct Node * right;
};
struct Node * root = NULL;
void insert(int a){
  struct Node *p ,*q ;
  struct Node *n =(struct Node*) calloc(1,sizeof(struct Node));
  n->data=a;
  n->left=NULL;
  n->right=NULL;
  if(root==NULL){
    root=n;
    printf("Inserted Node %d",n->data);
  }
  else{
    q=root;
    while(q!=NULL){
      p=q;
      if(a < q->data){
        q=q->left;
      }
      else{
        q=q->right;
      }
    }
      if(a < p->data){
        p->left=n;
        printf("Inserted Node %d",n->data);
      }
      else{
        p->right=n;
        printf("Inserted Node %d",n->data);
      }
  }
}

void inorder(struct Node *t) {
  if(t!=NULL){
    inorder(t->left);
    printf("\t%d",t->data);
    inorder(t->right);
  }
}
void preorder(struct Node *t) {
  if(t!=NULL){
    printf("\t%d",t->data);
    preorder(t->left);
    preorder(t->right);
  }
}
void postorder(struct Node *t) {
  if(t!=NULL){
    postorder(t->left);
    postorder(t->right);
    printf("\t%d",t->data);
  }
}
// void delete_node(struct Node *t,int a){
//   struct Node *p;
//   if(t==NULL){
//     printf("No node to Delete \n");
//   }
//   if(a<t->data){
//     t->left=delete_node(t->left,a);
//   }
// }

int main()
{
    int ch,el;
    printf("\nBinary Search Tree\n");
    do
    {
    printf("\nEnter Your Choice \n 1 : Insert New Node \n 2 : Preorder \n 3 : Inorder \n 4 : Postorder\n 5 : Exit\n");
    scanf("%d",&ch);
    switch(ch){
        case 1 :
        printf("Enter Element : ");
        scanf("%d",&el);
        insert(el);
        break;
        case 2:
        printf("Preorder of BST is : \n");
        preorder(root);
        break;
        case 3:
        printf("Inorder of BST is : \n");
        inorder(root);
        break;
        case 4:
        printf("Postorder of BST is : \n");
        postorder(root);
        case 5:
        exit(0);
        default:
        printf("Invalid Choice \n" );
    }
    }while(ch!=5);
    return 0;
}
