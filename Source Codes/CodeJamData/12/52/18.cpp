#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment (linker, "/STACK:200000000")
#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

typedef long long int64;
//typedef double old_double;
//#define double long double
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define pb  push_back
#define mp  make_pair


const int SZ = 6010;


const int dxy[6][2] = { {0,1}, {1,1}, {1,0}, {0,-1}, {-1,-1}, {-1,0} };


int s, m;
pair<int,int> a[11000];


void read() {
	cin >> s >> m;
	forn(i,m)
		scanf ("%d%d", &a[i].fs, &a[i].sc);
}


pair<int,int> corn[6];
bool stone[SZ][SZ];
int idx[SZ][SZ], q[SZ*SZ];
int msk_corn[1100000], msk_side[1100000];
int dsu[1100000];
bool ans_corn[11000], ans_side[11000], ans_cyc[11000];
int cbit[100000];


int dsu_get (int v) {
	return v==dsu[v] ? v : dsu[v] = dsu_get(dsu[v]);
}

void dsu_union (int a, int b) {
	a = dsu_get(a);
	b = dsu_get(b);
	dsu[b] = a;
	msk_corn[a] |= msk_corn[b];
	msk_side[a] |= msk_side[b];
}


int corner (int x, int y) {
	forn(i,6)
		if (mp(x,y) == corn[i])
			return i;
	return -1;
}

int side (int x, int y) {
	if (x == 1)  return 0;
	if (y == 1)  return 5;
	if (x == s+s-1)  return 3;
	if (y == s+s-1)  return 2;
	if (x <= s && y >= s && y == s+x-1)  return 1;
	if (x >= s && y <= s && x == s+y-1)  return 4;
	return -1;
}

bool inside (int x, int y) {
	if (x < 1 || y < 1 || x > s+s-1 || y > s+s-1)  return false;
	if (x <= s)
		return 1 <= y && y <= s+x-1;
	else
		return x-s+1 <= y && y <= s+s-1;
}

void bfs (int x, int y, int comp) {
	idx[x][y] = comp;
	int qh = 0,  qt = 0;
	q[qt++] = x * 10000 + y;
	while (qh != qt) {
		int x = q[qh] / 10000,
			y = q[qh] % 10000;
		++qh;
		if (idx[x][y] != comp)
			throw;

		int c = corner (x, y);
		int s = side (x, y);
		if (c != -1)
			msk_corn[comp] |= 1<<c;
		if (c == -1 && s != -1)
			msk_side[comp] |= 1<<s;

		forn(dir,6) {
			int nx = x + dxy[dir][0],
				ny = y + dxy[dir][1];
			if (inside (nx, ny) && !stone[nx][ny] && idx[nx][ny] == -1) {
				idx[nx][ny] = comp;
				q[qt++] = nx * 10000 + ny;
			}
		}
	}
}


void solve() {
	corn[0] = mp(1,1);
	corn[1] = mp(1,s);
	corn[2] = mp(s,s+s-1);
	corn[3] = mp(s+s-1,s+s-1);
	corn[4] = mp(s+s-1,s);
	corn[5] = mp(s,1);

	memset (stone, 0, sizeof stone);
	memset (ans_corn, 0, sizeof ans_corn);
	memset (ans_side, 0, sizeof ans_side);
	memset (ans_cyc, 0, sizeof ans_cyc);
	forn(i,m) {
		int x = a[i].fs,  y = a[i].sc;
		idx[x][y] = i;
		stone[x][y] = true;

		msk_corn[i] = msk_side[i] = 0;
		dsu[i] = i;

		int c = corner (x, y);
		int s = side (x, y);
		if (c != -1)
			msk_corn[i] |= 1<<c;
		if (c == -1 && s != -1)
			msk_side[i] |= 1<<s;

		forn(dir,6) {
			int nx = x + dxy[dir][0],
				ny = y + dxy[dir][1];
			if (stone[nx][ny])
				dsu_union (i, idx[nx][ny]);
		}

		int my = dsu_get (i);
		if (cbit[msk_corn[my]] >= 2)
			ans_corn[i] = true;
		if (cbit[msk_side[my]] >= 3)
			ans_side[i] = true;
	}

	int comps = 0;
	memset (idx, -1, sizeof idx);
	for (int x=1; x<=s+s-1; ++x)
		for (int y=1; y<=s+s-1; ++y)
			if (inside (x, y) && !stone[x][y] && idx[x][y] == -1) {
				dsu[comps] = comps;
				msk_corn[comps] = msk_side[comps] = 0;
				bfs (x, y, comps++);
			}
	for (int i=m-1; i>=0; --i) {
		int x = a[i].fs,  y = a[i].sc;
		if (!stone[x][y])  throw;
		stone[x][y] = false;
		idx[x][y] = comps++;

		dsu[comps-1] = comps-1;
		msk_corn[comps-1] = msk_side[comps-1] = 0;
		int c = corner (x, y);
		int s = side (x, y);
		if (c != -1)
			msk_corn[comps-1] |= 1<<c;
		if (c == -1 && s != -1)
			msk_side[comps-1] |= 1<<s;

		bool was_inner = false;
		forn(dir,6) {
			int nx = x + dxy[dir][0],
				ny = y + dxy[dir][1];
			if (inside (nx, ny) && !stone[nx][ny]) {
				int to = dsu_get (idx[nx][ny]);
				if (!msk_corn[to] && !msk_side[to])
					was_inner = true;
				dsu_union (comps-1, to);
			}
		}

		int my = dsu_get (comps-1);
		if (was_inner)
			if (msk_corn[my] || msk_side[my])
				ans_cyc[i] = true;
	}

	forn(i,m)
		if (ans_corn[i] || ans_side[i] || ans_cyc[i]) {
			bool fl = false;
			if (ans_corn[i]) {
				if (fl)  printf ("-");
				fl = true;
				printf ("bridge");
			}
			if (ans_side[i]) {
				if (fl)  printf ("-");
				fl = true;
				printf ("fork");
			}
			if (ans_cyc[i]) {
				if (fl)  printf ("-");
				fl = true;
				printf ("ring");
			}
			printf (" in move %d\n", i+1);
			return;
		}
	puts ("none");
}


int main() {
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);

	forn(i,100000)
		forn(j,20)
			if (i & (1<<j))
				++cbit[i];

	int ts;
	cin >> ts;
	forn(tt,ts) {
		read();
		if (! cin)  throw;
		printf ("Case #%d: ", tt+1);
		solve();
	}
}