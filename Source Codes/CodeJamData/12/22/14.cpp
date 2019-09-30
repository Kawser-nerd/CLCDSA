/*{{{*/
/*includes e defines*/
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef vector<string> VS;
typedef pair<int,int> pii;
#define sz(A) (int)(A).size()
#define FOR(A,B) for(int A=0; A < (int) (B);A++)
#define FOREACH(A,B) for((__typeof (B).begin) A = (B).begin(); A != (B).end(); A++)
#define pb push_back
#define all(x) x.begin() , x.end()
#define mp make_pair
/*}}}*/
/*{{{*/
/*main*/
void solveCase();
int main() {
	int TESTES; scanf("%d", &TESTES);
	for(int TESTE = 1; TESTE <= TESTES; TESTE++) {
		printf("Case #%d: ", TESTE);
		solveCase();
	}
    return 0;
}
/*}}}*/

#define MAXN 124

int N,M,H;
int C[MAXN][MAXN], F[MAXN][MAXN];
int PD[MAXN][MAXN];
multimap< int, pii > fila;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void dfs(int x, int y) {
	if(PD[x][y] == 0) return;
	//cout << "Chego em " << x << " "<< y <<  " que é de " << F[x][y] << " a " << C[x][y] << endl;
	PD[x][y] = 0;
	fila.insert( mp(0, pii(x,y) ) );

	FOR(d, 4) {
		int xx = x + dx[d], yy = y + dy[d];
		if(xx < 0 || xx >= N || yy < 0 || yy >= M) continue;
		int f = max(H, max( F[x][y], F[xx][yy] ));
		int c = min( C[x][y], C[xx][yy] );
		if(c - f < 50) continue;
		dfs(xx,yy);
	}
}

void insere(int x, int y, int custo) {
	if(PD[x][y] == -1 || PD[x][y] > custo) {
		PD[x][y] = custo;
		fila.insert( mp(custo, pii(x,y) ) );
	}
}

void solveCase() {
	cin >> H >> N >> M;

	FOR(i, N) {
		FOR(j, M) {
			cin >> C[N-i-1][j];
		}
	}
	FOR(i, N) {
		FOR(j, M) {
			cin >> F[N-i-1][j];
		}
	}
	memset(PD, -1, sizeof(PD));
	fila.clear();
	dfs(N-1, 0);


	if(0)
	for(int i = N-1; i >= 0; i--) {
		FOR(j, M) {
			cout << PD[i][j] << " ";
		}
		cout << endl;
	}

	while(!fila.empty()) {
		pair<int, pii> at = *fila.begin();
		fila.erase(fila.begin());
		int tempo = at.first;
		int x = at.second.first;
		int y = at.second.second;
		if(PD[x][y] < tempo) continue;

		FOR(d, 4) {
			int xx = x + dx[d], yy = y + dy[d];
			if(xx < 0 || xx >= N || yy < 0 || yy >= M) continue;
			int t = tempo;
			int f = max(H - t, max( F[x][y], F[xx][yy] ));
			int ff = max( F[x][y], F[xx][yy] );
			int c = min( C[x][y], C[xx][yy] );
			if(c - ff < 50) continue;

			if(c - f < 50) {
				int dif = 50 - (c - f);	
				int custo = 100;
				if(H - tempo - dif - F[x][y] >= 20) custo = 10;
				insere(xx,yy, tempo + dif + custo);
			} else {
				int custo = 100;
				if(H - tempo - F[x][y] >= 20) custo = 10;
				insere(xx,yy, tempo + custo);
			}
		}

	}

	if(0)
	for(int i = N-1; i >= 0; i--) {
		FOR(j, M) {
			cout << PD[i][j] << " ";
		}
		cout << endl;
	}

	double ans = PD[0][M-1];
	printf("%.10f\n", ans/10.0);

}

