#include <stdio.h>
#include <string.h>

int main(){
	char str[120];
	int n,m,k;
	
	scanf("%d%d%d",&n,&m,&k);

	if(n>=m)
	{
		printf("%d",k/m);
	}else{
		printf("%d",k/n);
		}
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&m,&k);
  ^