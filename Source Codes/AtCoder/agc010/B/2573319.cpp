#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<iomanip>
#include <assert.h>
#include<utility>
typedef long long int ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<signed(n);i++)
#define EREP(i,n) for(int i=1;i<=signed(n);i++)
#define ALL(a) (a).begin(),(a).end()
using std::cout;
using std::vector;
using std::endl;
using std::cin;
using std::string;
//#define EVEL 1
#ifdef EVEL
#define DEB(X) cout << #X << ":" <<X<<" " ;
#define TF(f) f ? cout<<"true  " : cout<<"false ";
#define END cout<<"\n";
#else
#define DEB(X) {}
#define TF(f) {}
#define END {}
#endif
constexpr int MOD = 1000000007;
constexpr ll INF = 50000000000000000;
typedef std::pair<int, int> P;
constexpr ll SIZE = 100010;

ll N, A[100010], B[SIZE];
ll ans = 0, sum = 0, wa = 0;
int main() {
	std::ios_base::sync_with_stdio(false);
	cin >> N;
	REP(i, N) {
		cin >> A[i];
		sum += A[i];
		wa += i + 1;
	}
	REP(i, N) {
		B[i] = A[(i + 1) % N] - A[i];
	}
	bool f = true;
	if (sum%wa != 0) { cout << ("NO") << endl; return 0; }
	if(0){
		ll SSS = 0;
		REP(i, N) {
			SSS += B[i];
		}
		assert(SSS == 0);
	}
	REP(i, N) {
		B[i] -= sum / wa;
		//cout<<B[i]<<' ';
	}
	//cout<<"\n================================\n";
	ll cnt = 0;
	REP(i, N) {
		if (B[i]<=0 && (-B[i]) % N == 0) { cnt += (-B[i]) / N; }
		else f = false;
	}
	if (f && cnt != sum / wa) {
		f = false;
		assert(false);
	}
	
	cout << (f ? "YES" : "NO") << endl;
	return 0;
}