#include<stdio.h>
int main()
{
	int A,B;
	 scanf("%d",&A);
	 scanf("%d",&B);
  if(A<=8 && B<=8){
	  printf("Yay!");
  }else{
	  printf(":(");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&A);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&B);
   ^