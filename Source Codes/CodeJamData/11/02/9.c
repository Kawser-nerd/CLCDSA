
#include <stdio.h>


  int C;
  char Cs[1000][16];
  int D;
  char Ds[1000][16];
  int N;
  char Ns[1000];
  int i;
  char Q[1024];
  int q;


int getC(char* Q) {
  int i;
  for(i=0;i<C;i++) {
    if(Q[0] == Cs[i][0] && Q[1] == Cs[i][1]) return i;
    if(Q[0] == Cs[i][1] && Q[1] == Cs[i][0]) return i;
  }
  return -1;
}


int getD(char* Q, int q) {
  int i,j;
  for(i=0;i<D;i++) {
    for(j=0;j<q-1;j++) {
      if(Q[q-1] == Ds[i][0] && Q[j] == Ds[i][1]) return i;
      if(Q[q-1] == Ds[i][1] && Q[j] == Ds[i][0]) return i;
    }
  }
  return -1;
}


int doQ(char* Q, int q) {
  int w;
  if(q < 2) return q;

    // 1: combine

  w = getC(Q+q-2);
  if(w>=0) {
    Q[q-2] = Cs[w][2];
    q--;
    return doQ(Q, q);
  }

    // 2: opposed

  w = getD(Q, q);
  if(w>=0) {
    q = 0;
    return doQ(Q, q);
  }

  return q;
}


int main() {
  int T = 0;
  int cz;

  scanf("%d", &T);
  for(cz=1;cz<=T;cz++) {
    scanf("%d", &C);
    for(i=0;i<C;i++) scanf("%s", &Cs[i]);
    scanf("%d", &D);
    for(i=0;i<D;i++) scanf("%s", &Ds[i]);
    scanf("%d", &N);
    scanf("%s", Ns);

    q = 0;
    for(i=0;i<N;i++) {
      Q[q++] = Ns[i];
      q = doQ(Q, q);
    }

    printf("Case #%d: [", cz);
    for(i=0;i<q;i++) {
      printf("%c%s", Q[i], (i<q-1)?", ":"");
    }
    printf("]\n");
  }

  return 0;
}
