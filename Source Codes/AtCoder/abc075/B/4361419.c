#include <stdio.h>

int main(void)
{
	int h,w,i,k;
	scanf("%d%d",&h,&w);
	char s[h+2][w+3];
	for(i=0;i<=h+1;i++)
		{
		if(i==0 || i==h+1)
			{for(k=0;k<=w+1;k++){s[i][k]='0';}}
		else	{scanf("%s",s[i]);}
		}
	for(i=1;i<=h;i++)
		{
		for(k=w+1;k>=0;k--)
			{
			if(k==w+1 || k==0){s[i][k]='0';}
			else {s[i][k]=s[i][k-1];}
			}
		}
	for(i=1;i<=h;i++)
		{
		for(k=1;k<=w;k++)
			{if(s[i][k]!='#')
				{
				s[i][k]='0';
				if(s[i-1][k-1]=='#'){s[i][k]++;}
				if(s[i-1][k]=='#'){s[i][k]++;}
				if(s[i-1][k+1]=='#'){s[i][k]++;}
				if(s[i][k-1]=='#'){s[i][k]++;}
				if(s[i][k+1]=='#'){s[i][k]++;}
				if(s[i+1][k-1]=='#'){s[i][k]++;}
				if(s[i+1][k]=='#'){s[i][k]++;}
				if(s[i+1][k+1]=='#'){s[i][k]++;}
				}
			}
		}
	for(i=1;i<=h;i++)
		{
		for(k=1;k<=w;k++)
			{printf("%c",s[i][k]);}
		printf("\n");
		}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&h,&w);
  ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   else {scanf("%s",s[i]);}
         ^