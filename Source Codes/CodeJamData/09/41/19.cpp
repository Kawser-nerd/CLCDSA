#include<cstdio>

const int maxn=50;
char p[maxn];
int pos[maxn],pos2[maxn];
int n,t,cases;
int ID[maxn];

int main()
{
	freopen("input.txt","r",stdin);

	for (scanf("%d",&t);t;t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%s",p);
			pos[i]=1;
			for (int j=0;j<n;j++)
			if (p[j]=='1') pos[i]=j+1;
			ID[i]=-1;
			pos2[i]=i;
		}
		int res=0;
		for (int i=1;i<=n;i++)
		{
			int k;
			for (int j=i;j<=n;j++)
			if (pos[j]<=i)
			{
				k=j;break;
			}

			res+=k-i;
			for (int j=k-1;j>=i;j--) pos[j+1]=pos[j];
		}

		printf("Case #%d: %d\n",++cases,res);
	}
}
			