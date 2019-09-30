#include <stdio.h>
#include <string.h>

int main(){
	char str[120];
	int n,m,k;
	
	scanf("%d%d",&n,&m);

		if(n*3==m*4){printf("4:3\n");}
	
		if(n*9==m*16){printf("16:9\n");}
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^