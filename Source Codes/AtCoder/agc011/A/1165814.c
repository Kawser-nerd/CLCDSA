#include<stdio.h>

int temp[100001];

void MergeSort(int x[],int left,int right);


int main(void){
  int N,C,K;
  int T[100001];
  int i,j,k,ans=1,first_time,passenger;
  scanf("%d %d %d",&N,&C,&K);
  for(i=0;i<N;i++){
    scanf("%d",&T[i]);
  }
  MergeSort(T,0,N-1);
  first_time=T[0];
  passenger=0;
  for(i=0;i<N;i++){
    if(T[i]-K <= first_time && passenger < C){
      passenger++;
    }else{
      first_time=T[i];
      ans++;
      passenger=1;
    }
  }
  printf("%d\n",ans);
  return 0;
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
   scanf("%d %d %d",&N,&C,&K);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&T[i]);
     ^