#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <stack>
#include <limits>
#include <climits>
#include <cassert>
#include <fstream>
#include <cstring>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <ciso646>
#include <set>
#include <array>
#include <unordered_map>

using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define inf 0x3f3f3f3f
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define VS vector<string>
#define VI vector<ll>
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define pi 2*acos(0.0)
#define INFILE() freopen("in0.txt","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define ll long long
#define ull unsigned long long
#define pii pair<ll,ll>
#define pcc pair<char,char>
#define pic pair<ll,char>
#define pci pair<char,ll>
#define eps 1e-14
#define FST first
#define SEC second
#define SETUP cin.tie(0), ios::sync_with_stdio(false), cout << setprecision(15)

namespace {
	struct input_returnner {
		ll N; input_returnner(ll N_ = 0) :N(N_) {}
		template<typename T> operator vector<T>() const { vector<T> res(N); for (auto &a : res) cin >> a; return std::move(res); }
		template<typename T> operator T() const { T res; cin >> res; return res; }
		template<typename T> T operator - (T right) { return T(input_returnner()) - right; }
		template<typename T> T operator + (T right) { return T(input_returnner()) + right; }
		template<typename T> T operator * (T right) { return T(input_returnner()) * right; }
		template<typename T> T operator / (T right) { return T(input_returnner()) / right; }
		template<typename T> T operator << (T right) { return T(input_returnner()) << right; }
		template<typename T> T operator >> (T right) { return T(input_returnner()) >> right; }
	};
	template<typename T> input_returnner in() { return in<T>(); }
	input_returnner in() { return input_returnner(); }
	input_returnner in(ll N) { return std::move(input_returnner(N)); }
}

const ll MOD = 1e9 + 7;

struct ModInt {
	ll v = 0;
	ModInt() {}
	template<class T> ModInt(const T& right) {
		v = right;
		if (v >= 0) v %= MOD;
		else v += ((-v) / MOD + 1)*MOD;
		v %= MOD;
	}
	void operator = (const ModInt& right) { v = right.v; }
	template<class T> void operator = (const T& right) {
		v = right;
		if (v >= 0) v %= MOD;
		else v = v += ((-v) / MOD + 1)*MOD;
		v %= MOD;
	}

	ModInt operator + (const ModInt& right) { return (v + right.v) % MOD; }
	ModInt operator - (const ModInt& right) { return (MOD - (v - right.v)); }
	ModInt operator * (const ModInt& right) { return (v * right.v) % MOD; }
	ModInt operator / (const ModInt& right) { return v / right.v; }

	void operator += (const ModInt& right) { v = (v + right.v) % MOD; }
	void operator -= (const ModInt& right) { v = (MOD - (v - right.v)); }
	void operator *= (const ModInt& right) { v = (v* right.v) % MOD; }
	void operator /= (const ModInt& right) { v = v / right.v; }

	bool operator == (const ModInt& right) { return v == right.v; }
};

ostream& operator << (ostream& os, const ModInt& value) {
	os << value.v;
	return os;
}

string YN[] = { "NO", "YES" };

void solve();
/// ---template---

#define int ll

int gcd(int a, int b) {
	return b != 0 ? gcd(b, a % b) : a;
}

signed main(void) {
	SETUP;
	solve();
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}

void solve() {
    int N; cin >> N;
    vector<vector<int> > F;
    vector<vector<int> > P;
    REP(i,N){
        vector<int> a(10); for(auto &A:a) cin >> A;
        F.push_back(a);
    }
    REP(j,N){
        vector<int> b(11); for(auto &a:b) cin >> a;
        P.push_back(b);
    }

    int res = -inf;
    for(int i=1;i<(1<<10);++i){
        bitset<10> b = i;
        int score = 0;
        REP(i,N){
            int cnt = 0;
            REP(j,10) if(b[j]) if(F[i][j]){
                ++cnt;
            }
            score += P[i][cnt];
        }
        res = max(score, res);
    }
    cout << res << endl;
}