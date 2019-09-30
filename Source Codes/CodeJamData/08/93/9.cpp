#include<stdio.h>
#include<algorithm>
using namespace std;
int lx[5],my[1<<5],get[5],ans,n,m,v[5][5];
void tt(int id)
{
	int s,now,j;
	for(s=0;s<(1<<m);s++)
	{
		lx[id]=s;
		if(id)
		{
			for(j=0;j<m;j++)
			{
				now=0;
				now+=my[get[j]&lx[id-1]];
				now+=my[get[j]&lx[id]];
				if(id-2>=0)
					now+=my[get[j]&lx[id-2]];
				if(now!=v[id-1][j])
					break;
			}
			if(j<m)
				continue;
		}
		if(id==n-1)
		{
			for(j=0;j<m;j++)
			{
				now=0;
				now+=my[get[j]&lx[id]];
				if(id-1>=0)
					now+=my[get[j]&lx[id-1]];
				if(now!=v[id][j])
					break;
			}
			if(j<m)
				continue;
			if(my[lx[n/2]]>ans)
				ans=my[lx[n/2]];
			continue;
		}
		tt(id+1);
	}
}
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int cc,o;
	int i,j;
	my[0]=0;
	for(i=1;i<(1<<5);i++)
		my[i]=my[i>>1]+(i&1);
	for(i=0;i<5;i++)
	{
		get[i]=0;
		get[i]|=1<<i;
		get[i]|=1<<(i+1);
		if(i-1>=0)
			get[i]|=1<<(i-1);
	}
	scanf("%d",&cc);
	for(o=1;o<=cc;o++)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",v[i]+j);
		ans=0;
		tt(0);
		printf("Case #%d: %d\n",o,ans);
	}
	return 0;
}
		
	
