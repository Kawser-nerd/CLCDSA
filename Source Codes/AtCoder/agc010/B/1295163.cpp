#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=n-1;i>=(0);i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define eall(v) unique(all(v), v.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

#define int long long
ll N;

ll A[100010];
ll B[100010];

signed main(void){
	scanf("%lld", &N);
	rep(i, N)scanf("%lld", &A[i]);
	ll sum = 0;
	rep(i, N) sum += A[i];

	if(sum % (N*(N+1)/2)){
		printf("NO\n"); return 0;
	}

	ll k = sum / (N*(N+1)/2);
	// printf("%lld\n", k);
	rep(i, N) B[i] = A[(i + 1) % N] - A[i % N];
	rep(i, N) B[i] -= k;

	ll cnt = 0;

	rep(i, N){
		if(B[i] > 0){
			printf("NO\n");
			return 0;
		}
		ll t = -B[i];
		if(t % N){
			printf("NO\n");
			return 0;
		}
		// printf("t %lld\n", t);
		cnt += t / N;
	}

	if(cnt == k){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;
}