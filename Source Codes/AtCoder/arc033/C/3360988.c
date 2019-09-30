#include<stdio.h>
#include<stdlib.h>

const int n=2000000;

void add(int *bit,int index,int v){
  for(int i=index;i<=n;i+=i&-i) bit[i]+=v;
}

int search(int *bit,int x){
  int k=1;
  while(2*k<=n) k*=2;
  int res=0;
  for(;k>0;k>>=1){
    if(res+k<=n && bit[res+k]<x){
      x-=bit[res+k];
      res+=k;
    }
  }
  return res+1;
}

void run(void){
  int q;
  scanf("%d",&q);
  int *bit=(int *)calloc(n+1,sizeof(int));
  while(q--){
    int t,x;
    scanf("%d%d",&t,&x);
    if(t==1){
      add(bit,x,1);
    } else {
      int v=search(bit,x);
      printf("%d\n",v);
      add(bit,v,-1);
    }
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&q);
   ^
./Main.c:29:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&t,&x);
     ^