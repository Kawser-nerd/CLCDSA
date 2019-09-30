#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int DY[4] = {0,1,0,-1};
const int DX[4] = {1,0,-1,0};

void assertGood(vector<string>& board) {
	rep(i,0,sz(board)-1) {
		rep(j,0,sz(board[i])) {
			bool a = (board[i][j] == '#');
			bool b = (board[i][j+1] == '#');
			bool c = (board[i+1][j] == '#');
			bool d = (board[i+1][j+1] == '#');
			if (a + b + c + d == 2) {
				assert(!(a && d));
				assert(!(b && c));
			}
		}
	}
}

vector<vi> shortestPaths(int R, int C, vector<string>& board, int startx, int starty) {
	vector<vi> dists(R, vi(C, -1));
	queue<pii> q;
	q.push(pii(starty, startx));
	dists[starty][startx] = 0;
	while (!q.empty()) {
		pii pa = q.front();
		q.pop();
		int d = dists[pa.first][pa.second];
		rep(di,0,4) {
			int ny = pa.first + DY[di];
			int nx = pa.second + DX[di];
			if (board[ny][nx] == '#') continue;
			if (dists[ny][nx] != -1) continue;
			dists[ny][nx] = d + 1;
			q.push(pii(ny,nx));
		}
	}
	return dists;
}

void solve(int cs) {
	int R, C, TargetD;
	cin >> R >> C >> TargetD;
	vector<string> board(R);
	rep(i,0,R) cin >> board[i];
	int startx = -1, starty = -1, endx = -1, endy = -1;
	rep(i,0,R) rep(j,0,C) {
		char c = board[i][j];
		if (c == 'S') starty = i, startx = j;
		if (c == 'F') endy = i, endx = j;
	}

	if ((startx + starty + endx + endy + TargetD) & 1) throw false;

	vector<vi> dists = shortestPaths(R, C, board, startx, starty);
	assert(dists[endy][endx] != -1);
	if (dists[endy][endx] < TargetD) throw false;
	if (abs(endy - starty) + abs(endx - startx) > TargetD) throw false;

// cerr << TargetD << " vs " << dists[endy][endx] << endl;

	auto test = [&]() {
		array<vector<vi>, 4> dists2;
		rep(i,0,4)
			dists2[i].assign(R, vi(C, -1));
		struct Pos {
			int y, x;
			int dir;
		};

		Pos nul = {-1,-1,0};
		array<vector<vector<Pos>>, 4> prevp;
		rep(i,0,4)
			prevp[i].assign(R, vector<Pos>(C, nul));

		vector<vi> failings(R, vi(C, -1));

		queue<Pos> q;
		auto add = [&](Pos p, int d, Pos bw, bool failing) {
			// assert(prevp[p.dir][p.y][p.x].x == -1);
			// assert(dists2[p.dir][p.y][p.x] == -1);
			if (failings[p.y][p.x] != -1) {
				if (failing) return;
				if (failings[p.y][p.x] < d) return;
			}

			if (failing) {
				failings[p.y][p.x] = d;
			}
			else {
				dists2[p.dir][p.y][p.x] = d;
				prevp[p.dir][p.y][p.x] = bw;
				q.push(p);
			}
		};

		auto danger = [&](Pos p, int olddir, int newdir) -> bool {
			assert((newdir + olddir) & 1);
			int dx1 = DX[olddir];
			int dy1 = DY[olddir];
			int dx2 = DX[newdir];
			int dy2 = DY[newdir];
			return
				board[p.y + dy1][p.x + dx1] == '#' &&
				board[p.y - dy2][p.x - dx2] == '#' &&
				board[p.y + dy1 - dy2][p.x + dx1 - dx2] != '#';
		};

		rep(i,0,4)
			add({endy, endx, i}, 0, nul, false);

		while (!q.empty()) {
			Pos p = q.front();
			q.pop();
			int d = dists2[p.dir][p.y][p.x];
			if (dists[p.y][p.x] != -1 && dists[p.y][p.x] + d == TargetD) {
				cout << "POSSIBLE" << endl;
				// int y = p.y, x = p.x;
				while (p.x != -1) {
#ifdef DEBUG
board[p.y][p.x] = 'P';
#else
					if (board[p.y][p.x] == '#')
						board[p.y][p.x] = '.';
#endif
					p = prevp[p.dir][p.y][p.x];
// cerr << "set " << p.x << ' ' << p.y << ' ' << p.dir << endl;
				}
#ifdef DEBUG
board[y][x] = '!';
#endif
				rep(i,0,R) cout << board[i] << '\n';
				cout << flush;
				assertGood(board);
				int nsh = shortestPaths(R, C, board, startx, starty)[endy][endx];
// cerr << nsh << ' ' << TargetD << endl;
// cerr << "want " << dists[y][x] << " + " << d << endl;
// cerr << "actually + " << shortestPaths(R, C, board, endx, endy)[y][x] << endl;
				assert(nsh == TargetD);
				return true;
			}

			rep(ndir,0,4) {
				if (((ndir - p.dir) & 3) == 2) continue;
				Pos p2 = {
					p.y + DY[ndir],
					p.x + DX[ndir],
					ndir
				};
				if (dists2[p2.dir][p2.y][p2.x] != -1) continue;
				if (p2.x == 0 || p2.y == 0 || p2.x == C-1 || p2.y == R-1) continue;
				if (p.dir != p2.dir && danger(p, p.dir, p2.dir)) continue;

				bool failing = false;
				rep(di,0,4) {
					int ny = p2.y + DY[di];
					int nx = p2.x + DX[di];
					if (dists[ny][nx] != -1 && dists[ny][nx] + d + 2 < TargetD) failing = true;
				}

				add(p2, d + 1, p, failing);
			}
		}
		return false;
	};

	if (test()) return;

	cerr << "Warning at case " << cs << "!" << endl;
	cerr << TargetD << endl;
	rep(i,0,R) cerr << board[i] << endl;
	// abort();
	throw false;
}

int main() {
	int N;
	cin.sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	rep(i,0,N) {
		cout << "Case #" << i+1 << ": ";
		try {
			solve(i+1);
		} catch(bool) {
			cout << "IMPOSSIBLE" << endl;
		}
	}
}
