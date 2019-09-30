#include<stdio.h>
#include<stdlib.h>

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++){
    scanf("%d",a+i);
    a[i]--;
  }
  int *b=(int *)calloc(n+1,sizeof(int));
  for(i=0;i<n;i++) b[a[i]]=i;
  b[n]=-1;
  int c=0;
  int *ans=(int *)calloc(n,sizeof(int));
  ans[a[0]]=c;
  for(i=1;i<n;i++){
    if(b[a[i-1]+1]>b[a[i]+1]) c++;
    ans[a[i]]=c;
  }
  if(c>=26){
    puts("-1");
    return;
  }
  for(i=0;i<n;i++) putchar('A'+ans[i]);
  puts("");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",a+i);
     ^