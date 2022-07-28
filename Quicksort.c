
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
int partition(int *a,int st,int end){
  int pivot=*(a+end);
  int i=(st-1);
  for (int j = st; j <= end-1; j++) {
    if (*(a+j)<pivot) {
      i++;
      int temp=*(a+i);
      *(a+i)=*(a+j);
      *(a+j)=temp;
    }
  }
  int temp=*(a+i+1);
  *(a+i+1)=*(a+end);
  *(a+end)=temp;
  return (i+1);
}

void quicksort(int *a,int st,int end){
  if(st<end){
    int part_ind = partition(a,st,end);
    quicksort(a,st,part_ind-1);
    quicksort(a,part_ind+1,end);
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
    quicksort(ary,0,len-1);
    display(ary,len);

}
