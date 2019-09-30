#include <iostream>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

#define mp make_pair

const int maxn = 100005;

int px[maxn],py[maxn],f[maxn];

pair<int,int> sx[maxn],sy[maxn];

int fnd(int x){
	if (f[x]==x)return x;
	return f[x]=fnd(f[x]);
}

int n;

int dist(int u,int v){
	return min(abs(px[u]-px[v]),abs(py[u]-py[v]));
}

int unit(int x,int y){
	x=fnd(x);
	y=fnd(y);
	if (x==y)return 0;
	f[x]=y;
	return 1;
}

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		scanf("%d%d",&px[i],&py[i]);
		f[i]=i;
		sx[i]=mp(px[i],i);
		sy[i]=mp(py[i],i);
	}
	sort(sx,sx+n);
	sort(sy,sy+n);
	set < pair < int , pair < int , int > > >st;
	for (int i=0;i<n-1;++i){
		st.insert(mp(dist(sx[i].second,sx[i+1].second),mp(sx[i].second,sx[i+1].second)));
		st.insert(mp(dist(sy[i].second,sy[i+1].second),mp(sy[i].second,sy[i+1].second)));
	}
	long long res=0;
	while ((int)st.size()){
		auto cur= *(st.begin());
		st.erase(cur);
		int u=cur.second.first,v=cur.second.second;
		res += unit(u,v) * dist(u,v);
	}
	printf("%lld\n",res);
	return 0;
}