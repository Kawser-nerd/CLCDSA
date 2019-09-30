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
const int MOD = 1000000007;
const ll INF = 50000000000000000;
typedef std::pair<int, int> P;
struct edge { int to;double cost; };
#define VMAX 1010
int N;
double C[VMAX][VMAX];
double d[VMAX];
bool F[VMAX];
int X[VMAX], Y[VMAX], R[VMAX];
ll ans;

void Dijkstra(int s) {
	std::fill(F, F + N + 2, false);
	//std::fill(d, d + N + 2, INF);
	d[s] = 0;
	while (true) {
		int v = -1;
		REP(i, N+2) {
			if (!F[i] && (v == -1 || d[i]<d[v]))v = i;
		}
		if (v == -1)break;
		F[v] = true;
		REP(i, N+2) {
			d[i] = std::min(d[i], d[v] + C[v][i]);
		}
	}
}

int main() {
	int sx, sy, gx, gy;
	cin >> sx >> sy >> gx >> gy >> N;
	X[N] = sx, Y[N] = sy, X[N + 1] = gx, Y[N + 1] = gy;
	R[N] = R[N + 1] = 0;
	REP(i, 1002)REP(j, 1002)C[i][j] = INF;
	REP(i, N) {
		cin >> X[i] >> Y[i] >> R[i];
	}
	REP(i, N + 2){REP(j, N + 2) {
		if (i == j) { continue; }
		double temp =
			sqrt(ll(X[i] - X[j])*ll(X[i] - X[j]) + ll(Y[i] - Y[j])*ll(Y[i] - Y[j]));
        if(temp<=R[i]+R[j]){C[i][j]=0;}
	    else C[i][j] = temp- R[i] - R[j];
		/*DEB(X[i])DEB(X[j])DEB(Y[i])DEB(Y[j])*/DEB(C[i][j])
	}END}
    std::fill(d, d + N + 2, INF);
	Dijkstra(N);
    //Dijkstra(N);
	printf("%.10lf\n", d[N + 1]);
	return 0;
}