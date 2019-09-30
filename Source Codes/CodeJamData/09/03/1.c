#include<stdio.h>
#include<string.h>
char src[20]="welcome to code jam",str[600];
int ti,n,i,j,k,dp[20][600],res;
int main()
{
	scanf("%d\n",&n);
	for (ti=1;ti<=n;ti++)
	{
		gets(str);
		printf("Case #%d: ",ti);
		for (i=0;str[i];i++)
			if (str[i]=='w') dp[0][i]=1;
			else dp[0][i]=0;
		for (i=1;i<19;i++)
			for (j=0;str[j];j++)
			{
				dp[i][j]=0;
				if (str[j]==src[i])
					for (k=0;k<j;k++)
						dp[i][j]=(dp[i][j]+dp[i-1][k])%10000;
			}
		res=0;
		for (i=0;str[i];i++) res=(res+dp[18][i])%10000;
		if (res<1000) printf("0");
		if (res<100) printf("0");
		if (res<10) printf("0");
		printf("%d\n",res);
	}
	return 0;
}
