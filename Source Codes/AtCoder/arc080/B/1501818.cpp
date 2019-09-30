#include <iostream>
#include <cstring>
using namespace std;

int mp[110][110];
int sa[10010];
int h, w, n;

int main() {
	while (cin >> h >> w) {
		cin >> n;
		memset(mp, 0, sizeof(mp));
		for (int i = 1; i <= n; i++)
			cin >> sa[i];
		int ii = 0, jj = 0, cc = 1;
		int cas = h * w;
		while (cas--) {
			while (sa[cc] == 0) {
				cc++;
			}
			mp[ii][jj] = cc;
			sa[cc]--;;
			if (jj % 2 == 0) {
				ii++;
				if (ii >= w) {
					ii = w - 1;
					jj++;
				}
			}else {
				ii--;
				if (ii < 0) {
					ii = 0;
					jj++;
				}
			}
		}
		for (int j = 0; j < h; j++) {
			for (int i = 0; i < w; i++) {
				if (i)
					cout << " " << mp[i][j];
				else
					cout << mp[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}