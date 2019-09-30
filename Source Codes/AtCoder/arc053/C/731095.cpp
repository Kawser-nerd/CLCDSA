#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
using ulong = unsigned long;
using ll = long long;

struct AB{
	int a, b;
	bool operator<(const AB& ab) const{
		return a != ab.a ?  a < ab.a : b < ab.b;
	}
};
ll calcMax(vector<AB>& abs){
	ll ret = 0, pos = 0;
	for(AB ab : abs){
		pos += ab.a;
		ret = max(ret, pos);
		pos -= ab.b;
	}
	return ret;
}

int main(){
	int n;
	cin >> n;

	vector<AB> dec, inc;
	ll fin = 0;
	for(int i=0;i<n;i++){
		int a, b;
		cin >> a >> b;
		if(a < b){
			dec.push_back({a, b});
		}else{
			inc.push_back({b, a});
		}
		fin += a - b;
	}
	sort(dec.begin(), dec.end());
	sort(inc.begin(), inc.end());
	cout << max(calcMax(dec), calcMax(inc) + fin) << endl;
	return 0;

	ll minA = 1e9+1, minB = 1e9+1, maxA = -1, maxB = -1, minPos = 0;
	ll total = 0;
	vector<ll> moves;
	for(int i=0;i<n;i++){
		ll a, b;
		cin >> a >> b;
		minA = min(minA, a);
		minB = min(minB, b);
		maxA = max(maxA, a);
		maxB = max(maxB, b);
		//if mina and minb are updated at the same time
		total += a - b;
		moves.push_back(a - b);
		//minPos = min(minPos, total);
	}
	sort(moves.begin(), moves.end());
	for(ll l : moves){
		if(l > 0){ break; }
		minPos += l;
	}
	//cout << minPos << endl;
	cout << max(max(minA, total + minB), max(minPos + maxA, minPos + maxB)) << endl;
	return 0;
}