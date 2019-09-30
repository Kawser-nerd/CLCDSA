#include <stdio.h>
int main (){
 char s[102],u;
  int a,b,i,k,h,j,l;
  scanf ("%s",s);
  scanf ("%d",&a);
  for (i=0;i<a;i++){
  scanf ("%d %d",&k,&h);
    b=h-k;
    l=0;
    for (b;b>0;b=b-2){
    u=s[k-1+l];
    s[k-1+l]=s[h-1-l];
    s[h-1-l]=u;
      l++;
  }
  }
  printf ("%s\n",s);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%s",s);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%d",&a);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%d %d",&k,&h);
   ^