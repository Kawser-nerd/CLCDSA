#include<stdio.h>
#include<algorithm>
using namespace std;
struct tt
{
	int x,id;
	bool operator <(const tt &o)const
	{
		return x<o.x;
	}
}lb[5000+32],lc[5000+32];
int la[5000+32],a[5000+32],b[5000+32],c[5000+32];
int u[5000+32];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int cc,o;
	int i,j,k,now,ans,g,n;
	scanf("%d",&cc);
	for(o=1;o<=cc;o++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",a+i,b+i,c+i);
			la[i]=a[i];
		}
		sort(la,la+n);
		ans=0;
		for(i=0;i<n;i++)
			if(!i||la[i]!=la[i-1])
			{
				g=0;
				for(j=0;j<n;j++)
					if(a[j]<=la[i])
					{
						lb[g].x=b[j];
						lb[g].id=j;
						lc[g].x=c[j];
						lc[g].id=j;
						g++;
					}
				sort(lb,lb+g);
				sort(lc,lc+g);
				k=g-1;
				now=0;
				for(j=0;j<n;j++)
					u[j]=2;
				for(j=0;j<g;j++)
				{
					u[lb[j].id]|=1;
					if(u[lb[j].id]==3)
						now++;
					while(k>=0&&la[i]+lb[j].x+lc[k].x>10000)
					{
						if(u[lc[k].id]==3)
							now--;
						u[lc[k].id]^=2;
						k--;
					}
					if(now>ans)
						ans=now;
				}
			}
		printf("Case #%d: %d\n",o,ans);	
	}
	return 0;
}
		
	
