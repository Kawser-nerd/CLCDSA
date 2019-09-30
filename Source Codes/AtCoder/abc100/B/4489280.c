#include<stdio.h>
int main()
{
	int D,N;
	 scanf("%d",&D);
	 scanf("%d",&N);

	 if(N<100){
  if(D==0){
	  printf("%d",1*N);
	 }
if(D==1){
	  printf("%d",100*N);
}
if(D==2){
	  printf("%d",10000*N);
}
	 }
	 if(N==100){

			 if(D==0){
			 	  printf("%d",101);
			 	 }
			 if(D==1){
			 	  printf("%d",10100);
			 }
			 if(D==2){
			 	  printf("%d",1010000);

		 }

	 }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&D);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^