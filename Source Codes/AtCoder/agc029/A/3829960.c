#include<stdio.h>
#include<string.h>
int main()
{
	char s[200005];
	scanf("%s",s);
	int i;
	double ans=0;
	double x=0;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='W')
		   ans+=x;
		else
		   x++;
	}
	printf("%.0lf\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^