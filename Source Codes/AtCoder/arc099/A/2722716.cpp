#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int minPlace;
  int A[n];
  for (int i=0; i<n; i++) {
    scanf("%d", &A[i]);
    if (A[i] == 1) minPlace = i;
  }
  int res = 200000;
  for (int i = 0; i < k; i++) {
    int d = 1;
    if (minPlace-i > 0) {
      d += (minPlace-i) / (k-1);
      if ((minPlace-i) % (k-1) > 0) d++;
    }
    if (n-(minPlace+k-i) > 0) {
      d += (n-(minPlace+k-i)) / (k-1);
      if ((n-(minPlace+k-i)) % (k-1) > 0) d++;
    }
    if (d<res) res = d;
  }

  printf("%d\n", res);



  return 0;
}