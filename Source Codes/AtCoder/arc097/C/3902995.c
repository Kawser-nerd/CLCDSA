#include<stdio.h>
#include<stdlib.h>

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
  int *dp=(int *)calloc(2*(n+1),sizeof(int));
  int *bit=(int *)calloc(2*n+1,sizeof(int));
  bit[0]=2*n;
  dp[0]=0;
  for(i=1;i<=n;i++){
    add(bit,w[i],1);
    dp[i]=dp[i-1]+(i-sum(bit,w[i]));
  }
  int now=0;
  for(i=1;i<=n;i++){
    initBIT(bit);
    int inv=0;
    for(j=1;j<=i;j++){
      add(bit,b[j],1);
      inv+=j-sum(bit,b[j]);
    }
    int next=now^(n+1);
    dp[next]=inv;
    for(j=1;j<=n;j++){
      add(bit,w[j],1);
      int p=dp[next+j-1]+(i+j-sum(bit,w[j]));
      int q=dp[now+j]+(i+j-sum(bit,b[i]));
      dp[next+j]=p<q?p:q;
    }
    now=next;
  }
  printf("%d\n",dp[now+n]);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:29:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%d",s,&k);
     ^