#include<stdio.h>
int main (){
int n,l,h,b=0,a,ha;
scanf ("%d%d%d%d",&n,&l,&h,&ha);
   if (ha>l-1 && ha<h+1){
  b++;
  }
for (int i=1;i<n;i++){
 scanf ("%d",&a);
  ha=ha+a;
  if (ha<0){
  ha=0;
  }
  if (ha>l-1 && ha<h+1){
  b++;
  }
}
  printf ("%d\n",b);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d%d%d%d",&n,&l,&h,&ha);
 ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf ("%d",&a);
  ^