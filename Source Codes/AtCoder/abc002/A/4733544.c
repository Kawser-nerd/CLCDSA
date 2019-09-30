#include <stdio.h>
 
int main(){
	int i,j;
   scanf("%d %d",&i,&j);
  if(i>j) printf("%d\n",i);
  else printf("%d\n",j);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d %d",&i,&j);
    ^