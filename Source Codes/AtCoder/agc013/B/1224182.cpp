#include <cstdio>
inline int getInt(){ int s; scanf("%d", &s); return s; }

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#include <deque>
#include <queue>
#include <set>

using namespace std;

vector<int> g[100000];

int main(){
  const int n = getInt();
  const int m = getInt();

  REP(i,m){
    const int a = getInt() - 1;
    const int b = getInt() - 1;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> use(n);
  deque<int> ans;

  REP(i,2){
    int cur = 0;
    use[cur] = 0;

    while(true){
      use[cur] = 1;
      if(i == 0) ans.push_back(cur);
      else if(cur != 0) ans.push_front(cur);

      REP(i,g[cur].size()){
        const int next = g[cur][i];
        if(use[next] == 0) {
          cur = next;
          break;
        }
      }

      if(use[cur] == 1) break;
    }
  }

  printf("%d\n", (int)ans.size());
  REP(i,ans.size())
    printf("%d%c", ans[i] + 1, i == (int)ans.size() - 1 ? '\n' : ' ');

  return 0;
}