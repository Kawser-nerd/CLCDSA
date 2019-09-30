#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 200000
#define LL long long
#define INF 1000000000000000000
int n,top;
char s[MAXN+5],stk[MAXN+5];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='T')
		{
			if(stk[top]=='S')top--;
			else stk[++top]='T';
		}
		else stk[++top]='S';//
	}
	printf("%d",top);
}