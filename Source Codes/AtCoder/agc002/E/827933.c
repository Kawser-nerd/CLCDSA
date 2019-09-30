#include <stdio.h>
#include <stdlib.h>
int cmp_int(const void *a,const void *b){
  return -(*(int*)a - *(int*)b);
}
int N;
int a[100000];
int main(){
  int i,j;
  int x,y;
  int t;
  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d",&a[i]);
  qsort(a,N,sizeof(int),cmp_int);
  
  i=0;
  while(i<N-1 && i+1<a[i+1])i++;
  t=i;
  while(i<N-1 && t<a[i+1]){j++;i++;}
  x=a[t]-t-1;
  y=j;
  //printf("i=%d x=%d y=%d\n",t,x,y);
  if(x%2==0 && y%2==0)printf("Second\n");
  else printf("First\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:13:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<N;i++)scanf("%d",&a[i]);
                   ^