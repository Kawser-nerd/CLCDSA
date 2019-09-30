#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <iostream>

using namespace std;

#define fr(i, N) for(i = 0; i < (int)N; i++)
#define SZ(u) ((int)u.size())
#define setContains(i,j) (((1<<j)&i) != 0)
#define MP make_pair
#define F first
#define S second
#define pb push_back
#define Eps 1e-11

typedef pair<int, int> pi;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

inline bool isDigit(char a) { return '0' <= a && a <= '9'; }

int D, I, M, N, C;
vi List;
vvi Dy;

void pre_process();
void input();
void process();

int main()
{
	int t, T;
	scanf("%d", &T);
	//cin >> T;
	pre_process();

	fr(t, T)
	{
		input();
		printf("Case #%d: ", t+1);
		process();
		fflush(stdout);
	}
	return 0;
}

void pre_process() {
}

void input() {
  int i;
	scanf("%d%d%d%d", &D, &I, &M, &N);
	List = vi(N+1, 0);
	C = 256;
	
	fr (i, N) scanf("%d", &List[i+1]);
}

void process() {
	int Inf = 255*N*100, i, j, k;
	Dy = vvi(N+1, vi(C + 1, Inf));
	Dy[0][C] = 0;
	
	for (i = 1; i <= N; i++) {
		// Not doing anything
		Dy[i][List[i]] = Dy[i-1][C];
		for (j = 0; j < C; j++) if (abs(j - List[i]) <= M) {
			Dy[i][List[i]] = min(Dy[i][List[i]], Dy[i-1][j]);
		}
		
		// Delete
		for (j = 0; j <= C; j++) Dy[i][j] = min(Dy[i][j], Dy[i-1][j] + D);
		
		// Change
		for (j = 0; j < C; j++) for (k = 0; k <= C; k++) if (k == C || abs(k - j) <= M) {
			Dy[i][j] = min(Dy[i][j], Dy[i-1][k] + abs(j - List[i]));
		}
		
		// Insert
		while(1) {
			bool flag = false;
			for (j = 0; j < C; j++) for (k = 0; k <= C; k++) if (k == C || abs(k - j) <= M) {
				if (Dy[i][j] > Dy[i][k] + I) {
				  Dy[i][j] = Dy[i][k] + I;
					flag = true;
				}
			}
			
			if (!flag) break;
		}
	}
	
	int res = Inf;
	for (i = 0; i <= C; i++) res = min(res, Dy[N][i]);
	printf("%d\n", res);
}