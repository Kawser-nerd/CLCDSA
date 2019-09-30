#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
using namespace std;

int W, H, B;
const int MAX_N = 1000 + 10;

struct Rect {
	int x1, y1, x2, y2; //(x1,y1) - (x2,y2)
	void read() {
		cin >> x1 >> y1 >> x2 >> y2;
	}
	bool contain(int x, int y) {
		return x >= x1 && x <= x2 && y >= y1 && y <= y2;
	}
};

Rect r[MAX_N];

int dist(int x1, int y1, int x2, int y2) {
	return max(abs(x1 - x2), abs(y1 - y2)) - 1;
}

int dist(Rect a, Rect b) {
	set<int> ix, iy;
	ix.insert(a.x1), ix.insert(a.x2), ix.insert(b.x1), ix.insert(b.x2);
	iy.insert(a.y1), iy.insert(a.y2), iy.insert(b.y1), iy.insert(b.y2);

	int ans = 1 << 30;

	for (auto ax : ix)
		for (auto ay : iy)
			if (a.contain(ax, ay)) {
				for (auto bx : ix)
					for (auto by : iy)
						if (b.contain(bx, by)) {
							ans = min(ans, dist(ax, ay, bx, by));
						}
			}

	return ans;
}

int edge[MAX_N][MAX_N];

int D[MAX_N];
bool used[MAX_N];

int main() {
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		printf("Case #%d: ", nc);
		cin >> W >> H >> B;
		for (int i = 0; i < B; ++i) {
			r[i].read();
		}
		r[B].x1 = r[B].x2 = W;
		r[B].y1 = 0, r[B].y2 = H;
		++B;
		r[B].x1 = r[B].x2 = -1;
		r[B].y1 = 0, r[B].y2 = H;
		++B;
		for (int i = 0; i < B; ++i) {
			for (int j = 0; j < B; ++j) {
				edge[i][j] = dist(r[i], r[j]);
			}
		}
		int vs = B - 2, vt = B - 1;
		fill_n(D, B, 1 << 30);
		memset(used, 0, sizeof used);
		D[vs] = 0;
		for (int it = 0; it < B; ++it) {
			int who = -1;
			for (int i = 0; i < B; ++i)
				if (!used[i] && (who == -1 || D[i] < D[who])) {
					who = i;
				}
			used[who] = true;
			for (int i = 0; i < B; ++i)
				if (!used[i]) {
					D[i] = min(D[i], D[who] + edge[who][i]);
				}
		}
		cout << D[vt] << endl;
	}
}
