#include <stdio.h>
#include <string.h>

int main(void)
{
	int z,o,l,i;
	char s[100000];

	z=0;
	o=0;

	scanf("%s",s);

	l=strlen(s);

	for(i=0; i<l; i++)
	{
		if(s[i]=='0') z=z+1;
		else o=o+1;
	}

	if(z==0||o==0) printf("0\n");
	else if(z<o) printf("%d\n",z*2);
	else  printf("%d\n",o*2);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^