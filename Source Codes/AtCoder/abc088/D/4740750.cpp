#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(i, n) repi(i, 0, n)
#define rerepi(i, a, b) for(int i = int(a)-1; i >= b; --i)
#define rerep(i, n) rerepi(i, n, 0)
#define uniq(v) v.erase( unique(v.begin(), v.end()), v.end() );

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;

// ?????????
ll H, W, shiro_count, marker[51][51], tmp;
string maps[51][51], inin;
queue<ll> Qx;
queue<ll> Qy;

int run() {
	if (Qx.empty()) {
		return 0;
	}
	ll x = Qx.front();
	ll y = Qy.front();
	Qx.pop();
	Qy.pop();
	ll base = marker[x][y];
	
	if (x+1 <= H && maps[x+1][y] != "#" && marker[x+1][y] == -1) {
		marker[x+1][y] = base + 1;
		Qx.push(x+1);
		Qy.push(y);
	}
	if (x-1 >= 1 && maps[x-1][y] != "#" && marker[x-1][y] == -1) {
		marker[x-1][y] = base + 1;
		Qx.push(x-1);
		Qy.push(y);
	}
	if (y+1 <= W && maps[x][y+1] != "#" && marker[x][y+1] == -1) {
		marker[x][y+1] = base + 1;
		Qx.push(x);
		Qy.push(y+1);
	}
	if (y-1 >= 1 && maps[x][y-1] != "#" && marker[x][y-1] == -1) {
		marker[x][y-1] = base + 1;
		Qx.push(x);
		Qy.push(y-1);
	}
	return 1;
}

int main() {
	cin >> H >> W;
	repi(i, 1, H+1) {
		cin >> inin;
		rep(j, inin.size()) {
			maps[i][j+1] = inin[j];
			if (maps[i][j+1] == ".") {
				shiro_count += 1;
			}
		}
	}
	repi(i, 1, H+1) {
		repi(j, 1, W+1) {
			marker[i][j] = -1;
		}
	}
	
	marker[1][1] = 0;
	Qx.push(1);
	Qy.push(1);
	
	while(1) {
		if (0 == run()) {
			break;
		}
	}
	
	tmp = marker[H][W];
	if (-1 == tmp) {
		cout << -1 << endl;
		return 0;
	}
	cout << shiro_count - (tmp+1) << endl;
	return 0;
}