#include<stdio.h>
#include<assert.h>

#define MIN(A,B) ((A) < (B) ? (A) : (B))
#define MAX(A,B) ((A) > (B) ? (A) : (B))

#define LL __int64

LL t[3][3];
LL cnt[3][3];
LL x[100002],y[100002];

int dx[]={0,0,0,1,1,1,2,2,2};
int dy[]={0,1,2,0,1,2,0,1,2};

__int64 nCr(__int64 N,__int64 R)
{
	if(N==0 && R) return 0;
	if(N==0 && R==0) return 1;
	if(N && !R) return 1;
	if(R>N) return 0;
	if(R==1) return N;
	if(R==2) return (N*(N-1))/2;
	if(R==3) return (N*(N-1)*(N-2))/6;

	assert(0);

	return 0;
}

int main()
{
	freopen("a-large.in","r",stdin);
	freopen("output-large.out","w",stdout);

	int i,j,k,a,b;
	int Q,ks;
	LL n,A,B,C,D,x0,y0,M,ans,temp;

	scanf("%d",&Q);
	for(ks=1;ks<=Q;ks++)
	{
		scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&n,&A,&B,&C,&D,&x0,&y0,&M);
		x[0]=x0;
		y[0]=y0;
		for(i=1;i<n;i++)
		{
			x[i]=(A * x[i-1] + B) % M;
			y[i]=(C * y[i-1] + D) % M;
		}

		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				t[i][j]=0;

		for(i=0;i<n;i++)
			t[ x[i]%3 ][ y[i]%3 ]++;

		ans=0;
		for(i=0;i<9;i++)
			for(j=i;j<9;j++)
				for(k=j;k<9;k++)
				{
					for(a=0;a<3;a++) for(b=0;b<3;b++) cnt[a][b]=0;
					cnt[ dx[i] ][ dy[i] ]++;
					cnt[ dx[j] ][ dy[j] ]++;
					cnt[ dx[k] ][ dy[k] ]++;

					if( (dx[i]+dx[j]+dx[k])%3==0 && (dy[i]+dy[j]+dy[k])%3==0) ;
					else continue;

					temp=1;
					for(a=0;a<3;a++) for(b=0;b<3;b++) temp*=nCr(t[a][b],cnt[a][b]);
					if(temp)
						ans+=temp;
				}

		printf("Case #%d: %I64d\n",ks,ans);
	}

	return 0;
}