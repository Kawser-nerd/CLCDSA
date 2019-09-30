#include <stdio.h>

#define TSIZE (24*(60/5)+3)
int main(void) {
  int T[TSIZE];
  for(int i = 0; i < TSIZE; i++) {
    T[i] = 0;
  }

  int N;
  scanf("%d", &N);

  for(int i = 0; i < N; i++) {
    int S, E;
    scanf("%d%d", &S, &E);
    E = -E;

    int SM, EM;
    SM = (S / 100) * 60 + (S % 100);
    int S0 = SM % 5;
    SM = SM - S0;

    EM = (E / 100) * 60 + (E % 100);
    int E0 = EM % 5;
    if(E0 != 0) {
      EM = EM + (5 - E0);
    }

    T[(SM/5)]++;
    T[(EM/5)]--;
  }

  for(int i = 0; i < TSIZE-1; i++) {
    T[i+1] += T[i];
  }

  int SH, SM;
  int EH, EM;
  if(T[0] > 0) {
    SH = 0;
    SM = 0;
  }
  for(int i = 0; i <= (24*(60/5)); i++) {
    if(T[i] == 0 && T[i+1] > 0) {
      SH = (i+1) / 12;
      SM = (i+1) % 12 * 5;
    } else if(T[i] > 0 && T[i+1] == 0) {
      EH = (i+1) / 12;
      EM = (i+1) % 12 * 5;
      printf("%02d%02d-%02d%02d\n", SH, SM, EH, EM);
    }
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &S, &E);
     ^