#include<stdio.h>
int main(){
  int l,h,n,a,i;
  scanf("%d%d%d",&l,&h,&n);
  while(n--){
    i=0;
    scanf("%d",&a);
    if(a<l) i=l-a;
    else if(a>h) i--;
    printf("%d\n",i);
  }
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&l,&h,&n);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^