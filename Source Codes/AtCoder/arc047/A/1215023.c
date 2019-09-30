#include <stdio.h>

int main(void)
{
	int n,l,i,count=0,tab=1;
	char s[110000];
	scanf("%d %d %s",&n,&l,s);
		
	for(i=0;i<=n-1;i++){
		if(s[i]=='+'){
			tab++;
		} else{
			tab--;
		}
		if(tab>l){
			count++;
			tab=1;
		}
	}
	printf("%d\n",count);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %s",&n,&l,s);
  ^