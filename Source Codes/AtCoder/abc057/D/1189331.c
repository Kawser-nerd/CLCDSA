#include<stdio.h>

long long temp[51];
//Combination Table
long long C[51][51];//C[n][k] -> nCk

void comb_table(int N);
void MergeSort_re(long long x[],int left,int right);

int main(void){
  int N,A,B,i,same_value_num,same_value_pos;
  long long value[51],ans=0;
  double ave_max=0;
  scanf("%d %d %d",&N,&A,&B);
  for(i=0;i<N;i++) scanf("%lld",&value[i]);
  MergeSort_re(value,0,N-1);
  comb_table(51);
  for(i=0;i<A;i++){
    ave_max+=value[i];
  }
  ave_max/=A;
  printf("%f\n",ave_max);
  same_value_num=0;
  same_value_pos=0;
  for(i=0;i<N;i++){
    if(value[A-1]==value[i]){
      same_value_num++;
      if(i<A){
        same_value_pos++;
      }
    }
  }
  if(value[0]!=value[A-1]){
    ans=C[same_value_num][same_value_pos];
  }else{
    //same_value+=A-1;
    for(i=A;i<=B;i++){
      ans+=C[same_value_num][i];
      //printf("%d\n",ans);
    }
  }
  //printf("%d\n",same_value_num);
  printf("%lld\n",ans);
  return 0;
}


void comb_table(int N){
  int i,j;
  for(i=0;i<N;i++){
    for(j=0;j<=i;j++){
      if(j==0 || j==i){
        C[i][j]=1;
      }else{
        C[i][j]=C[i-1][j-1]+C[i-1][j];
      }
    }
  }
}



void MergeSort_re(long long  x[],int left,int right){
  int mid,i,j,k;
  if(left >= right) return;
  mid = (left+right)/2;
  MergeSort_re(x,left,mid);
  MergeSort_re(x,mid+1,right);

  for(i=left;i<=mid;i++) temp[i] = x[i];
  for(i=mid+1,j=right;i<=right;i++,j--) temp[i]=x[j];

  i=left;
  j=right;

  for(k=left;k<=right;k++){
    if(temp[i] >= temp[j]) x[k] = temp[i++];
    else x[k] = temp[j--];
  }
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&N,&A,&B);
   ^
./Main.c:15:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<N;i++) scanf("%lld",&value[i]);
                    ^