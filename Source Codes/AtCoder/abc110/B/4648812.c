#include <stdio.h>
#include <stdlib.h>
int ucm(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}
int main(){
  int n,m,i;
  scanf("%d%d",&n,&m);
  int x[n+1],y[m+1];
  scanf("%d%d",&x[0],&y[0]);
  for(i=1;i<n+1;i++)scanf("%d",&x[i]);
  for(i=1;i<m+1;i++)scanf("%d",&y[i]);
  qsort(x,n+1,sizeof(int),ucm);
  qsort(y,m+1,sizeof(int),ucm);
  if(x[n]<y[0])printf("No War");
  else printf("War");
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&x[0],&y[0]);
   ^
./Main.c:11:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<n+1;i++)scanf("%d",&x[i]);
                     ^
./Main.c:12:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<m+1;i++)scanf("%d",&y[i]);
                     ^