/*for large data*/
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;
int N[2];
vector<int>adj[2][100];
struct quad
{
	int a,b,c,d;
	quad(int _a,int _b,int _c,int _d)  {a=_a,b=_b,c=_c,d=_d;}
};
bool operator<(quad u,quad v)
{
	if (u.a!=v.a) return u.a<v.a;
	if (u.b!=v.b) return u.b<v.b;
	if (u.c!=v.c) return u.c<v.c;
	return u.d<v.d;
}
map<quad,bool>M;
int TST[200][200][200],TOP;
int Check[2][100],dir[100],back[100];
vector<int>gad[2][100];
int dflow(int row,int u,int c)
{
	if (row==0)
	{
		int q,v;
		for (q=0;q<gad[0][u].size();q++)
		{
			v=gad[0][u][q];
			if (Check[1][v]>=c) continue;
			Check[1][v]=c;
			if (dflow(1,v,c))
			{
				dir[u]=v;
				back[v]=u;
				return 1;
			}
		}
		return 0;
	}
	else
	{
		if (back[u]<0) return 1;
		return dflow(0,back[u],c);
	}
}
int maxflow(int info,int n,int m)
{
	int q,w;
	for (q=0;q<n;q++) { gad[0][q].clear(); Check[0][q]=-1; dir[q]=-1; }
	for (q=0;q<m;q++) { gad[1][q].clear(); Check[1][q]=-1; back[q]=-1; }
	for (q=0;q<n;q++) for (w=0;w<m;w++) if (TST[info][q][w]) 
	{
		gad[0][q].push_back(w);
		gad[1][w].push_back(q);
	}
	int cnt=0;
	for (q=0;q<n;q++) cnt+=dflow(0,q,q);
	return cnt;
}
bool solve(quad st)
{
	if (M.find(st)==M.end()) //(a,b) >= (c,d)
	{
		if (adj[0][st.b].size()<adj[1][st.d].size()) return M[st]=false;
		int i,j,u,v,my=TOP++;
		int n=adj[0][st.b].size(),m=adj[1][st.d].size();
		for (i=0;i<n;i++) for (j=0;j<m;j++) 
		{
			u=adj[0][st.b][i],v=adj[1][st.d][j];
			TST[my][i][j]=0;
			if (u==st.a || v==st.c) continue;
			if (solve(quad(st.b,u,st.d,v))) TST[my][i][j]=1;
		}
		//find cover
		int needed=0;
		for (j=0;j<m;j++) if (adj[1][st.d][j]!=st.c) needed++;
		if (maxflow(my,n,m)>=needed) 
		{
			TOP--;
			return M[st]=true;
		}
		TOP--;
		return M[st]=false;
	}
	return M[st];
}
int main()
{
	int t,T,q,w,e,r,i;
	freopen("D-large.in","r",stdin);
	freopen("andoutput.txt","w",stdout);
	scanf("%d",&T);
	for (t=1;t<=T;t++)
	{
		fprintf(stderr,"%d %d\n",t,TOP);
		for (i=0;i<=1;i++)
		{
			scanf("%d",N+i);
			for (q=0;q<N[i];q++) adj[i][q].clear();
			for (q=0;q+1<N[i];q++)
			{
				int u,v;
				scanf("%d %d",&u,&v);
				u--;v--;
				adj[i][u].push_back(v);
				adj[i][v].push_back(u);
			}
		}
		M.clear();
		//solve(quad(1,0,0,1));
		bool flag=false;
		for (q=0;q<N[0];q++,fprintf(stderr,"%d\n",q)) for (w=0;w<N[1];w++) 
			if (solve(quad(-1,q,-1,w)))
			{
			
				flag=true;
			}
		printf("Case #%d: ",t);
		if (flag) printf("YES\n");
		else printf("NO\n");
			
	}
	return 0;
}