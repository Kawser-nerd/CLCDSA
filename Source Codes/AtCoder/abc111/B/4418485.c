#include <stdio.h>

int main(void)
{
	char n[100];
	int no;
	
	scanf("%s",n);
	
	if(n[0]>n[1]){
		no=1;
	}else if(n[0]==n[1]){
		if(n[2]<=n[1]){
			no=1;
		}else{
			no=2;
		}
	}else{
		no=2;
	}
	
	switch(no){
		case 1:
			printf("%c%c%c\n",n[0],n[0],n[0]);
			break;
		case 2:
			printf("%c%c%c\n",n[0]+1,n[0]+1,n[0]+1);
			break;
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",n);
  ^