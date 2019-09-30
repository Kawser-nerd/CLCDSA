#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cctype>

#define mp make_pair
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v.size()))

using namespace std;

typedef long long int64;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<string> vs;

template<class T> T abs(T x){return x>0 ? x:(-x);}
template<class T> T sqr(T x){return x*x;}

const int maxp=2000000;

vector<int64> v;
bool u[maxp+100];

int w[maxp];

void clear()
{
	memset(w,-1,sizeof(w));
}

vi tmp;

int get(int x)
{
	tmp.clear();
	while(w[x]!=-1 && w[x]!=x)
		tmp.push_back(x),x=w[x];
	for(int i=0;i<sz(tmp);i++)
		w[tmp[i]]=x;
	return x;
}

void merge(int x,int y)
{
	x=get(x),y=get(y);
	if(rand()%2)
		swap(x,y);
	w[x]=y;
}

int main()
{	
	memset(u,1,sizeof(u));
	u[0]=u[1]=false;
	for(int i=2;i<=maxp;i++)
	{
		if(!u[i]) continue;
		v.push_back(i);
		for(int j=i+i;j<=maxp;j+=i)
			u[j]=false;
	}
	int tc;
	cin >> tc;
	for(int ic=0;ic<tc;ic++)
	{
		int64 a,b,p;
		cin >> a >> b >> p;
		clear();
		for(int i=0;i<sz(v);i++)
		{
			if(v[i]<p) continue;
			int64 k=(a-1LL)/v[i];
			k++;
			k*=v[i];
			for(int64 j=k;j+v[i]<=b;j+=v[i])
				merge(j-a,j+v[i]-a);
		}
		int res=1;
		for(int64 i=a;i<=b;i++)
		{
			if(get(i-a)!=get(0))
				res++,merge(i-a,0);
		}
		printf("Case #%d: %d\n",ic+1,res);
	}
	return 0;
}
