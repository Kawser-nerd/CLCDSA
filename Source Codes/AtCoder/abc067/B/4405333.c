#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
  return *(int*)b - *(int*)a;
}

int main(void){
  int n,k,i,ans=0;
  scanf("%d %d",&n,&k);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  qsort(a,n,sizeof(int),cmp);
  for(i=0;i<k;i++){
    ans+=a[i];
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&k);
   ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^