#include <stdio.h>
int main (){
int i,j,n,m,x,y,a,b,max=-100,min=100;
  scanf ("%d%d%d%d",&n,&m,&x,&y);
for (i=0;i<n;i++){
scanf ("%d",&a);
  if (max<a){
 max=a; 
  }
}
for (i=0;i<m;i++){
  scanf ("%d",&b);
 if (min>b){
 min=b; 
  }
}
if (max>x && max<min && min<y+1){
printf ("No War");
}
  else {
  printf ("War");
  }
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%d%d%d%d",&n,&m,&x,&y);
   ^
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d",&a);
 ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%d",&b);
   ^