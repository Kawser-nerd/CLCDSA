#include <stdio.h>

int temp[100001];

void MergeSort(int x[],int left,int right);


int main(void){
  int N,i,tmp=0;
  long long int sum=0;
  int A[100001];
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);
  MergeSort(A,0,N-1);
  for(i=0;i<N-1;i++){
    sum+=A[i];
    if(sum*2 < A[i+1]){
      tmp=i+1;
      //printf("%d\n",tmp);
    }
  }
  printf("%d\n",N-tmp);
}

void MergeSort(int x[],int left,int right){
  int mid,i,j,k;
  if(left >= right) return;
  mid = (left+right)/2;
  MergeSort(x,left,mid);
  MergeSort(x,mid+1,right);

  for(i=left;i<=mid;i++) temp[i] = x[i];
  for(i=mid+1,j=right;i<=right;i++,j--) temp[i]=x[j];

  i=left;
  j=right;

  for(k=left;k<=right;k++){
    if(temp[i] <= temp[j]) x[k] = temp[i++];
    else x[k] = temp[j--];
  }
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:13:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<N;i++) scanf("%d",&A[i]);
                    ^