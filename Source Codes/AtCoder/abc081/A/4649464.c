#include<stdio.h>

int main(){
	char a[3];
  	int i,count;
  	
  
  scanf("%s",a);
  
  for(i=0;i < 3;i++){
    
    if(a[i] == '1'){
      count++;
    }
    
  }
    
  
  	
 printf("%d",count);
  
 
	return 0;
  
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",a);
   ^