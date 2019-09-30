#include <iostream>
#include <hash_map>
#include <queue>
#include <vector>

using namespace std;
using namespace stdext;


int n, r, c;
bool a[20][20];
typedef vector < pair<int,int> > state;


namespace stdext {
	size_t hash_value (state v) {
		size_t res = 0,  pw = 1;
		for (int i=0; i<n; ++i) {
			res += pw * v[i].first;
			pw *= 97;
			res += pw * v[i].second;
			pw *= 97;
		}
		return res;
	}
};


bool in (pair<int,int> a) {
	return 0 <= a.first && a.first < r
		&& 0 <= a.second && a.second < c;
}

const int dxy[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

bool u[20];
int q[20], qh, qt;

bool good (state a, int i) {
	for (int j=0; j<n; ++j)
		if (j != i && a[j] == a[i])
			return false;
	return true;
}

bool conn (state a) {
	memset (u, 0, sizeof u);
	u[0] = true;
	qh = qt = 0;
	q[qt++] = 0;
	while (qh<qt) {
		int v = q[qh++];
		for (int i=0; i<n; ++i) {
			int d = abs (a[i].first - a[v].first) + abs (a[i].second - a[v].second);
			if (d == 1 && !u[i]) {
				u[i] = true;
				q[qt++] = i;
			}
		}
	}
	return count (u, u+n, false) == 0;
}

int main() {
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);

	int ts;
	cin >> ts;
	for (int tt=0; tt<ts; ++tt) {

		cin >> r >> c;
		memset (a, 0, sizeof a);
		state start, need;
		for (int i=0; i<r; ++i)
			for (int j=0; j<c; ++j) {
				char ch;
				cin >> ch;
				if (ch == '#')
					a[i][j] = true;
				if (ch == 'x' || ch == 'w')
					need.push_back (make_pair (i, j));
				if (ch == 'o' || ch == 'w')
					start.push_back (make_pair (i, j));
			}
		sort (start.begin(), start.end());
		sort (need.begin(), need.end());
		n = (int) need.size();

		queue<state> q;
		hash_map<state,int> d;
		q.push (start);
		while (q.size()) {
			state cur = q.front();
			q.pop();
			int my = d[cur];
			if (cur == need)  break;

			bool curconn = conn(cur);

			state to, oto;
			for (int i=0; i<n; ++i)
				for (int j=0; j<4; ++j) {
					to = cur;
					pair<int,int> p = to[i];
					to[i].first += dxy[j][0];
					to[i].second += dxy[j][1];
					p.first -= dxy[j][0];
					p.second -= dxy[j][1];
					if (in (to[i]) && in (p) && !a[to[i].first][to[i].second] && !a[p.first][p.second] && good (to, i)
							&& find (to.begin(), to.end(), p) == to.end()) {
						if (curconn || conn (to)) {
							sort (to.begin(), to.end());
							if (!d.count(to)) {
								d[to] = my + 1;
								q.push (to);
							}
						}
					}
				}
		}

		/*
		for (state v=need; ; v=par[v]) {
			for (int i=0; i<n; ++i)
				cout << v[i].first << ' ' << v[i].second << endl;
			cout << endl;
			if (v == start)  break;
		}
		*/

		printf ("Case #%d: %d\n", tt+1, (d.count(need) ? d[need] : -1));

	}
	
}

