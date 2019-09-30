#include <stdio.h>
int N;
int L;
int a[100001];
int main(){
  int i,j;
  int flag=0;
  scanf("%d %d",&N,&L);
  for(i=1;i<=N;i++)scanf("%d",&a[i]);
  for(i=1;i<N;i++){
    if(a[i]+a[i+1]>=L)flag=1;
  }
  if(flag==0){
    printf("Impossible\n");
    return 0;
  }
  printf("Possible\n");
  i=1;
  while(i<N){
    if(a[i]+a[i+1]>=L)break;
    i++;
  }
  for(j=1;j<i;j++)printf("%d\n",j);
  for(j=N-1;j>i;j--)printf("%d\n",j);
   printf("%d\n",i);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&N,&L);
   ^
./Main.c:9:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=N;i++)scanf("%d",&a[i]);
                    ^