#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main(void)
{
	//?????
	
	char s[100010];
	int len;
	long int ans;
	int i;
	
	//????????
	scanf("%s",&s);
	
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	ans=0;
	len=strlen(s);
	for(i=0;i<len;i++){
		if(s[i]=='U'){
			ans=ans+len+i-1;
//			printf("ans=%d\n",ans);
		}else{
			ans=ans+2*len-i-2;
//			printf("ans=%d\n",ans);
		}
	}
	
//	printf("??????\n");
	
	//??
	
	
	printf("%ld",ans);
	
	
//	printf("???????\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100010]’ [-Wformat=]
  scanf("%s",&s);
        ^
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",&s);
  ^