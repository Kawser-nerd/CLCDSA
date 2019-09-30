#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <memory.h>
#include <algorithm>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <functional>
#include <numeric>

#include <thread>
#include <atomic>
#include <chrono>

using namespace std;



vector<int> vs;
int vcnt;

vector<int> emit;


void dfs(const vector<vector<int>> &graph, int nod, bool reversed) {
	int n = graph.size();
	vs[nod] = vcnt;
	for (int i = 0; i < n; i++) {
		if (vs[i] == vcnt) continue;
		if (!reversed)
		{
			if (graph[nod][i] == 0) continue;
			dfs(graph, i, reversed);
		}
		else {
			if (graph[i][nod] == 0) continue;
			dfs(graph, i, reversed);
		}
	}
	emit.push_back(nod);
}

int realA;

vector<int> solve(int n, int A, vector<vector<int>> graph, vector<int> originalIndex, vector<vector<int>> &originalGraph, int whatIHave) // adjacency matrix
{
	vector<int> ans;
	bool canChange = false;
	if (n == 1) {
		
		if (whatIHave == -1 || originalGraph[whatIHave][originalIndex[0]]) {
			whatIHave = originalIndex[0];
		}
		if (whatIHave == realA){
			ans.push_back(0);
		}
		return ans;
	}
	else
	{
		++vcnt;


		emit.clear();
		for (int i = 0; i < n; i++) {
			if (vs[i] == vcnt) continue;
			dfs(graph, i, false);
		}

		++vcnt;
		vector<int> firstGroup;
		vector<int> q(emit.rbegin(), emit.rend());

		bool needRemoval = false;
		if (A == -1) {
			needRemoval = true;
		}
		for (auto start : q) {
			if (vs[start] == vcnt) continue;
			emit.clear();
			dfs(graph, start, true);
			if (firstGroup.empty()) {
				firstGroup = emit;
			}

			if (needRemoval){
				bool fail = false;
				if (whatIHave == -1) {
					fail = true;
				}
				else {
					for (auto e : emit) {
						if (!originalGraph[originalIndex[e]][whatIHave])
						{
							fail = true;
							break;
						}
					}
				}
				if (fail) return ans;
			}
			else {
				if (whatIHave == -1) {
					canChange = true;
				}
				else {
					for (auto e : emit) {
						if (originalGraph[whatIHave][originalIndex[e]])
						{
							canChange = true;
							break;
						}
					}
				}
			}

			if (find(emit.begin(), emit.end(), A) == emit.end()) {
				// not found
			}
			else {
				needRemoval = true;
			}
		}

		if (A == -1){
			for (int i = 0; i < n; i++) {
				ans.push_back(i);
			}
			return ans;
		}

		if (canChange)
		{
			for (int pathStart = 0; pathStart < n; pathStart++) {
				vector<vector<int>> newGraph(n-1, vector<int>(n-1));
				for (int i = 0; i < n; i++)
				{
					if (i == pathStart) continue;
					for (int j = 0; j < n; j++) {
						if (j == pathStart) continue;
						newGraph[i - (i >= pathStart)][j - (j >= pathStart)] = graph[i][j];
					}
				}
				vector<int> newStartings;
				for (int i = 0; i < n-1; i++) {
					newStartings.push_back(originalIndex[i + (i >= pathStart)]);
				}

				if (pathStart == A)
				{
					if (whatIHave == -1 || originalGraph[whatIHave][originalIndex[pathStart]])
					{
						auto sub = solve(n - 1, -1, newGraph, newStartings, originalGraph, originalIndex[pathStart]);
						if (sub.empty()) continue;

						ans.push_back(pathStart);
						for (auto s : sub) {
							ans.push_back(s + (s >= pathStart));
						}
						break;
					}
				}
				else
				{
					if (whatIHave == -1 || originalGraph[whatIHave][originalIndex[pathStart]])
					{
						// changes
						auto sub = solve(n - 1, A - (A >= pathStart), newGraph, newStartings, originalGraph, originalIndex[pathStart]);
						if (sub.empty()) continue;

						ans.push_back(pathStart);
						for (auto s : sub) {
							ans.push_back(s + (s >= pathStart));
						}
						break;
					}
					else
					{
						// remains
						auto sub = solve(n - 1, A - (A >= pathStart), newGraph, newStartings, originalGraph, whatIHave);
						if (sub.empty()) continue;

						ans.push_back(pathStart);
						for (auto s : sub) {
							ans.push_back(s + (s >= pathStart));
						}
						break;
					}
				}
			}
		}
	}

	if (canChange && ans.empty())
	{
		ans = ans;
	}
	return ans;
}

int n, A;
char line[1024];

int main()
{
	int TT;
	scanf("%d", &TT);
	for (int testcase = 1; testcase <= TT; testcase ++)
	{
		fprintf(stderr, "Processing case %d\n", testcase);
		scanf("%d%d", &n, &A);
		realA = A;
		vs.clear();
		vcnt = 0;
		vs.resize(n);
		vector<vector<int>> graph(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			scanf("%s", line);
			for (int j = 0; j < n; j++) {
				if (line[j] == '-') continue;
				if (line[j] == 'Y') {
					graph[j][i] = 1;
				}
				else {
					graph[j][i] = 0;
				}
			}
		}

		vector<int> availableStartings;
		for (int i = 0; i < n; i++) availableStartings.push_back(i);
		auto res = solve(n, A, graph, availableStartings, graph, -1);

		if (res.empty()) {
			printf("Case #%d: IMPOSSIBLE\n", testcase);
		}
		else {
			printf("Case #%d:", testcase);
			for (auto val : res) {
				printf(" %d", val);
			}
			printf("\n");
		}
		fprintf(stderr, "Finished case %d\n", testcase);
	}
	return 0;
}