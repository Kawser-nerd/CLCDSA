#include<stdio.h>
#include <stdlib.h>

int N,A,B,C;

void swap(int array[],int j){
  int st;
  st=array[j];
  array[j]=array[j+1];
  array[j+1]=st;
}

int key(int array[],int cur,int a,int b,int c){
  int ret[4];
  int i,j;
  if(cur==N){
    if(a>0&&b>0&&c>0){
      return abs(a-A)+abs(b-B)+abs(c-C)-30;
    }else{
      return 1000000000;
    }
  }
  ret[0]=key(array,cur+1,a,b,c);
  ret[1]=key(array,cur+1,a+array[cur],b,c)+10;
  ret[2]=key(array,cur+1,a,b+array[cur],c)+10;
  ret[3]=key(array,cur+1,a,b,c+array[cur])+10;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      if(ret[j+1]<ret[j])swap(ret,j);
    }
  }
  return ret[0];
}

int main(void){
  int i,ans;
  scanf("%d%d%d%d",&N,&A,&B,&C);
  int array[N];
  for(i=0;i<N;i++){
    while(scanf("%d",&array[i])!=1);
  }
  ans=key(array,0,0,0,0);
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&N,&A,&B,&C);
   ^