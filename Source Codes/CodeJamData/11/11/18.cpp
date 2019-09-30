#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
  int T; scanf("%d", &T);
  for(int t = 1; t <= T; t++) {
    long long N;
    int PD, PG;
    scanf("%lld%d%d", &N, &PD, &PG);

    bool ok = false;
    if(PG == 0 || PG == 100) {
      ok = PG == PD;
    } else for(int D = 1; !ok && D <= 100 && D <= N; D++) {
      for(int G = 0; !ok && G < 100; G++) {
        ok = (PD * D) % 100 == 0 &&
             (PG * G + (PG - PD) * D) % 100 == 0;
      }
    }

    printf("Case #%d: %s\n", t, ok ? "Possible" : "Broken");
  }
}
