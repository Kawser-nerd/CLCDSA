#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define MIN(a,b) ((a)<(b)?(a):(b))

void add(int *bit,int index,int v){
  const int n=bit[0];
  for(int i=index;i<=n;i+=i&-i) bit[i]+=v;
}

int sum(int *bit,int index){
  int res=0;
  for(int i=index;i>0;i-=i&-i) res+=bit[i];
  return res;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *p=(int *)calloc(n+1,sizeof(int));
  int *bit=(int *)calloc(n+1,sizeof(int));
  bit[0]=n;
  int i;
  for(i=1;i<=n;i++){
    int b;
    scanf("%d",&b);
    p[b]=i;
    add(bit,i,1);
  }
  int64 ans=0;
  for(i=1;i<=n;i++){
    add(bit,p[i],-1);
    int c=sum(bit,p[i]);
    ans+=MIN(c,n-i-c);
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&b);
     ^