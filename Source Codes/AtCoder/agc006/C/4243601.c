#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

void run(void){
  int n;
  scanf("%d",&n);
  int *x=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",x+i);
  int m;
  int64 k;
  scanf("%d%lld",&m,&k);
  int *s=(int *)calloc(n-1,sizeof(int));
  for(i=0;i<n-1;i++) s[i]=i;
  while(m--){
    int a;
    scanf("%d",&a);
    a-=2;
    int swap=s[a];
    s[a]=s[a+1];
    s[a+1]=swap;
  }
  int *t=(int *)calloc(n-1,sizeof(int));
  int *tmp=(int *)calloc(n-1,sizeof(int));
  for(i=0;i<n-1;i++) t[i]=i;
  while(k>0){
    if(k&1){
      for(i=0;i<n-1;i++) tmp[i]=s[t[i]];
      for(i=0;i<n-1;i++) t[i]=tmp[i];
    }
    for(i=0;i<n-1;i++) tmp[i]=s[s[i]];
    for(i=0;i<n-1;i++) s[i]=tmp[i];
    k>>=1;
  }
  int *y=(int *)calloc(n-1,sizeof(int));
  for(i=0;i<n-1;i++) y[i]=x[i+1]-x[i];
  for(i=0;i<n-1;i++) tmp[i]=y[t[i]];
  for(i=0;i<n-1;i++) y[i]=tmp[i];
  int64 ans=x[0];
  printf("%lld\n",ans);
  for(i=1;i<n;i++){
    ans+=y[i-1];
    printf("%lld\n",ans);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:11:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",x+i);
                    ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%lld",&m,&k);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^