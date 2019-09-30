#include<stdio.h>
#include<stdlib.h>

#define POS(i,j) ((i)*(n+1)+(j))

void initBIT(int *b){
  const int n=b[0];
  for(int i=1;i<=n;i++) b[i]=0;
}

void add(int *bit,int x,int v){
  const int n=bit[0];
  for(int i=x;i<=n;i+=i&-i) bit[i]+=v;
}

int sum(int *bit,int x){
  int res=0;
  for(int i=x;i>0;i-=i&-i) res+=bit[i];
  return res;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *b=(int *)calloc(n+1,sizeof(int));
  int *w=(int *)calloc(n+1,sizeof(int));
  int i,j;
  for(i=0;i<2*n;i++){
    char s[10];
    int k;
    scanf("%s%d",s,&k);
    if(s[0]=='B'){
      b[k]=i+1;
    } else {
      w[k]=i+1;
    }
  }
  int *dp=(int *)calloc((n+1)*(n+1),sizeof(int));
  int *bit=(int *)calloc(2*n+1,sizeof(int));
  bit[0]=2*n;
  dp[POS(0,0)]=0;
  for(i=1;i<=n;i++){
    add(bit,b[i],1);
    dp[POS(i,0)]=dp[POS(i-1,0)]+(i-sum(bit,b[i]));
  }
  initBIT(bit);
  for(j=1;j<=n;j++){
    add(bit,w[j],1);
    dp[POS(0,j)]=dp[POS(0,j-1)]+(j-sum(bit,w[j]));
  }
  for(i=1;i<=n;i++){
    initBIT(bit);
    for(j=1;j<=i;j++){
      add(bit,b[j],1);
    }
    for(j=1;j<=n;j++){
      add(bit,w[j],1);
      int p=dp[POS(i,j-1)]+(i+j-sum(bit,w[j]));
      int q=dp[POS(i-1,j)]+(i+j-sum(bit,b[i]));
      dp[POS(i,j)]=p<q?p:q;
    }
  }
  printf("%d\n",dp[POS(n,n)]);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:31:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%d",s,&k);
     ^