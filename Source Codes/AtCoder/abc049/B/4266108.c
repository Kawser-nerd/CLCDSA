#include <stdio.h>
#include <string.h>

int main(void)
{
	int h,w;
	scanf("%d%d",&h,&w);
	char s[h][w+1],cpy[h][w+1];
	int i;
	for(i=0;i<=h-1;i++)
		{
		fprintf(stderr,"\ni=%d",i);
		scanf("%s",s[i]);
		strcpy(cpy[i],s[i]);
		}
	
	for(i=0;i<=h-1;i++)
		{
		printf("%s\n%s\n",s[i],cpy[i]);
		}
	
	

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&h,&w);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s[i]);
   ^