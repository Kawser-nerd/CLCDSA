#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

void run(void){
  int n,c,k;
  scanf("%d%d%d",&n,&c,&k);
  int *t=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",t+i);
  qsort(t,n,sizeof(int),cmp);
  int ans=0;
  i=0;
  while(i<n){
    int j=i;
    while(j<n && t[j]-t[i]<=k && j-i<c) j++;
    ans++;
    i=j;
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&c,&k);
   ^
./Main.c:13:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",t+i);
                    ^