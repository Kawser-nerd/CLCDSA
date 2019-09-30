#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

/* PREWRITTEN CODE */

#define ALL(x) x.begin(),x.end()
#define PB push_back


#define FOR(i,p,k) for (int i=p; i<k; i++)
#define REP(i,n) for (int i=0; i<n; i++)
#define SIZE(x) (int)x.size()
/* COMPETITION CODE */

int main () {
  int number_of_tests;
  scanf("%d", &number_of_tests);
  REP (test_number, number_of_tests) {
    printf("Case #%d:", test_number+1);
		int N;
    scanf("%d", &N);
		int A[2000];
		int B[2000];
		REP (i, N) {
			scanf("%d %d", &A[i], &B[i]);
		}
		int res = 0;
		REP (i, N) {
			REP (j, N) if (i != j) if ((A[i] - A[j]) * (B[i] - B[j]) < 0) res += 1;
		}
    printf(" %d\n", res / 2);
  }
  return 0;
}


