#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
  return *(int*)a - *(int*)b;
}

int main(void){
  int n,x,i,ans=0;
  scanf("%d %d",&n,&x);
  int m[n];
  for(i=0;i<n;i++){
    scanf("%d",&m[i]);
    x=x-m[i];
  }
  qsort(m,n,sizeof(int),cmp);
  while(x>=0){
    ans++;
    x-=m[0];
  }
  printf("%d\n",ans+n-1);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&x);
   ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&m[i]);
     ^