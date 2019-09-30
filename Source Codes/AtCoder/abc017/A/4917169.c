#include<stdio.h>

int main(){
  int s1,e1,a1,b1;
  scanf("%d %d",&s1,&e1);
    a1=s1*e1;
  	b1=a1/10;
  int s2,e2,a2,b2;
  scanf("%d %d",&s2,&e2);
  	a2=s2*e2;
  	b2=a2/10;
  int s3,e3,a3,b3;
  scanf("%d %d",&s3,&e3);
  	a3=s3*e3;
  	b3=a3/10;
  int A,B;
  A=b1+b2+b3;
  printf("%d\n",A);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&s1,&e1);
   ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&s2,&e2);
   ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&s3,&e3);
   ^