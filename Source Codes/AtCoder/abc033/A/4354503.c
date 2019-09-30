#include <stdio.h>

int main(void){
	
	char n[100];
	int count;
	
	scanf("%s",n);
	
	for(int i=0;n[i]!='\0';i++){
		if(n[i]==n[i+1]){
			count++;
		}
	}
	
	if(count==3){
		printf("SAME\n");
	}else{
		printf("DIFFERENT\n");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",n);
  ^