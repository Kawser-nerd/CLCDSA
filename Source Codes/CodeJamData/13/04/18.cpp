#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 205;

int n, k, box[N], cnt[N], key[N], qtail, qhead, q[N], nowkey[N], nowkeys[N];
bool g[N][N], vis[N], used[N]; 
vector<int> cot[N];

bool check() {
	memset(nowkey, 0, sizeof(nowkey));
	for (int i = 0; i <= n; ++i) {
	  if (used[i]) {
	    if (i != 0) nowkey[key[i]]--;
	    for (int j = 0; j < cot[i].size(); ++j) {
	      nowkey[cot[i][j]]++;
			}
		}
	}
	
	memset(g, 0, sizeof(g));
	for (int i = 1; i <= n; ++i) {
		if (used[i]) continue;
	  for (int j = 1; j <= n; ++j) {
	    if (i == j || used[j]) continue;
	    for (int k = 0; k < cot[i].size(); ++k) {
	      if (cot[i][k] == key[j]) {
	        g[i][j] = true;
				}
			}
		}
	}
	for (int j = 1; j <= n; ++j) {
	  if (!used[j] && nowkey[key[j]] > 0) {
	  	g[0][j] = true;
		}
	}
	
	bool f1 = true;
	
	memset(vis, 0, sizeof(vis));
	qhead = 0; qtail = 1; q[1] = 0;
	while (qhead < qtail) {
	  int i = q[++qhead];
		for (int j = 1; j <= n; ++j) {
	    if (!vis[j] && g[i][j]) {
	      vis[j] = true;
	      q[++qtail] = j;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
	  if (!(vis[i] || used[i])) f1 = false;
	}
	
	return f1;
}

int main() {
	freopen("D.in", "r", stdin);
	freopen("D2.out", "w", stdout);
	
	int T, tmp, m;
	scanf("%d", &T);
	for (int V = 1; V <= T; ++V) {
		memset(box, 0, sizeof(box));
		memset(cnt, 0, sizeof(cnt));
		scanf("%d %d", &k, &n);
	  for (int i = 0; i <= n; ++i) cot[i].clear();
	  for (int i = 1; i <= k; ++i) {
	    scanf("%d", &tmp);
	    cot[0].push_back(tmp);
	    cnt[tmp]++;
		}
		for (int i = 1; i <= n; ++i) {
		  scanf("%d %d", &key[i], &m);
		  box[key[i]]++;
		  for (int j = 1; j <= m; ++j) {
		    scanf("%d", &tmp);
		    cot[i].push_back(tmp);
			  cnt[tmp]++;
			}
		}
		
		bool f2 = true;
		for (int i = 1; i <= 200; ++i) {
		  if (box[i] > cnt[i]) f2 = false;
		}
				
		memset(used, 0, sizeof(used));
		used[0] = true;
		memset(nowkeys, 0, sizeof(nowkeys));
		for (int i = 0; i < cot[0].size(); ++i) {
		  nowkeys[cot[0][i]]++;
		}
		if (!f2 || !check()) {
		  printf("Case #%d: IMPOSSIBLE\n", V);
		} else {
		  printf("Case #%d:", V);
		  for (int i = 1; i <= n; ++i) {
		    for (int j = 1; j <= n; ++j) {
		      if (used[j] || nowkeys[key[j]] <= 0) continue;
		      used[j] = true;
		      if (check()) {
		      	printf(" %d", j);
		      	--nowkeys[key[j]];
		      	for (int k = 0; k < cot[j].size(); ++k) {
		      	  nowkeys[cot[j][k]]++;
						}
		      	break;
		      } else {
		        used[j] = false;
					}
				}
			}
		  printf("\n");
		}
	}
	return 0;
}

