#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 200006
using namespace std;
char s[MAXN];
int n;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=n;i>=1;i--)
	{
		s[i]=s[i-1];
		if(s[i+1]==s[i])
		{
			printf("%d %d",i,i+1);
			return 0;
		}
	}
	for(int i=1;i<=n-2;i++)
		if(s[i]==s[i+2])
		{
			printf("%d %d",i,i+2);
			return 0;
		}
	printf("-1 -1");
}