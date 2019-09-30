#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[201];
	scanf("%s",s);
	int len=strlen(s);

	fprintf(stderr,"%s\nlen=%d\n",s,len);
	int ans=0,i;
	while(ans==0)
		{
		len-=2;
		{fprintf(stderr,"\n%d",len); }
		ans=len;
		for(i=0;i<=len/2-1;i++)
			{
			if(s[i]!=s[len/2+i])
				{ans=0; break;}
			}
		if(len<0){fprintf(stderr,"\nstop len<0\n"); break;}
		}
	printf("\n%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^