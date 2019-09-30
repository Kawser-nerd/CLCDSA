#include<iostream>
#include<queue>
using namespace std;
int n,a[2][100001],d[2][20][100001],e[2][20][100001];
int query(int parity,int l,int r)
{
	int k=0;l>>=1;r-=parity;r>>=1;
	while((1<<(k+1))<=r-l+1)k++;
	//fprintf(stderr,"Querying d(%d,%d,%d) = %d && d(%d,%d,%d) = %d\n",parity,k,l,d[parity][k][l],parity,k,r-(1<<k)+1,d[parity][k][r-(1<<k)+1]);
	return min(d[parity][k][l],d[parity][k][r-(1<<k)+1]);
}
int pos(int parity,int l,int r)
{
	int k=0;l>>=1;r-=parity;r>>=1;
	while((1<<(k+1))<=r-l+1)k++;
	//fprintf(stderr,"Posing e(%d,%d,%d) (d = %d) && e(%d,%d,%d) (d = %d)\n",parity,k,l,d[parity][k][l],parity,k,r-(1<<k)+1,d[parity][k][r-(1<<k)+1]);
	return d[parity][k][l]>d[parity][k][r-(1<<k)+1]?e[parity][k][r-(1<<k)+1]:e[parity][k][l];
}
struct range
{
	int l,r;
	range(int left,int right):l(left),r(right){}
	bool operator<(const range &b)const{return query(l&1,l,r)>query(b.l&1,b.l,b.r);}
};
int main()
{
	scanf("%d",&n);
	for(int i=0,j=0;i<n;i+=2,j++)scanf("%d%d",a[0]+j,a[1]+j);
	for(int i=0,j=0;i<n;i+=2,j++)
	{
		d[0][0][j]=a[0][j];
		d[1][0][j]=a[1][j];
		e[0][0][j]=i;
		e[1][0][j]=i+1;
	}
	for(int i=1;(1<<i)<=n/2;i++)
		for(int j=0;j+(1<<i)<=n/2;j++)
			for(int k=0;k<2;k++)
				if(d[k][i-1][j]<d[k][i-1][j+(1<<(i-1))])
				{
					d[k][i][j]=d[k][i-1][j];
					e[k][i][j]=e[k][i-1][j];
				}
				else
				{
					d[k][i][j]=d[k][i-1][j+(1<<(i-1))];
					e[k][i][j]=e[k][i-1][j+(1<<(i-1))];
				}
#if 0
	for(int i=0;(1<<i)<=n/2;i++)
		for(int j=0;j+(1<<i)<=n/2;j++)
			for(int k=0;k<2;k++)fprintf(stderr,"d(%d,%d,%d)=%d\ne(%d,%d,%d)=%d\n\n",k,i,j,d[k][i][j],k,i,j,e[k][i][j]);
	fputs("Sparse Table Ended here.\n\n\n",stderr);
#endif
	priority_queue<range> q;
	q.push({0,n-1});
	while(!q.empty())
	{
		range u=q.top();q.pop();
		int p=pos(u.l&1,u.l,u.r-1),r=pos(u.r&1,p+1,u.r);
#if 0
		fprintf(stderr,"Fuck %d %d\n",u.l,u.r);
		if(r==-1)fprintf(stderr,"Error with %d %d %d -> %d\n\t%d %d %d => -1\n",u.l&1,u.l,u.r,p,u.r&1,p+1,u.r);
		fprintf(stderr,"Get %d => %d;\t%d => %d\n",p,query(u.l&1,u.l,u.r-1),r,query(u.r&1,p+1,u.r));
#endif
		printf("%d %d ",query(u.l&1,u.l,u.r-1),query(u.r&1,p+1,u.r));
		if(u.l<=p-1)q.push({u.l,p-1});
		if(p+1<=r-1)q.push({p+1,r-1});
		if(r+1<=u.r)q.push({r+1,u.r});
	}
	putchar('\n');
	return 0;
}