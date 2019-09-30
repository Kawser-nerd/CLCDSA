#include <stdio.h>

int main(void)
{
	int n,j,k;
	char s[100];
	
	scanf("%s%d",s,&n);
	
	if(n%5!=0){
		j=n/5;
		k=n%5-1;
	}else{
		j=n/5-1;
		k=4;
	}
	
	
	printf("%c",s[j]);
	printf("%c\n",s[k]);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%d",s,&n);
  ^