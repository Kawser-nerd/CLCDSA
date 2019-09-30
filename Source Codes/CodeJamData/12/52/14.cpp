#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
int n,m;
bool val(int x,int y)
{
	if(1<=x&&x<=n&&1<=y&&y<=n+x-1)return 1;
	if(n<x&&x<=n*2-1&&x-n+1<=y&&y<=n*2-1)return 1;
	return 0;
}
int co(int x,int y)
{
	if(x==n&&y==1)return 0;
	if(x==1&&y==1)return 1;
	if(x==1&&y==n)return 2;
	if(x==n&&y==n*2-1)return 3;
	if(x==n*2-1&&y==n*2-1)return 4;
	if(x==n*2-1&&y==n)return 5;
	return -1;
}
int fo(int x,int y)
{
	if(y==1)return 0;
	if(x==1)return 1;
	if(y==x+n-1)return 2;
	if(y==n*2-1)return 3;
	if(x==n*2-1)return 4;
	if(y==x-n+1)return 5;
	return -1;
}
int dx[6]={-1,-1,0,0,1,1},dy[6]={-1,0,-1,1,0,1};
#define pct __builtin_popcount
#define M 10010
#define P (n*2+5)
int p[M],vr,vb,vf,f[M],g[M];
map<int,int> A;
int fa(int x){return f[x]==x?x:(f[x]=fa(f[x]));}
void mer(int x,int y)
{
	if(fa(x)==fa(y))return;
	g[f[y]]|=g[f[x]],f[f[x]]=f[y];
}
bool v[6010][6010];int f2[6010*6010];
int fa2(int x){return f2[x]==x?x:(f2[x]=fa2(f2[x]));}
int main()
{
	int _;scanf("%d",&_);
	for(int __=1;__<=_;__++)
	{
		scanf("%d%d",&n,&m);
		for(int i=0,x,y;i<m;i++)scanf("%d%d",&x,&y),p[i]=x*P+y;
		vr=vb=vf=M;
		memset(f,0,sizeof f),
		memset(g,0,sizeof g);
		for(int i=0;i<m;i++)
		{
			f[i]=i;
			int w=co(p[i]/P,p[i]%P);
			if(w!=-1)g[i]=1<<w;
		}
		A.clear();
		for(int i=0;i<m;i++)
		{
			for(int d=0;d<6;d++)
			{
				int x0=p[i]/P+dx[d],y0=p[i]%P+dy[d],p2=x0*P+y0;
				if(!val(x0,y0))continue;
				if(A.find(p2)!=A.end())mer(A[p2],i);
			}
			if(pct(g[fa(i)])>=2){vb=i+1;break;}
			A[p[i]]=i;
		}
		memset(f,0,sizeof f),
		memset(g,0,sizeof g);
		for(int i=0;i<m;i++)
		{
			f[i]=i;
			int w=fo(p[i]/P,p[i]%P);
			if(w!=-1&&co(p[i]/P,p[i]%P)==-1)g[i]=1<<w;
		}
		A.clear();
		for(int i=0;i<m;i++)
		{
			for(int d=0;d<6;d++)
			{
				int x0=p[i]/P+dx[d],y0=p[i]%P+dy[d],p2=x0*P+y0;
				if(!val(x0,y0))continue;
				if(A.find(p2)!=A.end())mer(A[p2],i);
			}
			if(pct(g[fa(i)])>=3){vf=i+1;break;}
			A[p[i]]=i;
		}
		memset(v,0,sizeof v);
		for(int i=0;i<m;i++)v[p[i]/P][p[i]%P]=1;
		memset(f,0,sizeof f);
		for(int i=1;i<=n*2;i++)
			for(int j=1;j<=n*2;j++)if(val(i,j)&&!v[i][j])f2[i*P+j]=i*P+j;
		for(int i=1;i<=n*2;i++)
			for(int j=1;j<=n*2;j++)if(val(i,j)&&!v[i][j])
			{
				for(int d=0;d<6;d++)
				{
					int x0=i+dx[d],y0=j+dy[d];
					if(!val(x0,y0))continue;
					if(v[x0][y0]||fa2(x0*P+y0)==fa2(i*P+j))continue;
					f2[fa2(x0*P+y0)]=fa2(i*P+j);
				}
				if(co(i,j)!=-1||fo(i,j)!=-1)f2[fa2(i*P+j)]=fa2(0);
			}
		for(int i=m-1;i>=0;i--)
		{
			int S=0,x=p[i]/P,y=p[i]%P;
			f2[x*P+y]=x*P+y;
			for(int d=0;d<6;d++)
			{
				int x0=x+dx[d],y0=y+dy[d];
				if(!val(x0,y0))continue;
				if(v[x0][y0]||fa2(x0*P+y0)==fa2(x*P+y))continue;
				if(fa2(x0*P+y0)!=fa2(0))S++;
				f2[fa2(x0*P+y0)]=fa2(x*P+y);
			}
			if(S)vr=i+1;
			v[x][y]=0;
			if(co(x,y)!=-1||fo(x,y)!=-1)f2[fa2(x*P+y)]=fa2(0);
		}
		printf("Case #%d: ",__);
		int mi=min(min(vr,vb),vf);
		if(mi==M)puts("none");else
		if(vb==mi)
			if(vf==mi)
				if(vr==mi)printf("bridge-fork-ring in move %d\n",mi);
				else printf("bridge-fork in move %d\n",mi);
			else if(vr==mi)printf("bridge-ring in move %d\n",mi);
				else printf("bridge in move %d\n",mi);
		else
			if(vf==mi)
				if(vr==mi)printf("fork-ring in move %d\n",mi);
				else printf("fork in move %d\n",mi);
			else if(vr==mi)printf("ring in move %d\n",mi);
				else printf("wrong-answer in move %d\n",mi);
	}
	return 0;
}
