#include <map>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> dic;

string show(string s, char c) {
	for (int i = 0; i < (int)s.length(); ++i) {
		s[i] = s[i] == c ? '1' : '0';
	}
	return s;
}

pair<int, int> gao(int c, const vector<int>& v, const string& s) {
	if (s.empty()) {
		return make_pair(c, v[0]);
	} else {
		map<string, vector<int> > mp;
		for (int i = 0; i < (int)v.size(); ++i) {
			mp[show(dic[v[i]], s[0])].push_back(v[i]);
		}
		pair<int, int> ret = make_pair(1, -1);
		for (map<string, vector<int> >::const_iterator it = mp.begin(); it != mp.end(); ++it) {
			bool d = mp.size() > 1 && count(it->first.begin(), it->first.end(), '1') == 0;
			ret = min(ret, gao(c - (d ? 1 : 0), it->second, s.substr(1)));
		}
		return ret;
	}
}

int main() {
	int re, n, m;
	string s;
	vector<int> v[12];
	pair<int, int> ans;

	cin >> re;
	for (int ri = 1; ri <= re; ++ri) {
		cin >> n >> m;
		dic.resize(n);
		for (int i = 1; i <= 10; ++i) {
			v[i].clear();
		}
		for (int i = 0; i < n; ++i) {
			cin >> dic[i];
			v[dic[i].length()].push_back(i);
		}

		cout << "Case #" << ri << ":";
		for (int i = 0; i < m; ++i) {
			cin >> s;
			ans = make_pair(1, -1);
			for (int i = 1; i <= 10; ++i) {
				if (!v[i].empty()) {
					ans = min(ans, gao(0, v[i], s));
				}
			}
		//	cout << "[" << ans.first << "," << ans.second << "]";
			cout << " " << dic[ans.second];
		}
		cout << endl;
	}

	return 0;
}

