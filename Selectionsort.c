
#include <stdio.h>
#include <stdlib.h>

void allocate(int *a,int len){
    for (int i=0;i<len;i++){
        printf("\nEnter Element :");
        scanf("%d",(a+i));
    }
}
void display(int *a,int len){
    printf("\nSorted Elements :");
    for (int i=0;i<len;i++){
        printf("\t%d",*(a+i));
    }
}

void selectionsort(int *a,int len){
  int i,j,small;
  for (i = 0; i < len-1; i++) {
    small=i;
    for (j = i+1; j < len; j++) {
      if(*(a+j)<*(a+small))
        small=j;
    }
    int temp=*(a+small);
    *(a+small)=*(a+i);
    *(a+i)=temp;
  }
}

void main()
{
    int *ary;
    int len;
    printf("Enter Length Of Array : ");
    scanf("%d",&len);
    ary=(int*)calloc(len,sizeof(int));
    allocate(ary,len);
    selectionsort(ary,len);
    display(ary,len);

}
