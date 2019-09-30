#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>

using namespace std;

const int maxN = 510;

int n;
long long a[maxN];
set < long long > S;

vector < long long > get() {
	set < long long > b;
	while (b.size() != 10) {
		b.insert(a[rand() % n]);
	}
	vector < long long > res;
	for (set < long long > :: iterator it = b.begin(); it != b.end(); ++it) {
		res.push_back(* it);
	}
	return res;
}

vector < vector < long long > > res;

void solve(int test) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	S.clear();
	res.clear();

	srand(493992);
	

	long long good = -1;
	int index = 0;
	while (true) {
		++index;
		if (index % 100000 == 0) {
			cerr << index << endl;
		}
		vector < long long > b = get();
		long long sum = 0;
		for (int i = 0; i < b.size(); ++i)
			sum += b[i];
		
		res.push_back(b);
		if (S.find(sum) != S.end()) {
			cerr << "NICE" << endl;
			good = sum;
			break;
		}
		S.insert(sum);
	}

	printf("Case #%d:\n", test);
	int have = 0;
	for (int i = 0; i < res.size(); ++i) {
		vector < long long > b = res[i];
		long long sum = 0;
		for (int j = 0; j < b.size(); ++j)
			sum += b[j];
		if (sum == good) {
			for (int j = 0; j < b.size(); ++j)
				printf((j == 0) + " %lld", b[j]);
			printf("\n");
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int i = 1; i <= tests; ++i) {
		solve(i);
		cerr << i << endl;
	}
	return 0;
}