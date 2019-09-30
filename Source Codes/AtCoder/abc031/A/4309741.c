#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
  return *(int*)a - *(int*)b;
}

int main(void){
  int a,d,n,m;
  scanf("%d%d",&a,&d);
  if(a>=d) printf("%d\n",a*(d+1));
  else printf("%d\n",(a+1)*d);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&d);
   ^