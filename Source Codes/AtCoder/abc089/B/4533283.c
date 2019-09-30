#include <stdio.h>

int main(void)
{
	int n,count;
	char s[110];
	
	count=0;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%c",&(s[i]));
	}
	
	for(int i=0;i<n;i++){
		if(s[i]=='Y'){
			count++;
			break;
		}
	}
	
	if(count!=0){
		printf("Four\n");
	}else{
		printf("Three\n");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c",&(s[i]));
   ^