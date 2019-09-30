#include <stdio.h>
int main (){
int a,b,c,x,i,k=0,j,l;
  scanf ("%d%d%d%d",&a,&b,&c,&x);
for (i=0;i<a+1;i++){
if (x-(i*500)>-1){
for (j=0;j<b+1;j++){
if (x-(i*500)-(j*100)>-1){
for (l=0;l<c+1;l++){
if (x-(i*500)-(j*100)-(l*50)==0){
k++;
}
}
}
  else{
  break;
  }
}
}
else{
break;
}
}
printf ("%d",k);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%d%d%d%d",&a,&b,&c,&x);
   ^