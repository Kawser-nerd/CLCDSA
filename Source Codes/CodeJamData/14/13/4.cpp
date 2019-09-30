#include<bits/stdc++.h>
#include<sys/time.h>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

const int N = 1000;
double dp[2][N][N];

void precalc(){
	int cur = 0, next = 1;
	int n = N;
	
	rep(i, n) dp[0][i][i] = 1;
	rep(i, n){
		memset(dp[next], 0, sizeof(dp[next]));
		if(i % 100 == 0) dbg(i);
		
		rep(j, n) rep(k, n){
			if(k == i){
				rep(l, n) dp[next][j][l] += dp[cur][j][k] / n;
			}
			else{
				dp[next][j][k] += dp[cur][j][k] * (1 - 1.0 / n);
				dp[next][j][i] += dp[cur][j][k] / n;
			}
		}
		swap(cur, next);
	}
	//rep(i, 10) rep(j, 10) cerr<<dp[cur][i * 100][j * 100]<<(j==9?"\n":" ");
}

inline int xor128(){
	static int w = (unsigned int)time(NULL);
	//static int w = 88675123;
	static int x = 123456789, y = 362436069, z = 521288629;
	int t = x ^ x << 11;
	x = y; y = z; z = w;
	return w = w ^ w >> 19 ^ t ^ t >> 8;
}
vi gengood(){
	vi res(N);
	rep(i, N) res[i] = i;
	rep(i, N){
		int p = xor128() % (N - i);
		swap(res[i], res[i + p]);
	}
	return res;
}
vi genbad(){
	vi res(N);
	rep(i, N) res[i] = i;
	rep(i, N){
		int p = xor128() % N;
		swap(res[i], res[p]);
	}
	return res;
}

void test(){
	
	int correct = 0;
	
	rep(i, 100){
		vi in = gengood();
		double score = 1;
		rep(i, N) score *= dp[N & 1][in[i]][i] * N;
		
		if(score < 5) correct++;
	}
	rep(i, 100){
		vi in = genbad();
		double score = 1;
		rep(i, N) score *= dp[N & 1][in[i]][i] * N;
		
		if(score >= 5) correct++;
	}
	dbg(correct);
}

void run(){
	int n; cin >> n;
	assert(n == N);
	vi in(N);
	double score = 1;
	
	rep(i, N){
		cin >> in[i];
		score *= dp[N & 1][in[i]][i] * N;
	}
	if(score >= 5) cout << "BAD" << endl;
	else cout << "GOOD" << endl;
}

int main(){
	precalc();
	//test();
	
	int cs; cin >> cs;
	rep(i, cs){
		cout << "Case #" << i+1 << ": ";
		run();
	}
	
	return 0;
}
