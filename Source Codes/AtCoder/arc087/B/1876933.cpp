#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <queue>
#include <deque>
#include <math.h>
#include <cmath>
#include <stack>
#include <algorithm>
#include <list>
#include <array>
#include <valarray>
#include <unordered_map>
#include <cassert>
#include <random>
#include <cstring>

using namespace std;

typedef long long li;

#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

double eps = 1e-5;
const int INF = 1e9 + 7;

const int N = 9e3 + 7;

bool d[N][2 * N];
bool used[N][2 * N];

vector<int> dx, dy;

bool calcX(int i, int x) {
	if (i < 0)
		return false;

	if (used[i][x])
		return d[i][x];

	if (i < 1)
		return false;

	used[i][x] = true;

	if (i == 1)
		d[i][x] = calcX(i - 1, x - dx[i - 1]);
	else
		d[i][x] = calcX(i - 1, x - dx[i - 1]) || calcX(i - 1, x + dx[i - 1]);

	return d[i][x];
}

bool calcY(int i, int y) {
	if (i < 0)
		return false;

	if (used[i][y])
		return d[i][y];

	if (i < 1)
		return false;

	used[i][y] = true;

	d[i][y] = calcY(i - 1, y - dy[i - 1]) || calcY(i - 1, y + dy[i - 1]);

	return d[i][y];
}

int main() {
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	string s;
	cin >> s;

	int tx, ty;
	cin >> tx >> ty;

	int cur = 0, fl = 1;
	for (auto c : s) {
		if (c == 'F') {
			cur++;
		}
		else {
			if (fl)
				dx.push_back(cur);
			else
				dy.push_back(cur);

			fl ^= 1;
			cur = 0;
		}
	}

	if (cur) {
		if (fl)
			dx.push_back(cur);
		else
			dy.push_back(cur);
	}

	/*for (auto it : dx)
		cout << it << ' ';
	cout << endl;
	for (auto it : dy)
		cout << it << ' ';*/

	d[0][N] = true;
	used[0][N] = true;
	bool x = calcX(dx.size(), tx + N);

	memset(d, false, sizeof(d));
	memset(used, false, sizeof(used));

	d[0][N] = true;
	used[0][N] = true;
	bool y = calcY(dy.size(), ty + N);

	if (x && y)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
}