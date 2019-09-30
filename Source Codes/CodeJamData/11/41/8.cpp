#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

vector <pair <double, double> > v; // speed, length

void main2(void){
	int N,i;
	double X,S,R,t,B,E,w;
	
	v.clear();
	
	cin >> X >> S >> R >> t >> N;
	REP(i,N){
		cin >> B >> E >> w;
		v.push_back(make_pair(w,E-B));
		X -= (E-B);
	}
	v.push_back(make_pair(0.0,X));
	
	sort(v.begin(),v.end());
	
	double ans = 0.0;
	REP(i,v.size()){
		double speed = v[i].first, dist = v[i].second;
		double run = min(t, dist / (speed + R));
		t -= run;
		double walk = (dist - run * (speed + R)) / (speed + S);
		ans += run + walk;
	}
	
	printf("%.9f\n",ans);
}

//////////////////////////////// multiple testcases ////////////////////////////////

int main(void){
	int T,t;
	scanf("%d",&T);
	REP(t,T){
		printf("Case #%d: ",t+1);
		main2();
	}
	return 0;
}
