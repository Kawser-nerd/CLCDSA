#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char T[25][60/5];
  memset(T, 0, 25*60/5);

  int N;
  scanf("%d", &N);

  for(int i = 0; i < N; i++) {
    int S, E;
    scanf("%d%d", &S, &E);
    E = -E;

    int SH, SM;
    int EH, EM;

    SH = S / 100;
    SM = S % 100;
    EH = E / 100;
    EM = E % 100;

    int S0 = SM % 10;
    if(S0 < 5) {
      SM = SM - S0;
    } else {
      SM = SM - (S0 - 5);
    }
    int E0 = EM % 10;
    if(E0 != 0) {
      if(E0 <= 5) {
	EM = EM + (5 - E0);
      } else {
	EM = EM + (10 - E0);
      }
    }
    if(EM == 60) {
      EM = 0;
      EH += 1;
    }

    //printf("DEBUG SH=%d SM=%d EH=%d EM=%d\n", SH, SM, EH, EM);
    if((EH-SH) >= 1){
      for(int j = SM/5; j < 60/5; j++) {
	T[SH][j] = 1;
      }
      if((EH-SH) >= 2) {
	for(int j = SH+1; j < EH; j++) {
	  for(int k = 0; k < 60/5; k++) {
	    T[j][k] = 1;
	  }
	}
      }
      for(int j = 0; j < EM/5; j++) {
	T[EH][j] = 1;
      }
    } else {
      for(int j = SM/5; j < EM/5; j++) {
	T[SH][j] = 1;
      }
    }
    
    if(T[EH][EM/5] == 0)
      T[EH][EM/5] = 2;
  }

  int flag = 0;
  int SH, SM;
  int EH, EM;
  for(int i = 0; i <= 24; i++) {
    for(int j = 0; j < 60/5; j++) {
      //printf("DEBUG %02d%02d = %d\n", i, j*5, T[i][j]);
      if(flag == 0 && T[i][j] == 1) {
	SH = i; SM = j;
	flag = 1;
      } else if(flag == 1 && T[i][j] == 2) {
	EH = i; EM = j;
	printf("%02d%02d-%02d%02d\n", SH, SM*5, EH, EM*5);
	flag = 0;
      }
    }
  }
  if(flag == 1) {
    printf("%02d%02d-2400\n", SH, SM*5);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &S, &E);
     ^