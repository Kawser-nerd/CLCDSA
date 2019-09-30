#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 100 * 1000 + 100;
const int inf = 1000 * 1000;

char buf[size];

struct edge {
	int tg, cap, flow, back;

	edge(int tg = 0, int cap = 0, int flow = 0, int back = 0) : tg(tg), cap(cap), flow(flow), back(back) {}
};

vector <edge> vertex[size];

void addedge(int v, int u, int c) {
	edge e1(u, c, 0, vertex[u].size());
	edge e2(v, 0, 0, vertex[v].size());

	vertex[v].pb(e1);
	vertex[u].pb(e2);	
}

map <string, int> nums;
set <string> words;
vector <string> sentenses[size];
bool used[size];
int start, finish, total;
int n;

int tc;

bool dfs(int v) {
	if (v == finish)
		return true;
	used[v] = true;
	for (int i = 0; i < (int) vertex[v].size(); i++)
		if (vertex[v][i].flow < vertex[v][i].cap && (!used[vertex[v][i].tg] && dfs(vertex[v][i].tg))) {
			vertex[v][i].flow++;
			vertex[vertex[v][i].tg][vertex[v][i].back].flow--;

			return true;
		}

	return false;
}

int findflow() {
	int flow = 0;
	while (true) {
		for (int i = 0; i < total; i++)
			used[i] = false;
		if (dfs(start))
			flow++;
		else
			break;
	}

	return flow;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &tc);
    for (int tnum = 0; tnum < tc; tnum++) {
    	scanf("%d\n", &n);

    	words.clear();
    	for (int i = 0; i < n; i++) {
    		sentenses[i].clear();
    		fgets(buf, size, stdin);
    		stringstream ss(buf);
    		string str;

    		while (ss >> str) {
    			words.insert(str);
    			sentenses[i].pb(str);
    		}
    	}

    	int m = words.size();
    	total = n + 2 * m;
    	int cnt = 0;
    	nums.clear();
    	for (set <string>::iterator it = words.begin(); it != words.end(); ++it) {
    		nums[*it] = cnt++;
    	}

    	for (int i = 0; i < total; i++)
    		vertex[i].clear();
    	start = 0;
    	finish = 1;
    	for (int i = 0; i < m; i++)
    		addedge(n + 2 * i, n + 2 * i + 1, 1);
    	for (int i = 0; i < n; i++)
    		for (int j = 0; j < (int) sentenses[i].size(); j++) {
    			int rn = nums[sentenses[i][j]];
    			addedge(i, n + 2 * rn, inf);
    			addedge(n + 2 * rn + 1, i, inf);
    		} 

    	cerr << tnum + 1 << endl;
    	printf("Case #%d: %d\n", tnum + 1, findflow());
    }


    return 0;
}