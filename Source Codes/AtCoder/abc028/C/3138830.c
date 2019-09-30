#include <stdio.h>
int main()
{
  int data[5];
  scanf("%d %d %d %d %d",&data[0],&data[1],&data[2],&data[3],&data[4]);
  int i,j,tmp = 0;
  for(i=0;i<4;i++){
	  for(j=4 ; j > i+1 ; j--){
		  if(data[j]<data[j-1]){
			  tmp = data[j];
			  data[j] = data[j-1];
			  data[j-1] = tmp;
		  }
	  }
  }
  if(data[0]+data[3]+data[4]>data[1]+data[2]+data[4])
	  printf("%d\n",data[0]+data[3]+data[4]);
  else printf("%d\n",data[1]+data[2]+data[4]);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d %d",&data[0],&data[1],&data[2],&data[3],&data[4]);
   ^