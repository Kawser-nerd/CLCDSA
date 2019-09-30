#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int mini(int a,int b){
  if(a>b) return b;
  return a;
}

int cmp(const void *a,const void *b){
  return *(int*)a - *(int*)b;
}

int main(void){
  int n,k,i;
  scanf("%d %d",&n,&k);
  int h[n],sub[n-1],min;
  for(i=0;i<n;i++) scanf("%d",&h[i]);
  qsort(h,n,sizeof(int),cmp);
  min = h[k-1]-h[0];
  for(i=k;i<n;i++) min = mini(min,h[i]-h[i-k+1]);
  printf("%d\n",min);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&k);
   ^
./Main.c:18:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",&h[i]);
                    ^