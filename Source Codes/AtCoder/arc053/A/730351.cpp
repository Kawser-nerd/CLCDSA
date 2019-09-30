#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<fstream>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<memory>
#include<functional>
#include <iomanip>


using namespace std;

#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define F(i,j,k) fill(i[0],i[0]+j*j,k)
#define P(p) cout<<(p)<<endl;
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define INF (1<<28)
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef long long ll;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int extgcd(int a, int b, int& x, int& y) {
	int d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else {
		x = 1; y = 0;
	}
	return d;
}

bool is_prime(ll n) {
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (ll i = 3; i * i <= n; i+=2) {
		if (n % i == 0) return false;
	}
	return n != 1;
}

vector<int> divisor(int n) {
	vector<int> res;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			res.pb(i);
			if (i != n / i) res.pb(n / i);
		}
	}
	return res;
}

map<int, int> prime_factor(int n) {
	map<int, int> res;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			++res[i];
			n /= i;
		}
	}
	if (n != 1) res[n] = 1;
	return res;
}

long long MOD = 1000000007ll;
ll mod_pow(ll x, ll n, ll mod) {
	if (n == 0) return 1;
	ll res = mod_pow(x * x % mod, n / 2, mod);
	if (n & 1) res = res * x % mod;
	return res;
}

bool is_kadomatsu(int a, int b, int c) {
	if (a == b || b == c || c == a) return false;
	if (b > a && b > c) return true;
	if (a > b && c > b) return true;
	return false;
}


int main() {

	int H, W;
	cin >> H >> W;

	P(H*(W - 1) + W*(H - 1));


	return 0;
}