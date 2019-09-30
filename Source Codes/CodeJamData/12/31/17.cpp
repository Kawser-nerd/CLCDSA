#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
vector<int> con[1000];
bool vis[1000];

bool visit(int p)
{
	if(vis[p]) return true;
	vis[p] = true;

	for(int i=0;i<con[p].size();i++) if(visit(con[p][i])) return true;
	return false;
}

int main()
{
	scanf("%d", &T);
	for(int t=0;t<T;){
		scanf("%d", &N);
		for(int i=0;i<N;i++){
			int m, v;
			scanf("%d", &m);
			for(;m--;){
				scanf("%d", &v);
				con[i].push_back(v-1);
			}
		}

		bool ret = true;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++) vis[j] = false;
			if(visit(i)) ret = false;
		}

		for(int i=0;i<N;i++) con[i].clear();
		printf("Case #%d: %s\n", ++t, ret ? "No" : "Yes");
	}
	return 0;
}
