#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

int N, A, B;
vector<int> from[100];
vector<int> to[100];
vector<pair<int,int> > v;

int count(int n) {
	bitset<100> disable;

	for (int i = 0; i < B; i++) {
		int f = v[i].first;
		int t = v[i].second;
		if ((n >> i) & 1) {
			from[t].push_back(f);
			to[f].push_back(t);
		}
		else disable[f] = true;
	}

	queue<int> q;
	bitset<100> mark;

	for (int i = 0; i < N; i++) {
		if (from[i].size()==0) q.push(i);
	}

	while (!q.empty()) {
		int p = q.front(); q.pop();
		if (disable[p] || mark[p]) continue;
		mark[p] = true;

		for (auto a : to[p]) {
			bool flag = true;
			for (auto b : from[a]) {
				if (mark[b]==false) {
					flag = false;
					break;
				}
			}
			if(flag) q.push(a);
		}
	}

	for (int i = 0; i < B; i++) {
		int f = v[i].first;
		int t = v[i].second;
		if ((n >> i) & 1) {
			from[t].pop_back();
			to[f].pop_back();
		}
	}

	return mark.count();
}

int main(int argc, char const *argv[]) {
	cin >> N >> A;

	for (int i = 0; i < A; i++) {
		int x, y; cin >> x >> y;
		from[x-1].push_back(y-1);
		to[y-1].push_back(x-1);
	}

	cin >> B;
	for (int i = 0; i < B; i++) {
		int x, y; cin >> x >> y;
		v.push_back(pair<int,int>(x-1, y-1));
	}

	int answer = 0;
	for (int i = 0; i < (1 << B); i++) answer = max(answer, count(i));

	cout << answer << endl;

	return 0;
}