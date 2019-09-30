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

typedef long long ll;

vector <ll> x;
set <ll> sums[70];
bool choose[70];

vector <pair <ll, ll> > func(vector <pair <ll, ll> > v){
	int i;
	
	if(v[0].second >= 2){
		x.push_back(0);
		REP(i,v.size()) v[i].second /= 2;
		return v;
	}
	
	ll d = v[1].first - v[0].first;
	x.push_back(d);
	
	map <ll, ll> mp,mp2;
	REP(i,v.size()) mp[v[i].first] += v[i].second;
	REP(i,v.size()){
		ll val = v[i].first;
		if(mp[val] > 0){
			ll tmp = mp[val];
			mp2[val] += tmp;
			mp[val] -= tmp;
			mp[val+d] -= tmp;
		}
	}
	
	vector <pair <ll, ll> > w;
	snuke(mp2,itr) w.push_back(*itr);
	sort(w.begin(),w.end());
	return w;
}

void main2(void){
	int i;
	
	x.clear();
	
	int P;
	cin >> P;
	vector <pair <ll, ll> > v(P);
	
	REP(i,P) cin >> v[i].first;
	REP(i,P) cin >> v[i].second;
	
/*	int P = (1<<13);
	vector <pair <ll, ll> > v(P);
	REP(i,P){
		v[i].first = -1234 + i;
		v[i].second = (1ll<<47);
	}
*/	
	ll target = -v[0].first;
	
	ll T = 0;
	REP(i,P) T += v[i].second;
	int N = 0;
	while(T > 1){
		T /= 2;
		N++;
	}
	
	REP(i,N) v = func(v);
	
	sort(v.begin(),v.end());
	REP(i,70) sums[i].clear();
	
	sums[0].insert(0);
	REP(i,N) snuke(sums[i],itr){
		ll y = (*itr);
		sums[i+1].insert(y);
		sums[i+1].insert(y + x[i]);
	}
	
	REP(i,70) choose[i] = false;
	for(i=N-1;i>=0;i--){
		if(sums[i].find(target - x[i]) != sums[i].end()){
			target -= x[i];
			choose[i] = true;
		}
	}
	
	vector <ll> ans;
	REP(i,N) if(choose[i]) ans.push_back(-x[i]); else ans.push_back(x[i]);
	sort(ans.begin(),ans.end());
	REP(i,N) cout << ' ' << ans[i];
	cout << endl;
}

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d:", tc+1);
		main2();
	}
	return 0;
}
