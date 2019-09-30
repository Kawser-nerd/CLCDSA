// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int h, w;
	cin >> h >> w;
	vector<string> b(h + 1);
	for (int i = 0; i < h; ++i) {
		cin >> b[i];
		b[i] += '#';
	}
	b[h] = string(w + 1, '#');
	bool win[100][100] = {};
	for (int i = h - 1; i >= 0; --i) {
		for (int j = w - 1; j >= 0; --j) {
			if (b[i][j] != '#') {
				bool w = false;
				if (b[i][j + 1] != '#' && !win[i][j + 1]) {
					w = true;
				}
				if (b[i + 1][j + 1] != '#' && !win[i + 1][j + 1]) {
					w = true;
				}
				if (b[i + 1][j] != '#' && !win[i + 1][j]) {
					w = true;
				}
				win[i][j] = w;
			}
		}
	}
	cout << (win[0][0] ? "First" : "Second") << endl;
	return 0;
}