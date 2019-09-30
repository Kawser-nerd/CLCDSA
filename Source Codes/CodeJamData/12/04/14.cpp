#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

// Hall of Mirrors

int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}
	if (a == 0) {
		return b;
	}
	return gcd(b, a % b);
}

void nextCheckPoint(int &nx, int &ny, int cx, int cy, int ux, int uy, int dx, int dy)
{
	if (dx == 0 || dy == 0) {
		nx = cx + dx * ux;
		ny = cy + dy * uy;
	} else {
		int ddx, ddy;
		if (dx > 0) {
			ddx = (floor((double)cx / ux) + 1) * ux - cx;
		} else {
			ddx = cx - (ceil((double)cx / ux) - 1) * ux;
		}
		if (dy > 0) {
			ddy = (floor((double)cy / uy) + 1) * uy - cy;
		} else {
			ddy = cy - (ceil((double)cy / uy) - 1) * uy;
		}
		int d = min(ddx, ddy);
		nx = cx + dx * d;
		ny = cy + dy * d;
	}
}

int reflect(vector <string> &map, int &ndx, int &ndy,
	    int cx, int cy, int ux, int uy, int dx, int dy)
{
	int x = cx / (ux * 2);
	int y = cy / (uy * 2);
	ndx = dx;
	ndy = dy;
	if (cx % (ux * 2) == 0 && cy % (uy * 2) == 0) {
		char d1 = map[y + (dy > 0 ? 0 : -1)][x + (dx > 0 ? 0 : -1)];
		char d2 = map[y + (dy > 0 ? 0 : -1)][x + (dx > 0 ? -1 : 0)];
		char d3 = map[y + (dy > 0 ? -1 : 0)][x + (dx > 0 ? 0 : -1)];
		if (d1 == '#' && d2 == '#' && d3 == '#') {
			ndx = -dx;
			ndy = -dy;
		} else if (d1 == '#' && d2 == '#') {
			ndy = -dy;
		} else if (d1 == '#' && d3 == '#') {
			ndx = -dx;
		} else if (d1 == '#') {
			return 1;
		}
	} else if (cx % (ux * 2) == 0) {
		if (dx > 0 && map[y][x] == '#' ||
		    dx < 0 && map[y][x - 1] == '#') {
			ndx = -dx;
		}
	} else if (cy % (uy * 2) == 0) {
		if (dy > 0 && map[y][x] == '#' ||
		    dy < 0 && map[y - 1][x] == '#') {
			ndy = -dy;
		}
	}
	return 0;
}

int isVisible(vector <string> &map, int px, int py, int lx, int ly, int D)
{
	int ux = (ly == 0) ? 1 : abs(ly);
	int uy = (lx == 0) ? 1 : abs(lx);
	int cx = (px * 2 + 1) * ux;
	int cy = (py * 2 + 1) * uy;
	int dx = lx / uy;
	int dy = ly / ux;
	int ax = 0;
	int ay = 0;
	while (1) {
		int nx, ny;
		nextCheckPoint(nx, ny, cx, cy, ux, uy, dx, dy);
		ax += abs(nx - cx);
		ay += abs(ny - cy);
		if ((ax / ux) * (ax / ux) + (ay / uy) * (ay / uy) > D * D * 4) {
			break;
		}
		cx = nx;
		cy = ny;
		if (cx == (px * 2 + 1) * ux && cy == (py * 2 + 1) * uy) {
			return 1;
		}
		if (reflect(map, dx, dy, cx, cy, ux, uy, dx, dy)) {
			return 0;
		}
	}
	return 0;
}

int main()
{
	string line;

	int cases;
	cin >> cases;

	for (int caseno = 1; caseno <= cases; caseno++) {
		int H, W, D;
		cin >> H >> W >> D;
		vector <string> map(H);
		int px, py;
		for (int y = 0; y < H; y++) {
			cin >> map[y];
			for (int x = 0; x < W; x++) {
				if (map[y][x] == 'X') {
					px = x;
					py = y;
				}
			}
		}
		int ret = 0;
		for (int ly = -D; ly <= D; ly++) {
			for (int lx = -D; lx <= D; lx++) {
				if (gcd(abs(lx), abs(ly)) != 1 ||
				    lx * lx + ly * ly > D * D) {
					continue;
				}
				ret += isVisible(map, px, py, lx, ly, D);
			}
		}
		cout << "Case #" << caseno << ": " << ret << endl;
	}

	return 0;
}
