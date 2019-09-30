#include <cstdio>
#include <string>

#define N 70
#define E 40

int test,t;
char a[N];
int n,i,c,base;
int dig[E];
bool used0;
int maxd;
long long ans;

inline int code(char c)
{
	if(c>='0' && c<='9') 
		return c-'0';else
		return 10+c-'a';
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&test); getchar();
	for(t=1;t<=test;t++)
	{
		gets(a);
		n=strlen(a);
		memset(dig,-1,sizeof(dig));
		c=code(a[0]);
		dig[c]=1;
		maxd=2;
		used0=0;
		for(i=1;i<n;i++)
		{
			c=code(a[i]);
			if(dig[c]==-1)
			{
				if(!used0)
				{
					dig[c]=0;
					used0=1;
				}else
				{
					dig[c]=maxd++;
				}
			}
		}
		base=0;
		for(i=0;i<n;i++)
		{
			c=code(a[i]);
			if(dig[c]+1>base)
				base=dig[c]+1;
		}
		ans=0;
		for(i=0;i<n;i++)
			ans=ans*base+dig[code(a[i])];
		printf("Case #%d: %I64d\n",t,ans);
	}
	return 0;
}
