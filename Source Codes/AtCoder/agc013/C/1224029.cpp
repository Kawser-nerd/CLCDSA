#include <algorithm>
#include <queue>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

#include <cstdio>
inline int getInt(){ int s; scanf("%d", &s); return s; }

#include <set>

using namespace std;

int main(){
  const int n = getInt();
  const int l = getInt();
  const int t = getInt();

  vector<int> x(n);
  vector<int> w(n);

  REP(i,n){
    x[i] = getInt();
    w[i] = getInt();
  }

  int k = 0;
  while(k != n && w[k] != 1) k++;

  if(k == n){
    REP(i,n){
      int p = (x[i] - t) % l;
      if(p < 0) p += l;
      printf("%d\n", p);
    }
    return 0;
  }

  int cnt = 0;

  REP(i,n) if(w[(k + i) % n] == 2){
    int xx = x[(k + i) % n];
    if(xx < x[k]) xx += l;

    int diff = xx - x[k];
    int dt = diff / 2 + diff % 2;

    if(dt < t) {
      cnt++;

      int rest = t - dt;
      cnt += 2 * (rest / l);

      if(diff % 2 == 0 && rest % l == 0) cnt--;

      const int r = rest % l;

      if(l - diff % 2 == 0){
        if(r + r > l - diff % 2) cnt++;
      }else{
        if(r + r >= l - diff % 2) cnt++;
      }
    }else if(dt == t && diff % 2 == 1){
      cnt++;
    }
  }

  // printf("%d %d\n", k, cnt);
  vector<int> ans(n);
  int kp = 0;
  REP(i,n){
    const int idx = (k + i) % n;
    int xx = (x[idx] + (w[idx] == 2 ? -t : t)) % l;
    if(xx < 0) xx += l;
    ans[i] = xx;
    if(i == 0) kp = xx;
  }

  sort(ans.begin(), ans.end());
  int idx = 0; while(ans[idx] != kp) idx++;
  int zidx = (idx - k - cnt) % n;
  if(zidx < 0) zidx += n;
  // printf("%d %d %d %d\n", k, cnt, kp, idx);

  REP(i,n) printf("%d\n", ans[(zidx + i) % n]);

  return 0;
}