#include <stdio.h>
int main (){
int a,b,i;
scanf ("%d",&b);
  a=b;
for (i=0;i<10000000;i++){
  if(a==4){
break;
}
  if (a%2==0){
  a=a/2;
  }
  else{
    a=3*a+1;
  }

}
  if(b>2){
  printf ("%d",i+4);
  }
  else if (b==2){
   printf ("4");
  } 
  else if (b==1){
   printf ("4");
  } 
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d",&b);
 ^