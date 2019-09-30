#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

int N, phase[3];
vector<int> empty;
const int MOD = 1000000007;
// last???352716????
void normalize(vector<int> &a) {
  int sum = 0;
  for(int i = a.size() - 1; i >= 0; i--) {
    if(sum + a[i] >= phase[0] + phase[1] + phase[2]) {
      a.erase(a.begin(), a.begin() + i + 1);
      return;
    }
    sum += a[i];
  }
}
int sum[24];
int rec(int pos, const vector<int> &last, int csum, int p) {
  if(pos == N && p == 3) {
    return 1;
  }else if(pos == N) {
    return 0;
  }
  cout << pos << "," << csum << "," << p << endl;
  int res = 0;
  if(p == 3) {
    for(int i = 1; i <= 10; i++) {
      res += rec(pos + 1, empty, 0, 3);
      if(res >= MOD) res -= MOD;
    }
    return res;
  }
  int psum = phase[p];
  for(int j = 1; j <= 10; j++) {
    vector<int> next = last;
    if(csum + j < psum) {
      next.push_back(j);
      normalize(next);
      res += rec(pos + 1, next, csum + j, p);
    }else if(csum + j == psum) {
      next.push_back(j);
      normalize(next);
      res += rec(pos + 1, next, 0, p + 1);
    }else if(csum + j > psum) {
      next.push_back(j);
      sum[0] = 0;
      for(int i = 0; i < next.size(); i++) {
        sum[i + 1] = sum[i] + next[i];
      }
      bool found = false;
      for(int i = 0; i < next.size() && !found; i++) {
        for(int k = i + 1; k <= next.size() && !found; k++) {
          if(sum[k] - sum[i] == phase[0]) {
            int remain = sum[next.size()] - sum[k];
            // phase1???
            if(sum[next.size()] = sum[k] >= phase[1]) {
              for(int l = k + 1; l <= next.size(); l++) {
                if(sum[l] - sum[k] == phase[1]) {
                  remain = sum[next.size()] - sum[l];
                  if(remain < phase[2]) {
                    normalize(next);
                    res += rec(pos + 1, next, remain, 2);
                    found = true;
                  }else if(remain == phase[2]) {
                    res += rec(pos + 1, empty, 0, 3);
                    found = true;
                  }
                }
              }
            } else {
              normalize(next);
              res += rec(pos + 1, next, remain, 1);
              found = true;
            }
          }
        }
      }
      if(!found) {
        for(int i = 0; i <= next.size() && !found; i++) {
          if(sum[next.size()] - sum[i] < phase[0]) {
            res += rec(pos + 1, next, sum[next.size()] - sum[i] , 0);
            found = true;
          }
        }
      }
    }
    if(res >= MOD) res -= MOD;
  }
  return res;
}
// 5-7-5???????
const int MAX_P = 126 * 126 * 462;
char cs[MAX_P][5 + 7 + 5 + 1];
int cscnt = 0;

char curstr[5 + 7 + 5 + 1];
void rec(int pos, int cur, int p) {
  if(p == 3){
    memcpy(cs[cscnt++], curstr, pos);
  }else{ 
    for(int i = 1; i <= 10; i++) {
      if(i + cur > phase[p]) break;
      if(i + cur == phase[p]) {
        curstr[pos] = i;
        rec(pos + 1, 0, p + 1);
      }else {
        curstr[pos] = i;
        rec(pos + 1, cur + i, p);
      }
    }
  }
}

struct PMA{
  int next[11]; //????0???
  bool matched;
  PMA() {memset(next, -1, sizeof(next)); matched = false; }
};
const int PMA_SIZE = 33900;
PMA pma[PMA_SIZE];
int dp[41][PMA_SIZE][2];
int curpma = 1; // root
int main() {
  cin >> N >> phase[0] >> phase[1] >> phase[2];
  rec(0, 0, 0);
  int root = 0;
  int cur = 0;
  pma[root].next[0] = root;
  for(int i = 0; i < cscnt; i++) {
    cur = root;
    for(int j = 0; cs[i][j]; j++) {
      if(pma[cur].next[cs[i][j]] == -1) {
        pma[cur].next[cs[i][j]] = curpma++;
      }
      cur = pma[cur].next[cs[i][j]];
    }
    pma[cur].matched = true;
  }
  queue<int> que;
  for(int j = 1; j < 11; j++) {
    if(pma[root].next[j] != -1) {
      que.push(pma[root].next[j]);
      pma[pma[root].next[j]].next[0] = 0;
    }else {
      pma[root].next[j] = root;
    }
  }
  while(!que.empty()) {
    int now = que.front(); que.pop();
    for(int j = 1; j < 11; j++) {
      if(pma[now].next[j] != -1) {
        int next = pma[now].next[0];
        while(pma[next].next[j] == -1) next = pma[next].next[0];
        pma[pma[now].next[j]].next[0] = pma[next].next[j];
        pma[pma[now].next[j]].matched |= pma[pma[next].next[j]].matched;

        que.push(pma[now].next[j]);
      }
    }
  }
  dp[0][0][0] = 1;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < curpma; j++) {
      for(int k = 1; k <= 10; k++) {
        int cur = j;
        while(pma[cur].next[k] == -1) {
          cur = pma[cur].next[0];
        }
        cur = pma[cur].next[k];
        if(!pma[cur].matched) {
          dp[i + 1][cur][0] += dp[i][j][0];
          if(dp[i + 1][cur][0] >= MOD) dp[i + 1][cur][0] -= MOD;
          dp[i + 1][cur][1] += dp[i][j][1];
          if(dp[i + 1][cur][1] >= MOD) dp[i + 1][cur][1] -= MOD;
        }else {
          dp[i + 1][cur][1] += dp[i][j][0];
          if(dp[i + 1][cur][1] >= MOD) dp[i + 1][cur][1] -= MOD;
          dp[i + 1][cur][1] += dp[i][j][1];
          if(dp[i + 1][cur][1] >= MOD) dp[i + 1][cur][1] -= MOD;
        }
      }
    }
  }
  int ans = 0;
  for(int j = 0; j < curpma; j++) {
    ans += dp[N][j][1];
    if(ans >= MOD) ans -= MOD;
  }
  cout << ans << endl;
} ./Main.cpp:61:33: warning: using the result of an assignment as a condition without parentheses [-Wparentheses]
            if(sum[next.size()] = sum[k] >= phase[1]) {
               ~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~
./Main.cpp:61:33: note: place parentheses around the assignment to silence this warning
            if(sum[next.size()] = sum[k] >= phase[1]) {
                                ^
               (                                    )
./Main.cpp:61:33: note: use '==' to turn this assignment into an equality comparison
            if(sum[next.size()] = sum[k] >= phase[1]) {
                                ^
                                ==
1 warning generated.