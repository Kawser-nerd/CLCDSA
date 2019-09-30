#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
  return *(int*)a - *(int*)b;
}
int main(void){
  int n,i;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  qsort(a,n,sizeof(int),cmp);
  printf("%d\n",a[n-1]-a[0]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^