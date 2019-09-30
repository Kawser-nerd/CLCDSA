#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<cctype>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<list>
#define ull unsigned long long 
#define ll long long 
#define pii pair<int,int >
#define iiii pair<int,pii >
#define MAXN 100020
 
using namespace std;

int X[MAXN],Y[MAXN],par[MAXN],Rank[MAXN];
vector<pii >vX,vY;
set<pair<int,pii > >Set;
ll res=0;
int n;

void fInit(int n)
{
	for(int i=0;i<n;i++)
	{
		par[i]=i;
		Rank[i]=0;
	}
}

int fFind(int x)
{
	if(par[x]==x) return x;
	return par[x]=fFind(par[x]);
}

ll fUnite(int x,int y)
{
	x=fFind(x);y=fFind(y);
	if(x==y)return false;
	if(Rank[x]<Rank[y])par[x]=y;
	else
	{
		par[y]=x;
		if(Rank[x]==Rank[y])Rank[x]++;
	}
	return 1;
}

int know(int x,int y)
{
	return abs(x-y);
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",X+i,Y+i);
		vX.push_back(make_pair(X[i],i));
		vY.push_back(make_pair(Y[i],i));
	}
	
	fInit(n);
	sort(vX.begin(),vX.end());
	sort(vY.begin(),vY.end());
	
	for(int i=0;i<n-1;i++)
	{
		Set.insert(make_pair(know(vX[i+1].first,vX[i].first),make_pair(vX[i+1].second,vX[i].second)));
		Set.insert(make_pair(know(vY[i+1].first,vY[i].first),make_pair(vY[i+1].second,vY[i].second)));
	}
	
	while (Set.size())
	{
		set<iiii >::iterator it=Set.begin();
		res+=fUnite((*it).second.second,(*it).second.first)*(ll)(*it).first;
		Set.erase(it);
	}
	
	cout<<res<<endl;
	
	return 0;	
}