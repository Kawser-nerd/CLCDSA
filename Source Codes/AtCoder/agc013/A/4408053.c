#include<stdio.h>
#include<stdlib.h>

int calc(int *a,int n){
  int i=0;
  int ans=0;
  while(i<n){
    ans++;
    int j=i+1;
    while(j<n && a[j]==a[i]) j++;
    if(j>=n) break;
    int sign=a[j]-a[j-1]>0?1:-1;;
    while(j<n && sign*(a[j]-a[j-1])>=0) j++;
    i=j;
  }
  return ans;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  int x=calc(a,n);
  printf("%d\n",x);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:24:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^