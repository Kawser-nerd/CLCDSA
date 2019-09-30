#include <stdio.h>

int main(void)
{
	char a,b,c,d,e,f;
	
	scanf("%c%c%c\n%c%c%c",&a,&b,&c,&d,&e,&f);

	if(a==f&&c==d&&b==e){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c%c%c\n%c%c%c",&a,&b,&c,&d,&e,&f);
  ^