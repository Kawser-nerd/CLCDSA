#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int tc; scanf("%d", &tc);
  for(int tci = 0; tci < tc; tci++) {
    int n,s,p; scanf("%d%d%d", &n, &s, &p);
    int base_count = 0;
    int additional_count = 0;
    for(int i = 0; i < n; i++) {
      int t; scanf("%d", &t);
      if((t+2)/3 >= p) { base_count++; continue; }
      if(t>=29 || t<=1) continue;
      if((t+4)/3 >= p) additional_count++;
    }
    printf("Case #%d: %d\n", tci+1, base_count+min(additional_count,s));
  }
  return 0;
}

