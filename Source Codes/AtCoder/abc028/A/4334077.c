#include<stdio.h>
int main (){
int a;
  scanf ("%d",&a);
  if (a==100){
  printf ("Perfect\n");
  }
  else if (a>89 && a<100){
  printf ("Great\n");
  }
  else if (a>59 && a<90){
  printf ("Good\n");
  }
  else if (a<60){
  printf ("Bad\n");
  }
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%d",&a);
   ^