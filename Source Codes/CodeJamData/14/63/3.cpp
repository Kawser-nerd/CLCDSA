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

int n;
int color[10003];
vector<vector<int>> graph;

map<pair<int, int>, int> grpnumber;
map<vector<int>, int> group;

int getGroup(int a, int b) // edge b-> a, a as root
{
	if (grpnumber.count(make_pair(a, b)))
		return grpnumber[make_pair(a, b)];

	vector<int> children;
	for (auto next : graph[a]){
		if (next == b) {
			continue;
		}
		int res = getGroup(next, a);
		children.push_back(res);
	}

	sort(children.begin(), children.end());
	children.push_back(color[a]);

	if (group.count(children)) {
		int val = group[children];
		grpnumber[make_pair(a, b)] = val;
		return val;
	}
	int newIndex = group.size();
	group[children] = newIndex;
	grpnumber[make_pair(a, b)] = newIndex;
	return newIndex;
}



int main()
{
	int TT;
	scanf("%d", &TT);
	for (int testcase = 1; testcase <= TT; testcase ++)
	{
		fprintf(stderr, "Processing case %d\n", testcase);
		graph.clear();
		scanf("%d", &n);
		graph.resize(n);

		vector<pair<int, int>> edges;
		for (int i = 0; i < n; i++) {
			char color[128];
			scanf("%s", color);
			::color[i] = color[0];
		}
		for (int i = 0; i < n - 1; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			a--, b--;
			graph[a].push_back(b);
			graph[b].push_back(a);
			edges.emplace_back(a, b);
		}

		grpnumber.clear();
		group.clear();


		bool isSymmetric = false;

		for (auto edge : edges)
		{
			if (getGroup(edge.first, edge.second) == getGroup(edge.second, edge.first))
			{
				isSymmetric = true;
				break;
			}
		}

		for (int i = 0; i < n && !isSymmetric; i++)
		{
			int p = i;
			int parent = -1;
			int total = 1;
			bool fail = false;
			for (;p != -1;)
			{
				vector<pair<int,int>> children;
				for (auto next : graph[p])
				{
					if (next == parent) continue;
					children.emplace_back(getGroup(next, p), next);
				}
				sort(children.begin(), children.end());

				int single = -1;
				bool manySingle = false;
				for (int i = 0; i < children.size(); i++){
					if (i + 1 >= children.size() || children[i + 1].first != children[i].first) {
						if (single != -1) {
							manySingle = true;
							break;
						}
						single = children[i].second;
					}
					else {
						i++; // advance two
					}
				}

				if (manySingle) {
					fail = true;
					break;
				}

				parent = p;
				p = single;
			}

			if (fail) continue;

			isSymmetric = true;
			break;
		}

		if (isSymmetric)
		{
			printf("Case #%d: SYMMETRIC\n", testcase);
		}
		else
		{
			printf("Case #%d: NOT SYMMETRIC\n", testcase);
		}

		fprintf(stderr, "Finished case %d\n", testcase);
	}
}
