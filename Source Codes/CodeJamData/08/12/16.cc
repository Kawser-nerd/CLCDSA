#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> PII;
typedef vector<PII> VP;

bool check(int malted[], VP &cust) {
  for (VP::iterator i = cust.begin(); i != cust.end(); ++i)
    if (malted[i->first] == i->second)
      return true;
  return false;
  }

bool fix(int malted[], VP &cust) {
  VP::iterator i = cust.begin();
  while ((i != cust.end()) && !i->second) ++i;
  if (i == cust.end()) return false;
  malted[i->first] = 1;
  return true;
  }

bool solve(int malted[], VP custs[], int M) {
  for (int i = 0; i < M; ++i)
    if (!check(malted, custs[i])) {
      if (!fix(malted, custs[i]))
        return false;
      else i = -1;
      }
  return true;
  }

int main() {
  int C; scanf("%d", &C);
  for (int c = 1; c <= C; ++c) {
    int N, M; scanf("%d %d", &N, &M);
    VP custs[2000];
    for (int i = 0; i < M; ++i) {
      int T; scanf("%d", &T);
      for (int j = 0; j < T; ++j) {
        int X, Y; scanf("%d %d", &X, &Y);
        custs[i].push_back(PII(X-1, Y));
        }
      }
    printf("Case #%d:", c);
    int malted[2000] = {0};
    if (solve(malted, custs, M)) {
      for (int i = 0; i < N; ++i)
        printf(" %d", malted[i]);
      printf("\n");
      }
    else printf(" IMPOSSIBLE\n");
    }
  }