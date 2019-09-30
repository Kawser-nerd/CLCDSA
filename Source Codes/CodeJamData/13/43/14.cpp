#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<cmath>
using namespace std; typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int T, N;
int A[2000], B[2000];
ivec graph[2000];
int ret[2000], tid;
bool vis[2000];

void parse(vector< pair<int, int> > V)
{
	for(int i=0;i<V.size();i++){
		for(int j=i-1;j>=0;j--) if(V[j].second == V[i].second-1){
			graph[V[i].first].push_back(V[j].first);
			break;
		}
		for(int j=i-1;j>=0;j--) if(V[j].second == V[i].second){
			graph[V[j].first].push_back(V[i].first);
			break;
		}
	}
}

vector<int> childs;
void find_child(int p)
{
	if(vis[p]) return; vis[p] = true;
	childs.push_back(p);

	for(int i=0;i<graph[p].size();i++) find_child(graph[p][i]);
}

void top_sort(int p)
{
	if(ret[p] != -1) return;

	for(int i=0;i<N;i++) vis[i] = false;
	childs.clear();
	find_child(p);

	ivec ch = childs;
	sort(ch.begin(), ch.end());

	for(int i=0;i<ch.size();i++) if(ch[i] != p) top_sort(ch[i]);

	ret[p] = ++tid;
}

int main()
{
	scanf("%d", &T);
	for(int t=0;t++<T;){
		scanf("%d", &N);
		for(int i=0;i<N;i++) graph[i].clear();

		for(int i=0;i<N;i++) scanf("%d", A+i);
		for(int i=0;i<N;i++) scanf("%d", B+i);

		vector<pair<int, int> > V;
		for(int i=0;i<N;i++){
			V.push_back(make_pair(i, A[i]));
		}
		parse(V);
		V.clear();
		for(int i=0;i<N;i++){
			V.push_back(make_pair(i, B[i]));
		}
		reverse(V.begin(), V.end());
		parse(V);

		tid = 0;
		for(int i=0;i<N;i++) ret[i] = -1;
		for(int i=0;i<N;i++) top_sort(i);

		printf("Case #%d:", t);
		for(int i=0;i<N;i++) printf(" %d", ret[i]);
		puts("");
	}

	return 0;
}
