// Adrian Kügel
#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <assert.h>
#include <limits.h>
#include <complex>
#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;

typedef set<int> SI;
typedef map<int, int> MII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef complex<double> tComp;
typedef pair<short, int> PCI;
typedef vector<VI> VVI;

string dict[10000],dl[10000][26];

int main() {
	int tc;
	scanf("%d", &tc);
	for (int scen=1; scen<=tc; ++scen) {
		printf("Case #%d:", scen);
		int n, m;
		cin >> n >> m;
		VVI ogroups;
		MII used;
		for (int i=0; i<n; ++i) {
			cin >> dict[i];
			for (char c='a'; c<='z'; ++c) {
				dl[i][c-'a'] = "";
				for (int j=0; j<(int)dict[i].size(); ++j)
					dl[i][c-'a'] += (dict[i][j] == c ? '1' : '0');
			}
			if (used.find(dict[i].size()) == used.end()) {
				used[dict[i].size()] = ogroups.size();
				ogroups.push_back(VI(1, i));
			}
			else
				ogroups[used[dict[i].size()]].push_back(i);
		}
		string order;
		while(m--) {
			cin >> order;
			VVI groups = ogroups;
			VI nguess(groups.size(), 0);
			for (int jj=0; jj<26; ++jj) {
				int j = order[jj] - 'a';
				VVI groups2;
				VI nguess2;
				for (int i=0; i<(int)groups.size(); ++i) {
					map<string, vector<int> > ng;
					for (VI::iterator it=groups[i].begin(); it!=groups[i].end(); ++it)
						ng[dl[*it][j]].push_back(*it);
					for (map<string, vector<int> >::iterator it=ng.begin(); it!=ng.end(); ++it) {
						groups2.push_back(it->second);
						nguess2.push_back(nguess[i] + (ng.size()>1 && find(it->first.begin(), it->first.end(), '1') >= it->first.end()));
					}
				}
				groups = groups2;
				nguess = nguess2;
			}
			assert(groups.size() == n);
			int best = -1, ind;
			for (int i=0; i<(int)groups.size(); ++i) {
			//	printf("%d %d\n", i, nguess[i]);
				assert(groups[i].size() == 1);
				if (nguess[i] > best || nguess[i] == best && groups[i][0] < ind) {
					best = nguess[i];
					ind = groups[i][0];
				}
			}
			printf(" %s", dict[ind].c_str());
		}
		puts("");
	}
	return 0;
}
