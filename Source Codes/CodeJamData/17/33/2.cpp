#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;
using LL = long long;
using VL = vector<LL>;
using VVL = vector<VL>;
using PLL = pair<LL, LL>;
using VS = vector<string>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}
template<class S, class T>
ostream& operator<<(ostream& os, const pair<S,T>& p){
  return os << p.FF << " " << p.SS;
}
template<class T>
void maxi(T& x, T y){
  if(x < y) x = y;
}
template<class T>
void mini(T& x, T y){
  if(x > y) x = y;
}


const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

double dp[64][64];
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  FOR(t,1,T+1){
	int N, K; cin >> N >> K;
	double U; cin >> U;
	vector<double> xs(N);
	REP(i,N) cin >> xs[i];
	RSORT(xs);

	double ans = 0.;
	REP(k,N+1){
	  double rest = U;
	  vector<double> ys = xs;
	  REP(j,k){
		if(1. - ys[j] <= rest){
		  rest -= 1. - ys[j];
		  ys[j] = 1.;
		}
		else{
		  ys[j] += rest;
		  rest = 0;
		  break;
		}
	  }

	  double lb = 0., ub = 1.;
	  REP(i,100){
		double m = (lb + ub) / 2;
		double sum = 0.;
		REP(j,N)
		  sum += max(0., m - ys[j]);
		if(sum <= rest)
		  lb = m;
		else
		  ub = m;
	  }
	  REP(i,N) maxi(ys[i], lb);
	  
	  fill((double*)dp, (double*)dp+64*64, 0.);
	  dp[0][0] = 1.;
	  REP(i,N){
		for(int j=0;j<=N;++j){
		  dp[i+1][j+1] += dp[i][j] * ys[i];
		  dp[i+1][j] += dp[i][j] * (1. - ys[i]);
		}
	  }
	  double sum = 0.;
	  for(int i=K;i<=N;++i)
		sum += dp[N][i];
	  maxi(ans, sum);
	}

	REP(k,N+1){
	  double rest = U;
	  vector<double> ys = xs;
	  double lb1 = 0., ub1 = 1.;
	  REP(i,100){
		double m = (lb1 + ub1) / 2;
		double sum = 0.;
		REP(j,k)
		  sum += max(0., m - ys[j]);
		if(sum <= rest)
		  lb1 = m;
		else
		  ub1 = m;
	  }
	  REP(i,k){
		rest -= max(0., lb1 - ys[i]);
		maxi(ys[i], lb1);
	  }

	  double lb = 0., ub = 1.;
	  REP(i,100){
		double m = (lb + ub) / 2;
		double sum = 0.;
		REP(j,N)
		  sum += max(0., m - ys[j]);
		if(sum <= rest)
		  lb = m;
		else
		  ub = m;
	  }
	  REP(i,N) maxi(ys[i], lb);
	  
	  fill((double*)dp, (double*)dp+64*64, 0.);
	  dp[0][0] = 1.;
	  REP(i,N){
		for(int j=0;j<=N;++j){
		  dp[i+1][j+1] += dp[i][j] * ys[i];
		  dp[i+1][j] += dp[i][j] * (1. - ys[i]);
		}
	  }
	  double sum = 0.;
	  for(int i=K;i<=N;++i)
		sum += dp[N][i];
	  maxi(ans, sum);
	}

  	cout << "Case #" << t << ": " << fixed << setprecision(9) << ans << endl;
  }


  return 0;
}
