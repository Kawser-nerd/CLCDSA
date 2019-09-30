#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Tile {
	long long x, y;
	char ch;
	bool operator<(const Tile& t) const {return x+y < t.x+t.y;}
};

int N;
vector<Tile> t;
inline long long LAbs(long long x) {return x < 0 ? -x : x;}

void Try(long long x, long long y, long long& retx, long long& rety) {
//cout << "  Trying " << x << ' ' << y << endl;
	long long d1 = LAbs(x) + LAbs(y);
	long long d2 = LAbs(retx) + LAbs(rety);
	if (d1 > d2) return;
	if (d1 < d2 || d1 == d2 && x > retx || d1 == d2 && x == retx && y > rety) {
		retx = x;
		rety = y;
//cout << "  ret is now " << retx << ' ' << rety << endl;
	}
}

main() {
	int T, prob = 1;
	for (cin >> T; T--;) {
		cin >> N;
		t.resize(N);
		for (int i = 0; i < N; i++) cin >> t[i].x >> t[i].y >> t[i].ch;
		sort(t.begin(), t.end());
		long long retx = 1e18, rety = 1e18;
		for (int i = 0; i <= N; i++)
		for (int px = 0; px < 2; px++)
		for (int py = 0; py < 2; py++) {
			long long mna = (i==0 ? -5e17 : t[i-1].x + t[i-1].y);
			long long mxa = (i==N ? 5e17 : t[i].x + t[i].y);
			if (mna == mxa) continue;
			long long mnb = -5e17;
			long long mxb = 5e17;
			bool fail = false;
			for (int j = 0; j < N && !fail; j++) {
				if (px == (t[j].x&1) && py == (t[j].y&1)) {
					if (t[j].ch == '#') fail = true;
				} else if (px != (t[j].x&1) && py != (t[j].y&1)) {
					if (t[j].ch == '.') fail = true;
				} else {
					bool upper = ((j < i) ^ (t[j].ch == '.') ^ (px == (t[j].x&1)));
					if (upper)
						mnb = max(mnb, t[j].x-t[j].y);
					else
						mxb = min(mxb, t[j].x-t[j].y);
				}
			}
			if (!fail && mna <= mxa && mnb <= mxb) {
				vector<long long> cd;
				for (int i = -3; i <= 3; i++) cd.push_back(i);
				for (int i = -3; i <= 3; i++) cd.push_back(mna+i);
				for (int i = -3; i <= 3; i++) cd.push_back(mxa+i);
				for (int i = -3; i <= 3; i++) cd.push_back(mnb+i);
				for (int i = -3; i <= 3; i++) cd.push_back(mxb+i);
				for (int i = -3; i <= 3; i++) cd.push_back(-mna+i);
				for (int i = -3; i <= 3; i++) cd.push_back(-mxa+i);
				for (int i = -3; i <= 3; i++) cd.push_back(-mnb+i);
				for (int i = -3; i <= 3; i++) cd.push_back(-mxb+i);
				for (int ai = 0; ai < cd.size(); ai++)
				for (int bi = 0; bi < cd.size(); bi++) {
					long long a = cd[ai], b = cd[bi];
					if ((a&1) != (b&1)) continue;
					if (a < mna || a > mxa) continue;
					if (b < mnb || b > mxb) continue;
					long long x = (a+b)/2, y = (a-b)/2;
					if (px != (x&1)) continue;
					if (py != (y&1)) continue;
					Try(x, y, retx, rety);
				}
//cout << px << ' ' << py << ' ' << mna << ',' << mxa << ' ' << mnb << ',' << mxb << ": " << retx << ',' << rety << endl;
			}
		}
		if (retx == 1e18) {
			cout << "Case #" << prob++ << ": Too damaged" << endl;
		} else {
			cout << "Case #" << prob++ << ": " << retx << ' ' << rety << endl;
		}
	}
}
