// D.

#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int h, w;
	cin >> h >> w;
	int b[500][500];
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> b[i][j];
		}
	}
	vector<string> ans;
	int c = 0, px, py;
	for (int i = 0; i < h; ++i) {
		int st = i % 2 ? 0 : w - 1;
		int ed = i % 2 ? w : -1;
		int dir = i % 2 ? 1 : -1;
		for (int j = st; j != ed; j += dir) {
			if (c) {
				char w[64];
				sprintf(w, "%d %d %d %d", py + 1, px + 1, i + 1, j + 1);
				ans.push_back(w);
				b[i][j]++;
			}
			c = b[i][j] % 2;
			py = i, px = j;
		}
	}
	cout << ans.size() << endl;
	for (string s : ans) {
		cout << s << endl;
	}
	return 0;
}