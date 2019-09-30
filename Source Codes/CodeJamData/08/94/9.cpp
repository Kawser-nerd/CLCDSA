#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
	int cc,o;
	int n,m,x,y,i,j,k,p,q,ans,now,kk[4][2]={1,0,0,1,-1,0,0,-1};
	char str[32][32];
	int lx[1024],ly[1024],d[32][32],d2[32][32];
	scanf("%d",&cc);
	for(o=1;o<=cc;o++)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%s",str[i]);
		p=q=0;
		lx[q]=0;
		ly[q]=0;
		memset(d,0XFF,sizeof(d));
		d[0][0]=0;
		q++;
		while(p<q)
		{
			for(k=0;k<4;k++)
			{
				x=kk[k][0]+lx[p];
				y=kk[k][1]+ly[p];
				if(x>=0&&x<n&&y>=0&&y<m)
					if(str[x][y]!='.')
						if(d[x][y]==-1)
						{
							d[x][y]=d[lx[p]][ly[p]]+1;
							lx[q]=x;
							ly[q]=y;
							q++;
						}
			}
			p++;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				if(str[i][j]=='T')
					if(i||j)
						break;
			if(j<m)
				break;
		}
		if(i==n)
		{
			ans=0;
			for(i=0;i<n;i++)
				for(j=0;j<m;j++)
					if(d[i][j]!=-1)
						ans+=d[i][j];
			printf("Case #%d: %d\n",o,ans);
			continue;
		}
		ans=0;
		now=d[i][j];
		p=q=0;
		lx[q]=i;
		ly[q]=j;
		memset(d2,0XFF,sizeof(d2));
		d2[i][j]=0;
		q++;
		while(p<q)
		{
			for(k=0;k<4;k++)
			{
				x=kk[k][0]+lx[p];
				y=kk[k][1]+ly[p];
				if(x>=0&&x<n&&y>=0&&y<m)
					if(str[x][y]!='.')
						if(d2[x][y]==-1)
						{
							d2[x][y]=d2[lx[p]][ly[p]]+1;
							lx[q]=x;
							ly[q]=y;
							q++;
						}
			}
			p++;
		}
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(d[i][j]!=-1)
				{
					if(d[i][j]<d2[i][j])
						ans+=d[i][j];
					else
						ans+=d2[i][j];
				}
		for(i=0;i<=now;i++)
			if(now-i<i)
				ans+=i+i-now;
		printf("Case #%d: %d\n",o,ans);
	}
	return 0;
}







		
	
