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

int N;
ll D;
int parent[1000010];
ll val[1000010];
ll low[1000010],high[1000010];

vector <pair <ll, int> > v;

void main2(void){
	int i,j;
	
	cin >> N >> D;
	
	ll x,prod,add,mod;
	
	cin >> x >> prod >> add >> mod;
	REP(i,N){
		val[i] = x;
		x = (x * prod + add) % mod;
	}
	
	cin >> x >> prod >> add >> mod;
	REP(i,N){
		if(i != 0) parent[i] = (int)(x % i);
		x = (x * prod + add) % mod;
	}
	
	low[0] = high[0] = val[0];
	for(i=1;i<N;i++){
		low[i] = min(val[i], low[parent[i]]);
		high[i] = max(val[i], high[parent[i]]);
	}
	
	v.clear();
	REP(i,N) if(high[i] - low[i] <= D){
		v.push_back(make_pair(high[i] - D, -1));
		v.push_back(make_pair(low[i], 1));
	}
	
	int ans = 0;
	sort(v.begin(),v.end());
	int tmp = 0;
	REP(i,v.size()){
		tmp += v[i].second;
		ans = max(ans, -tmp);
	}
	
	cout << ans << endl;
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
