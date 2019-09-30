#include <cstdio>
#include <stdint.h>
#include <algorithm>
using namespace std;


int tens[] = {1,10,100,1000,10000,100000,1000000,10000000};

int main() {
  int tc; scanf("%d", &tc);
  for(int tci = 0; tci < tc; tci++) {
    int a,b; scanf("%d%d", &a, &b);
    int d; for(d=0;tens[d]<=a;d++);
    int cnt = 0;
    for(int x = a; x < b; x++) {
      int vals[10];
      vals[0]=0;
      for(int i = 1; i < d; i++) {
        vals[i] = x/tens[i]+x%tens[i]*tens[d-i];
      }
      sort(vals, vals+d);
      for(int i = 1; i < d; i++) {
        if(x < vals[i] && vals[i-1]<vals[i] && vals[i] <= b) cnt++;
      }
    }
    printf("Case #%d: %d\n", tci+1, cnt);
  }
  return 0;
}

