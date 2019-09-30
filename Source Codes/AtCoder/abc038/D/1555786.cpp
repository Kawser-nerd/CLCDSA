#include <iostream>
#include <array>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <random>
#include <queue>
#include <iomanip>

using namespace std;

using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vll = std::vector<ll>;
using vpll = std::vector<pll>;

pll arr[1000010] = {};

int rmqarr[300000 + 10];

/*
??????????
k*2+1
k*2+2
??????
(k-1)/2
*/

template<typename T>
class RMQ {
public:
	int n;

	RMQ(int N, T a) {
		for (int i = 0; i < 300000 + 10; i++)
			rmqarr[i] = a;

		n = 1;
		while (n<N) n *= 2;

	}

	T query(int a, int b) {
		return query(a, b, 0, 0, n);
	}

	T query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return INT_MIN;
		if (a <= l && r <= b) return rmqarr[k];

		else {
			T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return max(vl, vr);
		}

	}

	void update(int k, T a) {
		k += n - 1;

		rmqarr[k] = a;

		while (k > 0) {
			k = (k - 1) / 2;
			rmqarr[k] = max(rmqarr[k * 2 + 1], rmqarr[k * 2 + 2]);
		}
	}
private:

};


//?????
ll gcd(ll a, ll b) {
	if ( a%b == 0 )
		return b;
	return gcd(b,a%b);
}

//?????
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
	ll n,a,b,c,q,k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
		arr[i].second *= -1;
	}

	sort(arr,arr+n);

	RMQ<int> rmq(100010,0);
	
	for (int i = 0; i < n; i++) {
		ll tmp = rmq.query(0, arr[i].second*-1);
		rmq.update(arr[i].second*-1,tmp+1);
	}
	cout << rmq.query(0, 100010) << endl;

}