#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

#define MAX_LENGTH 200

vector <string> parseVS() {
	int c;
	scanf("%d\n", &c);
	vector <string> v;
	char buf[MAX_LENGTH];
	for (int i = 0; i < c; i++) {
		fgets(buf, MAX_LENGTH, stdin);
		v.push_back(string(buf));
	}
	return v;
}

#define MAX_ENGINES 500

int minSwitches(vector <string> engines, vector <string> queries) {
	int used[MAX_ENGINES];
	int ne = engines.size();
	for (int i = 0; i < ne; i++) used[i] = 0;
	int c = 0;
	int s = 0;
	for (int i = 0; i < queries.size(); i++) {
		int p;
		for (p = 0; p < ne; p++) {
			if (queries[i] == engines[p]) break;
		}
		if (p < ne && !used[p]) {
			c++;
			if (c == ne) {
				s++;
				for (int j = 0; j < ne; j++) used[j] = 0;
				c = 1;
			}
			used[p] = 1;
		}
	}
	return s;
}

int main() {
	int N;
	vector <string> engines;
	vector <string> queries;
	scanf("%d\n", &N);
	for (int i = 1; i <= N; i++) {
		engines = parseVS();
		queries = parseVS();
		int cnt = minSwitches(engines, queries);
		printf("Case #%d: %d\n", i, cnt);
	}
}

