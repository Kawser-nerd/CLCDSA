
#include <stdio.h>

int main() {
  int T = 0;
  __int64 N;
  int k, cz;
  __int64 i, j;
  int Pd, Pg;
  __int64 D, G;
  int yes;

  scanf("%d", &T);
  for(cz=1;cz<=T;cz++) {
    scanf("%I64d %d %d", &N, &Pd, &Pg);

// x/D = Pd, y/G = Pg

    yes = 0;
//    if(Pg == 100 && Pd < 100) goto found;

  // D=1..N, G=D..inf
  // can find D candidates easily

  // if found D, guess various G's
  // Pg = (D*Pd + won)/(G)
  // Pg*G/100 - D*Pd/100 = won now (must be <= G-D)

    for(D=1;D<=N&&D<=1000;D++) {
      i = (__int64)D*Pd;  // i = games won out of D
      if(i%100) continue; // j = games won out of G
      i /= 100;

      for(G=D;G<=100000;G++) {
        j = (__int64)G*Pg;   // played G games, Pg % won, j won
        if(j%100) continue;
        j /= 100;
//        if(G-j/100 < D-i/100) continue;
        if(i > j) continue;
        if(D-i > G-j) continue;

//        printf("%d %d\n", D, G);
        yes = 1;
        goto found;
      }
    }

found:
    printf("Case #%d: %s\n", cz, yes?"Possible":"Broken" );

  }

  return 0;
}
