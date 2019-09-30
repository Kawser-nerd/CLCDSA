#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long ll;
#define mfor(i,a,b) for(int i=(a);i<(b);++i)
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

	ll N, M;
	cin >> N >> M;
	vector<P> ab;
	rep(i, N) {
		ll A, B;
		cin >> A >> B;
		ab.push_back(make_pair(A, B));
	}

	sort(ab.begin(), ab.end(), pairComp);


	ll ans = 0;
	rep(i, N) {
		if (M <= 0) {
			continue;
		}
		if (M < ab[i].second) {
			ans += M * ab[i].first;
			M = 0;
		}else {
			ans += ab[i].first * ab[i].second;
			M -= ab[i].second;
		}
	}
	cout << ans << endl;

    return 0;
}