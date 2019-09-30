#include<stdio.h>

int ans;
int w[100][100];
int w1[100][100];
int r,c,R,C;
int dirr[]={0,1,0,-1};
int dirc[]={1,0,-1,0};

void SOLVE(int day)
{
	int ar[6][6],ac[6][6],wx[6][6];
	int ok,i,j,nr,nc,nowr,nowc;
	int curmax,x,y;

	if(ans==-1) return;

	if(w[r][c]>0)
	{
		if(ans < day) ans=day;
	}

	if(w[r][c]<=0) return;

	ok=1;
	for(i=0;i<4;i++)
		if( c+dirc[i]>=1 && c+dirc[i]<=C && r+dirr[i]>=1 && r+dirr[i]<=R && w[r+dirr[i]][c+dirc[i]]>0)
			ok=0;

	if(ok)
	{
		ans=-1;
		return;
	}

	for(i=1;i<=R;i++)
		for(j=1;j<=C;j++)
		{
			nowr=i;
			nowc=j;
			ar[nowr][nowc]=-1;
			curmax=-1;

			if(w[nowr][nowc]<=0) continue;

			for(x=0;x<4;x++)
			{
				nr=nowr+dirr[x];
				nc=nowc+dirc[x];

				if(nr>=1 && nr<=R && nc>=1 && nc<=C && curmax<=w[nr][nc] && w[nr][nc]>0)
				{
					if(curmax<w[nr][nc])
					{
						curmax=w[nr][nc];
						ar[nowr][nowc]=nr;
						ac[nowr][nowc]=nc;
					}
					else if(nr<ar[nowr][nowc] || (nr==ar[nowr][nowc] && nc<ac[nowr][nowc]) )
					{
						ar[nowr][nowc]=nr;
						ac[nowr][nowc]=nc;
					}
					
				}
			}
		}

		for(i=0;i<4;i++)
		{
			nr=r+dirr[i];
			nc=c+dirc[i];

			if(nr>=1 && nr<=R && nc>=1 && nc<=C && w[nr][nc]>0)
			{
				ar[r][c]=nr;
				ac[r][c]=nc;

				for(x=1;x<=R;x++)
					for(y=1;y<=C;y++)
						wx[x][y]=w[x][y];
				
				for(x=1;x<=R;x++)
					for(y=1;y<=C;y++)
					{
						if(ar[x][y]!=-1)
						{
							w[ ar[x][y] ][ ac[x][y] ] -= wx[x][y];
						}

					}

				SOLVE(day+1);

				for(x=1;x<=R;x++)
					for(y=1;y<=C;y++)
						w[x][y]=wx[x][y];
				
			}
		}

}

int main()
{
	freopen("b2.in","r",stdin);
	freopen("b2.out","w",stdout);

	int T,ks,i,j;

	scanf("%d",&T);
	for(ks=1;ks<=T;ks++)
	{
		scanf("%d%d%d%d",&C,&R,&c,&r);
		for(i=1;i<=R;i++)
			for(j=1;j<=C;j++)
				scanf("%d",&w[i][j]);

		ans=0;
		SOLVE(0);

		if(ans==-1) printf("Case #%d: forever\n",ks);
		else printf("Case #%d: %d day(s)\n",ks,ans);
	}

	return 0;
}