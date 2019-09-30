#include <stdio.h>
#include <string.h>


int main(void)
{
	char od[51],ev[51];
	int i,lenod,lenev;
	scanf("%s%s",od,ev);
	lenod=strlen(od);
	lenev=strlen(ev);
	fprintf(stderr,"lenod=%d lenev=%d\n",lenod,lenev);
	if(lenod==lenev)
		{
		for(i=0;i<=lenod-1;i++)
			{printf("%c%c",od[i],ev[i]);}
		}
	else
		{
		for(i=0;i<=lenod-2;i++)
			{printf("%c%c",od[i],ev[i]);}
		printf("%c",od[i]);
		}

	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s",od,ev);
  ^