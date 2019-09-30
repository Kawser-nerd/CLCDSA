#include<stdio.h>

int main(){
  int n;
  long x=0,y=0,t[1000],a[1000],j;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    scanf("%ld %ld",&t[i],&a[i]);
  x=t[0];
  y=a[0];
  for(int i=1;i<n;i++){
    if(x/t[i]>y/a[i])
      j=x/t[i];
    else
      j=y/a[i];
    if(x>j*t[i]||y>j*a[i])
      j++;
    x=t[i]*j;
    y=a[i]*j;
  }
  printf("%ld\n",x+y);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld",&t[i],&a[i]);
     ^