#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int tam[1000];

vector<int> adj[1000];
int T, teste;
int n,a,b;

int dfs(int v, int p, int r) {
	tam[v] = 1;

	int ch = adj[v].sz;
	if (p != -1) ch--;

	int b1 = 0;
	int b2 = 0;
	for (int i = 0; i < adj[v].size(); i++) {
		int th = adj[v][i];
		if (th == p) continue;

		int rem = dfs(th, v, r);

		tam[v] += tam[th];
		rem = tam[th]-rem;

		if (rem > b1) {
			swap(b1,b2);
			b1=rem;
		}
		else if (rem > b2) b2=rem;
	}

	if (ch == 0) return 0;
	else if (ch == 1) return tam[v] - 1;
	return tam[v] - 1 - b1 - b2;
}

int main() {
	for (scanf("%d", &T); T; T--) {
		printf("Case #%d: ", ++teste);

		scanf("%d", &n);
		for (int i=0; i<n; i++) adj[i].clear();
			
		for (int i=0; i < n-1; i++) {
			scanf("%d %d", &a, &b); a--; b--;
			adj[a].pb(b); adj[b].pb(a);
		}

		int ans = n;
		for (int root = 0; root < n; root++) {
			ans = min(ans, dfs(root, -1, root));
		}

		printf("%d\n", ans);
	}	
}