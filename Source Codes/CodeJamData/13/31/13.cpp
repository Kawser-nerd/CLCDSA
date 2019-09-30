#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 1000010
char s[N];
bool nz(char c)
{
	return (c!='a')&&(c!='e')&&(c!='i')&&(c!='o')&&(c!='u');
}
int main()
{
	int _;scanf("%d",&_);
	for(int __=1;__<=_;__++)
	{
		scanf("%s",s);int n=strlen(s),m;
		scanf("%d",&m);
		ll S=0;int la=0;
		for(int l=0,i=0;i<n;i++)
			if(!nz(s[i]))l=0;else
			{
				l++;l=min(l,m);
				if(l==m)
				{
					S+=(ll)(i-la-m+2)*(n-i);
					la=i-m+2;
				}
			}
		printf("Case #%d: %I64d\n",__,S);
	}
	return 0;
}