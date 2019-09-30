#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int nex[1005];
int maxcyclength;
vector<int> pre[1005];
int sumtwo = 0;
bool visited[1005];

int findlongest(int x) {
  int res = 1;
  for (int i = 0; i < (int)pre[x].size(); i++) {
    if (!visited[pre[x][i]]) {
      visited[pre[x][i]] = true;
      res = max(res, findlongest(pre[x][i]) + 1);
    }
  }
  return res;
}

int main() {
  scanf("%d", &t);
  int cs =0;
  while (t--) {
    ++cs;
    maxcyclength = 0 ;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      pre[i].clear();
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &nex[i]);
      nex[i]--;
      pre[nex[i]].push_back(i);
    }
    sumtwo = 0;
    for (int i = 0; i < n; i++) {
      if (i == nex[nex[i]]) {
        //2 cycles
        memset(visited,0, sizeof(visited));
        visited[i] = true;
        visited[nex[i]] = true;
        int tmpi = findlongest(i);
        int tmpi2 = findlongest(nex[i]);
//        printf("%d: %d %d: %d\n", i, tmpi, nex[i], tmpi2);
        sumtwo += tmpi + tmpi2;
      }
    }
    sumtwo /= 2;
    for (int i = 0; i < n; i++) {
      int now = i;
      memset(visited, 0, sizeof(visited));
      int len = 0;
      while (!visited[now]) {
        visited[now] = true;
        now = nex[now];
        ++len;
      }
      if (now == i) {
        maxcyclength = max(maxcyclength, len);
      }
    }
    printf("Case #%d: %d\n", cs, max(sumtwo, maxcyclength));
  }
}
