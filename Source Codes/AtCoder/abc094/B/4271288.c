#include<stdio.h>
int main(){
  int n,m,x,a[100],i,g=0,l=0;
  scanf("%d%d%d",&n,&m,&x);
  for(i=0;i<m;i++){
    scanf("%d",&a[i]);
    a[i]>x?g++:l++;
  }
  printf("%d",g>l?l:g);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&m,&x);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^