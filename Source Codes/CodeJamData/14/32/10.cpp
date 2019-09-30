#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int N = (int) 100, MODULO = (int) 1e9 + 7;
int factorial[N + 1];
string s[N];

bool ok(string s) {
	string t = s;
	t.erase(unique(t.begin(), t.end()), t.end());
	sort(t.begin(), t.end());
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	return t == s;
}

int main() {
	factorial[0] = 1;
	for(int i = 1; i <= N; ++i)
		factorial[i] = 1LL * factorial[i - 1] * i % MODULO;
	int nTest; cin >> nTest;
	for(int test = 0; test < nTest; ++test) {
		int n; cin >> n;
		vector<int> full (26);
		for(int i = 0; i < n; ++i) {
			cin >> s[i];
			s[i].erase(unique(s[i].begin(), s[i].end()), s[i].end()); 
			if(s[i].size() == 1) ++full[s[i][0] - 'a'];
		}
		int groupCount = 0, res = 1;
		vector<bool> used (n);
		string curr = "", all = "";
		while(find(used.begin(), used.end(), false) != used.end()) {
			bool found = false;
			for(int i = 0; !found && i < n; ++i) if(!used[i] && s[i].size() == 1) {
				if(curr.empty()) curr = s[i], found = used[i] = true;
				else if(curr[0] == s[i][0]) curr = s[i] + curr, found = used[i] = true;
				else if(curr[curr.size() - 1] == s[i][0]) curr += s[i], found = used[i] = true;
			}
			if(found) continue;
			if(curr.empty()) {
				int x = find(used.begin(), used.end(), false) - used.begin();
				curr = s[x];
				found = used[x] = true;
			}
			if(found) continue;
			for(int i = 0; !found && i < n; ++i) if(!used[i]) {
				if(curr[0] == s[i][s[i].size() - 1]) curr = s[i] + curr, found = used[i] = true;
				else if(curr[curr.size() - 1] == s[i][0]) curr += s[i], found = used[i] = true;
			}
			if(found) continue;
			if(!ok(curr)) res = 0;
			++groupCount;
			all += curr;
			curr = "";
		}
		if(!curr.empty()) ++groupCount;
		if(!ok(curr)) res = 0;
		if(!ok(all += curr)) res = 0;
		for(int i = 0; i < 26; ++i) res = 1LL * res * factorial[full[i]] % MODULO;
		res = 1LL * res * factorial[groupCount] % MODULO;
		printf("Case #%d: %d\n", test + 1, res);
	}
	return 0;
}
