#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  for(i=n-1;i>0;i--) if(a[i]>a[i-1]+1) break;
  if(i>0 || a[0]!=0){
    puts("-1");
    return;
  }
  int64 ans=0;
  i=n-1;
  while(i>0){
    ans+=a[i];
    while(i>0 && a[i]==a[i-1]+1) i--;
    i--;
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:11:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^