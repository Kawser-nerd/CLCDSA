#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

template<class T> int size(const T & a) {
	return (int)a.size();
}
template<class T> T sqr(const T &a) {
	return a * a;
}
typedef struct SNode *PNode;
struct SNode {
	map<string, PNode> next;
	SNode() {
		next.clear();
	}
	int Add(int i, vector<string> &vs) {
		if (i == size(vs)) return 0;
		int add = 0;
		if (next.find(vs[i]) == next.end()) {
			add = 1;
			next[vs[i]] = new SNode();
		}
		return add + next[vs[i]]->Add(i + 1, vs);
	}
} head;
vector<string> split(string s) {
	vector<string> res;
	s.erase(0, 1);
	while (size(s)) {
		string cur = "";
		for (; size(s);) {
			if (s[0] == '/') break;
			cur += s[0];
			s.erase(0, 1);
		}
		res.push_back(cur);
		if (size(s)) {
			s.erase(0, 1);
		}
	}
	return res;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int ntests;
	scanf("%d", &ntests);
	for (int itest = 1; itest <= ntests; itest++) {
		printf("Case #%d: ", itest);
		int n, m;
		scanf("%d%d", &n, &m);
		head.next.clear();
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			vector<string> vs = split(s);
			head.Add(0, vs);
		}
		int res = 0;
		for (int i = 0; i < m; i++) {
			string s;
			cin >> s;
			vector<string> vs = split(s);
			res += head.Add(0, vs);
		}
		cout << res << endl;

	}
	return 0;
}