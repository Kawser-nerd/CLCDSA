#include<cstdio>
#include<cstring>
#define MAXN 1000006
#include<algorithm>
using namespace std;
int ans,n,l,cnt,r,q[MAXN];
char s[MAXN],t[MAXN];
int main()
{
	//freopen("blank.in","r",stdin);
	//freopen("blank.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%s",t+1);
	l=1;
	if(!strcmp(s+1,t+1))
	{
		printf("0");
		return 0;
	}
	for(int i=n,j=n;i>=1;i--)
	{
		if(t[i]==t[i-1]) continue;
		j=min(i,j);
		while(j&&t[i]!=s[j]) 
			j--;
		if(!j)
		{
			printf("-1");
			return 0;
		}
		while(l<=r)
		{
			if(q[l]-(r-l)>i) l++;
			else break;
		}
		q[++r]=j;
		if(i!=j) ans=max(ans,r-l+1);
	}
	printf("%d\n",++ans);
}