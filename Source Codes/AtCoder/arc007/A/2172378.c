#include<stdio.h>
int main()
{
	int i;
	char x,s[55];
	scanf("%c",&x);
	scanf("%s",s);
	i=0;
	while(s[i]!='\0')
	{
		if(s[i]!=x)
			printf("%c",s[i]);
		i++;
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c",&x);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^