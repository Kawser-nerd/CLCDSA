#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> adj[100001];
int n,os[100001],chs[100001],sum[100001];
char str[100010];

int ans,cost;

void get_sum(int cur,int p) {
	sum[cur] = os[cur];
	for(auto &it:adj[cur]) if(it!=p) {
		get_sum(it,cur);
		sum[cur] += sum[it];
	}
}
void dfs(int cur,int p) {
	int cnt=0;
	for(auto &it:adj[cur]) {
		if(it==p) cnt++;
		else if(sum[it]) {
			dfs(it,cur);
			cnt++;
		}
	}
	cost += cnt + (cnt%2 ^ os[cur]);
	chs[cur] = cnt%2 ^ os[cur];
}
int get_ans(int cur,int p) {
	int d1=0,d2=0;
	for(auto &it:adj[cur]) if(it!=p) {
		if(!sum[it]) continue;

		int val = get_ans(it,cur);
		if(val > d1) {
			d2=d1; d1=val;
		} else if(val > d2) {
			d2=val;
		}
	}
	ans = min(ans,cost-d1-d2-1-chs[cur]+(chs[cur]^1));
	return d1 + 1+chs[cur]-(chs[cur]^1);
}

int main() {
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	scanf("%s",&str[1]);
	for(int i=1;i<=n;i++){
		if(str[i]=='W') os[i]=1;
	}

	int root=0;
	for(int i=1;i<=n;i++) if(os[i]) {
		root=i;
		break;
	}

	if(!root) {
		puts("0");
		return 0;
	}

	get_sum(root,0);
	dfs(root,0);
	ans = cost;
	if(sum[root]!=1) 
		get_ans(root,0);
	
	printf("%d\n",ans);

	return 0;
}