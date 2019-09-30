#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int re, n;

	cin >> re;
	for (int ri = 1; ri <= re; ++ri) {
		cin >> n;
		vector<string> c(n);
		for (int i = 0; i < n; ++i) {
			cin >> c[i];
		}
		cin >> n;
		vector<string> d(n);
		for (int i = 0; i < n; ++i) {
			cin >> d[i];
		}
		cin >> n;
		string s;
		cin >> s;
		
		vector<char> x;
		for (string::const_iterator i = s.begin(); i != s.end(); ++i) {
			x.push_back(*i);
REDO:
			if (x.size() >= 2) {
				for (vector<string>::const_iterator j = c.begin(); j != c.end(); ++j) {
					if ((x[x.size() - 1] == j->at(0) && x[x.size() - 2] == j->at(1)) ||
						(x[x.size() - 2] == j->at(0) && x[x.size() - 1] == j->at(1))) {
						x.resize(x.size() - 2);
						x.push_back(j->at(2));
						goto REDO;
					}
				}
			}

			for (vector<string>::const_iterator k = d.begin(); k != d.end(); ++k) {
				if (count(x.begin(), x.end(), k->at(0)) > 0 &&
					count(x.begin(), x.end(), k->at(1)) > 0) {
					x.clear();
					break;
				}
			}
		}

		cout << "Case #" << ri << ": [";
		for (int i = 0; i < (int)x.size(); ++i) {
			if (i > 0) {
				cout << ", ";
			}
			cout << x[i];
		}
		cout << "]" << endl;
	}

	return 0;
}

