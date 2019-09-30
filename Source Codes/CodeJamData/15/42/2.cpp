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

int N,V,X;
int v[110],x[110];

double get_small(double vv){
	double ans = 0.0;
	int i;
	REP(i,N){
		double tmp = min(vv, (double)v[i]);
		vv -= tmp;
		ans += tmp * x[i];
	}
	return ans;
}

double get_big(double vv){
	double ans = 0.0;
	int i;
	for(i=N-1;i>=0;i--){
		double tmp = min(vv, (double)v[i]);
		vv -= tmp;
		ans += tmp * x[i];
	}
	return ans;
}

double func(int X){
	int i;
	
	if(X == x[0] || X == x[N-1]){
		double ans = 0.0;
		REP(i,N) if(x[i] == X) ans += v[i];
		return ans;
	}
	
	double low = 0.0, high = 0.0;
	REP(i,N) high += v[i];
	REP(i,100){
		double mid = (low + high) / 2.0;
		double small = get_small(mid);
		double big = get_big(mid);
		if(X * mid >= small && X * mid <= big) low = mid; else high = mid;
	}
	
	return high;
}

int input(void){
	double tmp;
	cin >> tmp;
	return (int)(tmp * 10000.0 + 0.5);
}

void main2(void){
	int i;
	
	cin >> N;
	V = input();
	X = input();
	
	vector <pair <int, int> > p;
	REP(i,N){
		int vv = input();
		int xx = input();
		p.push_back(make_pair(xx, vv));
	}
	sort(p.begin(),p.end());
	REP(i,N){
		x[i] = p[i].first;
		v[i] = p[i].second;
	}
	
	if(!(X >= x[0] && X <= x[N-1])){
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	
	double ans = func(X);
	printf("%.9f\n", V / ans);
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
