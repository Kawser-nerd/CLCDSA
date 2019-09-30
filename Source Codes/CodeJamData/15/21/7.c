#define DEBUG 0

#include "../../stdc++.h"
using namespace std;

#define MAXN 1000000

int dp[MAXN + 1];

int rev(int i) {
  char s[100];
  sprintf(s, "%d", i);
  reverse(s, s + strlen(s));
  long long ret = atoll(s);
  if(ret > INT_MAX) {
    printf("overflow\n");
    exit(1);
  }
  return (int)ret;
}

int main() {
  int cn, tc, N, i, reached = 1;
  queue<pair<int, int> > q;
  q.push(make_pair(1, 1));
  dp[1] = 1;
  while(reached < MAXN) {
    if(DEBUG && reached % 1000 == 0)
      printf("%d\n", reached);
    if(q.empty()) {
      puts("ERROR");
      exit(1);
    }
    i = q.front().first;
    int d = q.front().second;
    q.pop();
    if(!dp[i + 1]) {
      dp[i + 1] = d + 1;
      q.push(make_pair(i + 1, d + 1));
      reached++;
    }
    i = rev(i);
    if(!dp[i]) {
      dp[i] = d + 1;
      q.push(make_pair(i, d + 1));
      reached++;
    }    
  }
  scanf("%d", &tc);
  for(cn = 1; cn <= tc; cn++) {
    scanf("%d", &N);
    printf("Case #%d: %d\n", cn, dp[N]);
  }
  return 0;
}
