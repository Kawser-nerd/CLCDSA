#include <stdio.h>
int main (){
int l,h,k,i,g;
scanf ("%d%d%d",&l,&h,&k);
for (i=0;i<k;i++){
scanf ("%d",&g);
if (g<l+1){
printf ("%d\n",l-g);
}
  else if (g>l && g<h+1){
  printf ("0\n");
  }
  else{
  printf ("-1\n");
  }
}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d%d%d",&l,&h,&k);
 ^
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d",&g);
 ^