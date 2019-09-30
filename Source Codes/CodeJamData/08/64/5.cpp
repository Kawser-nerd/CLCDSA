#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <sstream>
#include <map>
#include <assert.h>
using namespace std;
typedef long long int llint;
#define N 100
#define EPS 1e-10
#define INF 1e10
#define LOW(x) ((((x)^((x)-1))&x))
#define Debug(x) cout<<#x<<"=\""<<x<<"\""<<endl;
#define Hline() do{cout<<"-------------------------------"<<endl;}while(0)
const int two[]={1,1<<1,1<<2,1<<3,1<<4,1<<5,1<<6,1<<7,1<<8,1<<9,1<<10,
1<<11,1<<12,1<<13,1<<14,1<<15,1<<16,1<<17,1<<18,1<<19,1<<20,
1<<21,1<<22,1<<23,1<<24,1<<25,1<<26,1<<27,1<<28,1<<29,1<<30};
const int dir[][2]={{-1,0},{0,1},{1,0},{0,-1}};
const char dname[]="NWSE";
//const char dname[]="URDL";
const double PI=acos(-1.0);
//*****************************************//
double Euclid_dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
template<class T>
string convert(vector<T> vv)
{
	ostringstream re;
	for(int i=0;i<vv.size();i++)
	{
		if(i)re<<" ";
		re<<vv[i];
	}
	return re.str();
}
template<class T>
string convert(T vv)
{
	ostringstream re;
	re<<vv;
	return re.str();
}
template<class T>
vector<T> parse(const string& ss,const char* cut)
{
	vector<T> re;
	for(int j=0;j<ss.size();j++)
	{
		string s;
		while(j<ss.size()&&NULL==strchr(cut,ss[j]))
			s+=ss[j++];
		if(!s.empty())
		{
			T tmp;
			istringstream is(s);
			is>>tmp;
			re.push_back(tmp);
		}
	}
	return re;
}
namespace match
{
bool rset[N];
int rmatch[N];
bool augment(int v,const vector<vector<int> >& edge)
{
	for(int i=0;i<edge[v].size();i++)
	{
		int u=edge[v][i];
		if(rset[u])continue;
		rset[u]=true;
		if(rmatch[u]==-1||augment(rmatch[u],edge))
		{
			rmatch[u]=v;
			return true;
		}
	}
	return false;
}
bool maxMatch(int n,int m,const vector<vector<int> >& edge)
{
	memset(rset,false,sizeof(bool)*m);
	memset(rmatch,0xff,sizeof(int)*m);
	int re=0;
	for(int i=0;i<n;i++)
	{
		if(!augment(i,edge))return false;
		memset(rset,false,sizeof(bool)*m);
	}
	return true;
}
};
bool can[N][N];
vector<int> son1[N],son2[N];
vector<vector<int> > tedge1,tedge2;
void DFS(int v,int f,vector<int> son[],const vector<vector<int> >& tedge)
{
	son[v].clear();
	for(int i=0;i<tedge[v].size();i++)
	{
		int u=tedge[v][i];
		if(u==f)continue;
		DFS(u,v,son,tedge);
		son[v].push_back(u);
	}
	//cout<<"parent "<<v<<endl;
//	for(int i=0;i<son[v].size();i++)
//		cout<<son[v][i]<<" ";
//	cout<<endl;
}
bool DP(int a,int b)
{
	const int m=son1[a].size();
	const int n=son2[b].size();
	if(m<n)return false;
	if(n==0&&m==0)return true;
	vector<vector<int> > edge(son2[b].size());
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(DP(son1[a][j],son2[b][i]))
				edge[i].push_back(j);
		}
	}
	bool re=match::maxMatch(son2[b].size(),son1[a].size(),edge);
	//cout<<"root "<<a<<" and "<<b<<endl;
	//cout<<" size "<<m<<" "<<n<<endl;
	//cout<<" match "<<(re?"Yes":"No")<<endl;
	return re;
}
int main()
{
	int ca=1,t;
	for(cin>>t;t--;)
	{
		bool ans=false;
		int n,m;
		cin>>n;
		tedge1.clear();tedge1.resize(n);
		for(int i=1;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			a--;b--;
			tedge1[a].push_back(b);
			tedge1[b].push_back(a);
		}
		cin>>m;
		assert(m<=n);
		tedge2.clear();tedge2.resize(m);
		for(int i=1;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			a--;b--;
			tedge2[a].push_back(b);
			tedge2[b].push_back(a);
		}
		//Hline();
		DFS(0,-1,son2,tedge2);
		//Hline();
		for(int i=0;i<n;i++)
		{
		//	Hline();
			DFS(i,-1,son1,tedge1);
			//Hline();
			if(DP(i,0))
			{
				ans=true;
				break;
			}
		}
		cout<<"Case #"<<ca++<<": "<<(ans?"YES":"NO")<<endl;
	}
	return 0;
}
