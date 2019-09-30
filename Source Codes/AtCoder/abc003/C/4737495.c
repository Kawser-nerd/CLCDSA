#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
  return *(int*)a - *(int*)b;
}

int main(void){
  int n,k,i;
  double ans=0;
  scanf("%d %d",&n,&k);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  qsort(a,n,sizeof(int),cmp);
  for(i=n-k;i<n;i++){
    ans=(double)((ans+a[i])/2);
  }
  printf("%f\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&k);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^