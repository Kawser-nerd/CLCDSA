#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a)>(b)?(a):(b))

void update(int *bit,int x,int v){
  const int n=bit[0];
  for(int i=x;i<=n;i+=i&-i) bit[i]=MAX(bit[i],v);
}

int getMax(int *bit,int x){
  int res=0;
  for(int i=x;i>0;i-=i&-i) res=MAX(res,bit[i]);
  return res;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *bit=(int *)calloc(n+1,sizeof(bit));
  bit[0]=n;
  for(int i=0;i<n;i++){
    int c;
    scanf("%d",&c);
    int v=getMax(bit,c)+1;
    update(bit,c,v);
  }
  printf("%d\n",n-getMax(bit,n));
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&c);
     ^