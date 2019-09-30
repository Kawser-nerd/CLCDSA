#include <stdio.h>
#include <string.h>
#include <vector>

int n;
int open[210], key[210], c2k[210], cnt[210];
std::vector<int> k2c[210], contain[210];
int vis[210], ans[210];
bool possible;

void DFS(int ii) {
    for (int i=0; i<k2c[ii].size(); i++) {
        if (!open[k2c[ii][i]]) {
            int c = k2c[ii][i];
            for (int j=0; j<contain[c].size(); j++) {
                if (!vis[contain[c][j]]) {
                    vis[contain[c][j]] = true;
                    DFS(contain[c][j]);
                }
            }
        }
    }
}

bool TestAndSet(int ii, int jj) {
    if (open[jj] || key[c2k[jj]] == 0) {
        return false;
    }
    bool ret = true;
    ans[ii] = jj;
    open[jj] = 1;
    key[c2k[jj]]--;
    for (int i=0; i<contain[jj].size(); i++) {
        key[contain[jj][i]]++;
    }

    memset(vis, 0, sizeof(vis));
    for (int i=0; i<200; i++) {
        if (key[i] != 0 && !vis[i]) {
            vis[i] = 1;
            DFS(i);
        }
    }
    for (int i=0; i<n; i++) {
        if (!open[i] && !vis[c2k[i]]) {
            ret = false;
        }
    }
    

    if (!ret) {
        open[jj] = 0;
        key[c2k[jj]]++;
        for (int i=0; i<contain[jj].size(); i++) {
            key[contain[jj][i]]--;
        }
    }
    return ret;
}

int main() {
    int casN;
    scanf("%d", &casN);
    for (int casI=0; casI<casN; casI++) {    
        int k, kc;
        scanf("%d%d", &kc, &n);
        possible = true;

        for (int i=0; i<kc; i++) {
            scanf("%d", &k);
            key[k-1]++;
        }
        for (int i=0; i<200; i++) cnt[i] = key[i];
        
        for (int i=0; i<n; i++) {    
            scanf("%d%d", &k, &kc);
            k2c[k-1].push_back(i);
            c2k[i] = k-1;
            cnt[k-1] --;
            for (int j=0; j<kc; j++) {
                scanf("%d", &k);
                contain[i].push_back(k-1);
                cnt[k-1] ++;
            }
        }

        
        for (int i=0; i<200; i++) {
            if (cnt[i] < 0) {
                possible = false;
            }
        }

        if (possible) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (TestAndSet(i, j)) {
                        break;
                    }
                    if (j == n-1) {
                        possible = false;
                    }
                }
                if (!possible) break;
            }
        }

        if (!possible) printf("Case #%d: IMPOSSIBLE\n", casI+1);
        else {
            printf("Case #%d:", casI+1); 
            for (int i=0; i<n; i++) printf(" %d", ans[i]+1);
            puts("");
        }

        memset(key, 0, sizeof(key));
        memset(open, 0, sizeof(open));
        for (int i=0; i<n; i++) {
            k2c[i].clear();
            contain[i].clear();
        }
    }
}
