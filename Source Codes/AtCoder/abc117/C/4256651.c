#include <stdio.h>
 
void quicksort(int X[],int head,int tail);
 
main(){
  int N,M; //??,????
  int i; //?????
  scanf("%d%d",&N,&M);
  int X[M]; //?????
  int D[M-1]; //????????
  int A=0;
  
  for(i=0;i<M;i++)
    scanf("%d",&X[i]);
  
  if(N<M){ //N>=M???????????????????????0
    quicksort(X,0,M-1);
    for(i=0;i<M-1;i++)
      D[i] = X[i+1] - X[i];
    quicksort(D,0,M-2);
    for(i=0;i<M-N;i++){
      A += D[i];
    }
  }
  
  printf("%d\n",A);
  
  return 0;
}
 
void quicksort(int X[],int head,int tail){
  int pivot; //????
  int tmphead,tmptail;
  int i; //?????
  tmphead = head;
  tmptail = tail;
  pivot = X[head];
  while(head<tail){
    while(X[tail]>=pivot && head<tail) tail--;
    if(head!=tail) X[head++] = X[tail];
    while(X[head]<=pivot && head<tail) head++; 
    if(head!=tail) X[tail--] = X[head];
  }
  X[head] = pivot;
  pivot = head;
  head = tmphead;
  tail = tmptail;
  if(head<pivot)
  quicksort(X,head,pivot-1);
  if(tail>pivot)
  quicksort(X,pivot+1,tail);
} ./Main.c:5:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&X[i]);
     ^