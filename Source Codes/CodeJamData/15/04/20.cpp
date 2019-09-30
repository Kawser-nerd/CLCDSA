#include <iostream>
#include <cassert>
#include <set>
#include <vector>
#include <limits>
#include <cstring>
#include <algorithm>

using namespace std;

const int CANVAS_SIZE = 36;
const int ORIGIN = 7;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct point {
	int x, y;
	bool operator<(const point& other) const {
		if (x != other.x) return x < other.x;
		return y < other.y;
	}
	bool operator==(const point& other) const {
		return x == other.x && y == other.y;
	}
};

typedef set<point> omino;

char tempCanvas[CANVAS_SIZE][CANVAS_SIZE];

ostream& operator<<(ostream& os, const omino& om) {
	int minX = numeric_limits<int>::max();
	int minY = numeric_limits<int>::max();
	int maxX = numeric_limits<int>::min();
	int maxY = numeric_limits<int>::min();
	for (omino::const_iterator it = om.begin(); it != om.end(); it++) {
		minX = min(minX, it->x);
		minY = min(minY, it->y);
		maxX = max(maxX, it->x);
		maxY = max(maxY, it->y);
	}
	assert(minX != numeric_limits<int>::max());
	assert(minY != numeric_limits<int>::max());
	assert(maxX != numeric_limits<int>::min());
	assert(maxY != numeric_limits<int>::min());
	assert(maxX - minX < CANVAS_SIZE);
	assert(maxY - minY < CANVAS_SIZE);
	memset(tempCanvas, '.', sizeof tempCanvas);
	for (omino::const_iterator it = om.begin(); it != om.end(); it++) {
		tempCanvas[it->x - minX][it->y - minY] = '#';
	}
	for (int i = minX; i <= maxX; i++) {
		tempCanvas[i - minX][maxY - minY + 1] = '\0';
		os << tempCanvas[i - minX] << endl;
	}
	return os;
}

vector<omino> ominoes[7];

void precalc() {
	set<point> one;
	one.insert((point) {0, 0});
	ominoes[1].push_back(one);
	for (int i = 2; i < 7; i++) {
		for (vector<omino>::iterator it = ominoes[i - 1].begin(); it != ominoes[i - 1].end(); it++) {
			assert((int) it->size() == i - 1);
			set<point> newPoints;
			for (omino::iterator jt = it->begin(); jt != it->end(); jt++) {
				for (int d = 0; d < 4; d++) {
					point newPoint = *jt;
					newPoint.x += dx[d];
					newPoint.y += dy[d];
					if (it->find(newPoint) == it->end())
						newPoints.insert(newPoint);
				}
			}
			for (set<point>::iterator jt = newPoints.begin(); jt != newPoints.end(); jt++) {
				omino newOmino = *it;
				newOmino.insert(*jt);
				assert((int) newOmino.size() == i);
				if (find(ominoes[i].begin(), ominoes[i].end(), newOmino) == ominoes[i].end()) {
					ominoes[i].push_back(newOmino);
					//cerr << newOmino << endl;
				}
			}
		}
		//cerr << "  There are " << ominoes[i].size() << " ominoes of size " << i << " (not checked for symmetry)." << endl << endl;
	}
}

int canvas[CANVAS_SIZE][CANVAS_SIZE];

int dfs(int x, int y, int R, int C) {
	if (x < 0 || x >= R || y < 0 || y >= C) return 0;
	int a = x + ORIGIN;
	int b = y + ORIGIN;
	if (canvas[a][b] != 1) return 0;
	canvas[a][b] = 3;
	int ret = 1;
	for (int d = 0; d < 4; d++) {
		ret += dfs(x + dx[d], y + dy[d], R, C);
	}
	return ret;
}

bool fitsOnCanvas(int R, int C, const omino& om) {
	int minX = numeric_limits<int>::max();
	int minY = numeric_limits<int>::max();
	int maxX = numeric_limits<int>::min();
	int maxY = numeric_limits<int>::min();
	for (omino::const_iterator it = om.begin(); it != om.end(); it++) {
		minX = min(minX, it->x);
		minY = min(minY, it->y);
		maxX = max(maxX, it->x);
		maxY = max(maxY, it->y);
	}
	assert(minX != numeric_limits<int>::max());
	assert(minY != numeric_limits<int>::max());
	assert(maxX != numeric_limits<int>::min());
	assert(maxY != numeric_limits<int>::min());
	assert(maxX - minX < CANVAS_SIZE);
	assert(maxY - minY < CANVAS_SIZE);
	bool success = false;
	for (int i = 0; i < R + minX - maxX && !success; i++) {
		int x = ORIGIN + i - minX;
		for (int j = 0; j < C + minY - maxY && !success; j++) {
			int y = ORIGIN + j - minY;
			for (int a = 0; a < R; a++) {
				for (int b = 0; b < C; b++) {
					canvas[a + ORIGIN][b + ORIGIN] = 1;
				}
			}
			for (omino::const_iterator it = om.begin(); it != om.end(); it++) {
				assert(x + it->x >= ORIGIN && x + it->x < ORIGIN + R);
				assert(y + it->y >= ORIGIN && y + it->y < ORIGIN + C);
				assert(canvas[x + it->x][y + it->y] == 1);
				canvas[x + it->x][y + it->y] = 2;
			}
			bool thisSuccess = true;
			for (int a = 0; a < R && thisSuccess; a++) {
				for (int b = 0; b < C && thisSuccess; b++) {
					thisSuccess = (dfs(a, b, R, C) % ((int) om.size())) == 0;
				}
			}
			success = thisSuccess;
		}
	}
	return success;
}

bool solve() {
	int X, R, C;
	cin >> X >> R >> C;
	assert(X >= 1 && X <= 20);
	assert(R >= 1 && R <= 20);
	assert(C >= 1 && C <= 20);
	if (X >= 7 || (R * C) % X != 0)
		return true;
	for (vector<omino>::iterator it = ominoes[X].begin(); it != ominoes[X].end(); it++) {
		assert(X == (int) it->size());
		if (!fitsOnCanvas(R, C, *it) && !fitsOnCanvas(C, R, *it))
			return true;
	}
	return false;
}

int main() {
	int T;
	cin >> T;
	assert(T >= 1 && T <= 100);
	precalc();
	for (int i = 0; i < T; i++) {
		cout << "Case #" << (i + 1) << ": " << (solve() ? "RICHARD" : "GABRIEL") << endl;
	}
	return 0;
}
