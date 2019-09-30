#include <stdio.h>
#include <string.h>

int T,t,n,i,j,k;
double ans;
bool u[2000];
int a[2000];

int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			a[i]--;
		}
		memset(u,0,sizeof(u));
		for(i=0;i<n;i++)
			if(!u[i])
			{
				k=1;
				u[i]=1;
				for(j=a[i];j!=i;j=a[j])
				{
					u[j]=1;
					k++;
				}
				if(k!=1)
					ans+=k;
			}
		printf("Case #%d: %.12lf\n",++t,ans);
	}
	return 0;
}