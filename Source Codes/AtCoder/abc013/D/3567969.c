#include<stdio.h>
#include<stdlib.h>

void run(void){
  int n,m,d;
  scanf("%d%d%d",&n,&m,&d);
  int *a=(int *)calloc(n+1,sizeof(int));
  int i;
  for(i=0;i<=n;i++) a[i]=i;
  for(i=0;i<m;i++){
    int b;
    scanf("%d",&b);
    int s=a[b];
    a[b]=a[b+1];
    a[b+1]=s;
  }
  int *b=(int *)calloc(n+1,sizeof(int));
  for(i=1;i<=n;i++) b[a[i]]=i;
  int *ans=(int *)calloc(n+1,sizeof(int));
  int *stack=(int *)calloc(n,sizeof(int));
  for(i=1;i<=n;i++){
    if(ans[i]>0) continue;
    int len=0;
    stack[len++]=i;
    int now=b[i];
    while(now!=i){
      stack[len++]=now;
      now=b[now];
    }
    int j;
    for(j=0;j<len;j++) ans[stack[j]]=stack[(d+j)%len];
  }
  for(i=1;i<=n;i++) printf("%d\n",ans[i]);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&m,&d);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&b);
     ^