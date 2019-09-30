#include <stdio.h>
int main(){
int a,b,c,d=0;
scanf ("%d%d",&a,&b);
if ((b-b%10)/10 == 0){
c=a*10+b;
}
else if ((b-b%100)/100 == 0){
c=a*100+b;
}
else {
c=a*1000+b;
}
for (int i=0;i<c*100;i++){
if (c == i*i){
  d=1;
}
}
if (d==1){
printf ("Yes");
}
else{
printf ("No");
}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d%d",&a,&b);
 ^