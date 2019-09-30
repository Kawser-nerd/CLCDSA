#include <stdio.h>
typedef long long ll;
using namespace std;

int main(void) {
  ll i, j, k, a, b;
  scanf("%lld%lld", &a, &b);
  if(a <= 8 && b <= 8) printf("Yay!");
  else printf(":(");
  return 0;
}