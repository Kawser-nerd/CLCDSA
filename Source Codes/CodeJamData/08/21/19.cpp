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


int main()
{
	int tc;
	cin >> tc;
	for(int ic=0;ic<tc;ic++)
	{
		int n;
		int64 A,B,C,D,x0,y0,M;
		cin >> n >> A >> B >> C >> D >> x0 >> y0 >> M;
		vector<ii> v;
		int64 X=x0,Y=y0;
		v.push_back(ii((int)x0,(int)y0));
		for(int i=1;i<=n-1;i++)
		{
			  X=(A*X+B)%M;
			  Y=(C*Y+D)%M;
			  v.push_back(ii((int)X,(int)Y));
		}
		map<ii,int> m;
		for(int i=0;i<sz(v);i++)
		{
			v[i].first%=3;
			v[i].second%=3;
			m[v[i]]++;
		}
		vector<pair<ii,int64> > w;
		for(map<ii,int>::iterator it=m.begin();it!=m.end();it++)
		{
			w.push_back(mp(it->first,(int64)(it->second)));
		}
		int64 res=0;
#define v botva
		for(int i=0;i<sz(w);i++)
			for(int j=i+1;j<sz(w);j++)
				for(int k=j+1;k<sz(w);k++){
					if(((int64)w[i].first.first+(int64)w[j].first.first+(int64)w[k].first.first)%3!=0) continue;
					if(((int64)w[i].first.second+(int64)w[j].first.second+(int64)w[k].first.second)%3!=0) continue;									
					res+=(w[i].second*w[j].second*w[k].second);
				}
		for(int i=0;i<sz(w);i++)
			for(int j=0;j<sz(w);j++)
			{
				if(i==j) continue;
				int k=j;
				if(((int64)w[i].first.first+(int64)w[j].first.first+(int64)w[k].first.first)%3!=0) continue;
				if(((int64)w[i].first.second+(int64)w[j].first.second+(int64)w[k].first.second)%3!=0) continue;
				res+=(w[i].second*w[j].second*(w[j].second-1LL))/2LL;
			}
		for(int i=0;i<sz(w);i++)
		{
			int k=i;
			int j=i;
			if(((int64)w[i].first.first+(int64)w[j].first.first+(int64)w[k].first.first)%3!=0) continue;
			if(((int64)w[i].first.second+(int64)w[j].first.second+(int64)w[k].first.second)%3!=0) continue;
			res+=(w[i].second*(w[i].second-1LL)*(w[i].second-2LL))/6LL;
		}
		printf("Case #%d: ",ic+1);
		cout << res;
		printf("\n");
	}
	return 0;
}
