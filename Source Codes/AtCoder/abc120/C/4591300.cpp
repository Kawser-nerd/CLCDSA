#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long ll;
#define mfor(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,n)  mfor(i,0,n)
#define all(x) (x).begin(),(x).end()

bool comp(const vector<int> &x, const vector<int> &y){
    return x[2] > y[2];
}

typedef pair<ll, ll> P;

bool pairComp(const P& x, const P& y) {
	return x.first < y.first;
}


int main(void){

	string s;
	cin >> s;

	int red = 0;
	int blue = 0;
	rep(i, s.size()) {
		if (s[i] == '0') {
			red++;
		}else {
			blue++;
		}
	}
	int ans = min(red, blue) * 2;

	cout << ans <<endl;

  return 0;
}