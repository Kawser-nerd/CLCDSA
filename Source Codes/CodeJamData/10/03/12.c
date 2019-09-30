#include <stdio.h>
#include <string.h>

int g[100000];

int many[100000];
int next[100000];

int used[100000];
int cool[100000];

long long solve(int R, int k, int N)
{ 	
  int sum = 0;
  int upto = 0;
  long long answer = 0;
  int n;
  int w;
  int i;
  long long cycle;

  memset(many, 0, sizeof(many));
  memset(next, 0, sizeof(next));

  for (i = 0; i < N; ++i) {
    while (sum + g[upto % N] <= k) {
      sum += g[upto % N];
      upto++;
      if ((upto % N) == i) break;
    }
    many[i] = sum;
    next[i] = upto % N;
    //    printf("%d %d ; %d %d\n", i, g[i], many[i], next[i]);
    sum -= g[i];
  }

  for (i = 0; i < N; ++i) {
    used[i] = -1;
  }

  for (n = w = 0; R; ++n) {
    cool[n] = many[w];
    //    printf("cool %d\n", cool[n]);
    answer += many[w];
    --R;
    used[w] = n;
    w = next[w];
    if (used[w] != -1) {
      break;
    }
  }

  cycle = 0;
  for (i = used[w]; i <= n; ++i) {
    cycle += cool[i];
  }
  //  printf("%d left, cycle %lld * %d\n", R, cycle, (n - used[w] + 1));
  answer += cycle * (R / (n - used[w] + 1));
  R %= n - used[w] + 1;

  for (; R; --R) {
    answer += many[w];
    w = next[w];
  }

  return answer;
}

int main()
{
  int t, T, R, k, N, i;

  scanf("%d", &T);
  for (t = 0; t < T; ++t) {
    scanf("%d %d %d", &R, &k, &N);
    for (i = 0; i < N; ++i) {	
      scanf("%d", &g[i]);
    }
    printf("Case #%d: %lld\n", t + 1, solve(R, k, N));
  }

  return 0;
}
