#define DEBUG 0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

map<long long, long long> a;

int main() {
  long long tc, cn, K, N, i;
  scanf("%lld", &tc);
  for(cn = 1; cn <= tc; cn++) {
    scanf("%lld%lld", &N, &K);
    a.clear();
    a[N] = 1;
    while(K > 0) {
      map<long long, long long>::reverse_iterator rit = a.rbegin();
      i = rit->first;
      if(DEBUG)
	printf("K = %lld, i = %lld\n", K, i);
      K -= rit->second;
      if(DEBUG)
	printf("i = %lld, a[i] = %lld\n", i, a[i]);
      if(i % 2)
	a[i / 2] += rit->second * 2;
      else
	a[i / 2] += rit->second, a[i / 2 - 1] += rit->second;
      a.erase(i);
    }
    printf("Case #%lld: %lld %lld\n", cn, i / 2, (i - 1) / 2);
    //1-0 0 2-1 0 3-1 1 4-2 1 5-2 2
  }
  return 0;
}
