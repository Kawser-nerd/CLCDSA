#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FOREACH(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define SZ(x) ((int)(x).size())

typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<string> vs; typedef long long ll;

int N, M;
string mapa[100];
int dist[2][100][100];
bool mark[100][100];

int di[]={-1,1,0,0};
int dj[]={0,0,-1,1};

bool valid(int i, int j) {
	return i>=0 && i < N && j >=0 && j < M && mapa[i][j] != '.';
}
void bfs(int x, int si, int sj) {
	int i, j, ni, nj;
	queue<pi> q;
	q.push(make_pair(si, sj)); dist[x][si][sj] = 0;
	while (!q.empty()) {
		i = q.front().first;
		j = q.front().second;
		q.pop();
		REP(k, 4) {
			ni = i + di[k]; nj = j + dj[k];
			if (valid(ni, nj) && dist[x][ni][nj] == 0x3f3f3f3f) {
				dist[x][ni][nj] = dist[x][i][j] + 1;
				q.push(make_pair(ni, nj));
			}
		}
	}
}

bool seen[100][100];
int go() {
	int i, j, ni, nj;
	int res = 0;
	map<pi, pi> pred;
	queue<pi> q;
	CLEAR(seen, false);
	q.push(make_pair(0, 0)); seen[0][0] = true;
	while (!q.empty()) {
		i = q.front().first;
		j = q.front().second;
		q.pop();
		if (mapa[i][j] == 'T' && (i || j)) {
			while (i || j) {
				res += dist[0][i][j];
				mark[i][j] = true;
				pi p = pred[make_pair(i,j)];
				i = p.first; j = p.second;
			}
			break;
		}
		REP(k, 4) {
			ni = i + di[k]; nj = j + dj[k];
			//printf("%d %d\n", dist[0][i][j], dist[0][ni][nj]);
			if (valid(ni, nj) && dist[0][ni][nj] == dist[0][i][j] + 1 && !seen[ni][nj]) {
				pred[make_pair(ni, nj)] = make_pair(i, j);
				seen[ni][nj] = true;
				q.push(make_pair(ni, nj));
			}
		}
	}
	return res;
}


int main() {
	int casos, res;
	cin >> casos;
	REP(caso, casos) {
		cin >> N >> M;
		REP(i, N) cin >> mapa[i];
		CLEAR(dist, 0x3f);
		int f = 0;
		REP(i, N) REP(j, M) if (mapa[i][j] == 'T') {
			bfs(f, i, j);
			f++;
		}
		res = 0x3fffffff;
		if (f == 1) {
			res = 0;
			REP(i, N) REP(j, M) if (valid(i, j)) res += dist[0][i][j];
		} else {
			CLEAR(mark, false);
			res = go();
			REP(i, N) REP(j, M) if (valid(i,j) && !mark[i][j]) res += min(dist[0][i][j], dist[1][i][j]);
		}
		cout << "Case #" << caso+1 << ": " << res << endl;
	}
	return 0;
}
