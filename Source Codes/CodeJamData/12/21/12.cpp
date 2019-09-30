#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

int s[200];

int main() {
  int t;
  scanf("%d", &t);
  for(int z = 1; z <= t; z++) {
    int n;
    scanf("%d", &n);

    long double sum = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d", &s[i]);
      sum += s[i];
    }

    printf("Case #%d:", z);
    for(int i = 0; i < n; i++) {
      long double lo = 0, hi = 1.1;

      for(int z = 0; z < 60; z++) {
	long double mid = (lo+hi)/2;
	long double myscore = s[i] + sum * mid;
	long double test = 0;

	for(int j = 0; j < n; j++) {
	  if(i == j) continue;
	  test += max((long double)0, (myscore - s[j])/sum);
	  
	}

	if(test + mid <= 1)
	  lo = mid;
	else
	  hi = mid;
      }

      assert(hi <= 1 + 1e-9);
      printf(" %.6Lf", hi*100);
    }
    printf("\n");
  }
}
