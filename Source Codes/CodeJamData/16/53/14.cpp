#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define MAXV 1010

int parent[MAXV],rank[MAXV];

void init(int n){
	int i;
	REP(i,n) {parent[i] = i; rank[i] = 1;}
}

int root(int x){
	if(parent[x] != x) parent[x] = root(parent[x]);
	return parent[x];
}

void connect(int x, int y){
	int rx=root(x),ry=root(y);
	if(rx == ry) return;
	if(rank[rx] > rank[ry]) {parent[ry] = rx; rank[rx] += rank[ry];}
	if(rank[rx] <= rank[ry]) {parent[rx] = ry; rank[ry] += rank[rx];}
}

int N,S;
double x[1010],y[1010],z[1010],vx[1010],vy[1010],vz[1010];
double dist[1010][1010];
bool used[1010];

void main2(void){
	int i,j;
	
	cin >> N >> S;
	REP(i,N) cin >> x[i] >> y[i] >> z[i] >> vx[i] >> vy[i] >> vz[i];
	
	REP(i,N) REP(j,N){
		double dx = x[i] - x[j];
		double dy = y[i] - y[j];
		double dz = z[i] - z[j];
		dist[i][j] = sqrt(dx*dx+dy*dy+dz*dz);
	}
	
	vector <pair <double, pair <int, int> > > v;
	REP(i,N) REP(j,i){
		v.push_back(make_pair(dist[i][j], make_pair(i, j)));
	}
	
	sort(v.begin(),v.end());
	
	init(N);
	
	double last = 0.0;
	REP(i,v.size()){
		last = v[i].first;
		int s = v[i].second.first;
		int t = v[i].second.second;
		connect(s, t);
		if(root(0) == root(1)){
			printf("%.9f\n", last);
			return;
		}
	}
}

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc+1);
		main2();
	}
	return 0;
}
