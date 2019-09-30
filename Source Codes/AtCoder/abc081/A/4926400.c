#include<stdio.h>
int main(){
  	int count=0,i;
	char a[3];
  
  	for(i=0;i<3;i++){
    	scanf("%c",&a[i]);
      	if(a[i]=='1')count++;
    }
  	printf("%d",count);
  	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
      scanf("%c",&a[i]);
      ^