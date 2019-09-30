#include <stdio.h>
#include <cmath>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int main(int argc, char *argv[argc])
{
  ull X, Y;

  scanf("%llu%llu", &X, &Y);

  int N = log2((long double)Y / X) + 1;
  printf("%d\n", N);
  
  return 0;
}