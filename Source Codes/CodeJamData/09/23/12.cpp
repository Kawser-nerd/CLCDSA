#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;


struct state {
	int x, y, num;
	state() { }
	state (int x, int y, int num)
		:x(x), y(y), num(num)
	{ }
};

int n;
vector<string> a;
queue<state> qq;
const int MAXD = 1000;
bool u[20][20][MAXD*2+1];
int d[20][20][MAXD*2+1];
vector<char> qu;
int cntq;
bool stop;
int stopd;

void go (int x, int y, int num, int dst, char c1, char c2=0, state par = state()) {
	if (num+MAXD > MAXD*2 || num+MAXD<0)  return;
	if (u[x][y][num+MAXD])  return;
	u[x][y][num+MAXD] = true;
	qq.push (state (x, y, num));
	d[x][y][num+MAXD] = dst;
	if (num > 0 && num <= 250 && qu[num]) {
		qu[num] = false;
		if (--cntq == 0) {
			stop = true;
			stopd = dst;
		}
	}
}

bool ru[20][20][MAXD*2+1];
string r[20][20][MAXD*2+1];

string restore (int x, int y, int num, int dst) {
	if (a[x][y]-'0' == num)
		return string(1,a[x][y]);
	if (ru[x][y][num+MAXD])
		return r[x][y][num+MAXD];
	ru[x][y][num+MAXD] = true;
	string best;
	state st (x, y, num);
	int dxy[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
	int curnum = a[x][y]-'0';
	for (int i=0; i<4; ++i) {
		state to (st.x+dxy[i][0], st.y+dxy[i][1], st.num);
		if (to.x >= 0 && to.y >= 0 && to.x < n && to.y < n) {
			char op = a[to.x][to.y];
			for (int j=0; j<4; ++j) {
				state to (st.x+dxy[i][0], st.y+dxy[i][1], st.num);
				to.x += dxy[j][0],  to.y += dxy[j][1];
				if (to.x >= 0 && to.y >= 0 && to.x < n && to.y < n) {
					int nnum = (a[to.x][to.y] - '0');
					int need;
					if (op == '+')
						need = num - curnum;
					else
						need = num - curnum + 2 * nnum;
					if (!u[to.x][to.y][need+MAXD] || d[to.x][to.y][need+MAXD] + 2 != dst)
						continue;
					string cand = string(1,op) + restore (to.x, to.y, need, dst - 2);
					if (best.empty() || cand < best)
						best = cand;
				}
			}
		}
	}
	best = string(1,a[x][y]) + best;
	return r[x][y][num+MAXD] = best;
}

int main() {
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);

	int ts;
	cin >> ts;
	for (int ttt=0; ttt<ts; ++ttt) {

		int m;
		cin >> n >> m;
		a.resize (n);
		for (int i=0; i<n; ++i)
			cin >> a[i];
		qu.assign (251, 0);
		vector<int> q (m);
		cntq = 0;
		for (int i=0; i<m; ++i) {
			cin >> q[i];
			if (!qu[q[i]])
				++cntq;
			qu[q[i]] = true;
		}
		stop = false;

		while (qq.size())
			qq.pop();
		memset (u, 0, sizeof u);

		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				if (isdigit (a[i][j]))
					go (i, j, a[i][j]-'0', 1, a[i][j]);
		while (qq.size()) {
			state st = qq.front();
			qq.pop();
			int myd = d[st.x][st.y][st.num+MAXD];
			if (stop && myd > stopd)
				break;

			int dxy[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
			for (int i=0; i<4; ++i) {
				state to (st.x+dxy[i][0], st.y+dxy[i][1], st.num);
				if (to.x >= 0 && to.y >= 0 && to.x < n && to.y < n) {
					char op = a[to.x][to.y];
					for (int j=0; j<4; ++j) {
						state to (st.x+dxy[i][0], st.y+dxy[i][1], st.num);
						to.x += dxy[j][0],  to.y += dxy[j][1];
						if (to.x >= 0 && to.y >= 0 && to.x < n && to.y < n) {
							int nnum = a[to.x][to.y] - '0';
							int curnum = a[st.x][st.y] - '0';
							if (op == '+')
								to.num = nnum + st.num;
							else
								to.num = nnum - 2 * curnum + st.num;
							go (to.x, to.y, to.num, myd+2, op, a[to.x][to.y], st);
						}
					}
				}
			}
		}

		printf ("Case #%d:\n", ttt+1);
		memset (ru, 0, sizeof ru);
		for (int i=0; i<m; ++i) {
			int cur = q[i];
			int mind = 100000000;
			string ans;
			for (int x=0; x<n; ++x)
				for (int y=0; y<n; ++y)
					if (u[x][y][cur+MAXD] && d[x][y][cur+MAXD] <= mind) {
						if (d[x][y][cur+MAXD] < mind) {
							mind = d[x][y][cur+MAXD];
							ans = string (mind, 'z');
						}
						ans = min (ans, restore (x, y, cur, mind));
					}
			puts(ans.c_str());
		}

	}

}
