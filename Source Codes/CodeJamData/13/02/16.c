#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  FILE *f; int T, N, M, t, i, j, s; int a[100][100]; int mr[100]; int mc[100];
  if(argc <= 1) { fprintf(stderr, "Usage: %s input\n", argv[0]); exit(1); }
  f = fopen(argv[1], "rt");
  fscanf(f, "%d", &T);
  for(t=1; t<=T; ++t) {
    fscanf(f, "%d %d", &N, &M);
    for(i=0; i<N; ++i) mr[i]=0;
    for(j=0; j<M; ++j) mc[j]=0;
    for(i=0; i<N; ++i) {
      for(j=0; j<M; ++j) {
        fscanf(f, "%d", &(a[i][j]));
        if(a[i][j]>mr[i]) mr[i]=a[i][j];
        if(a[i][j]>mc[j]) mc[j]=a[i][j];
      }
    }
    s=1;
    for(i=0; i<N; ++i) {
      for(j=0; j<M; ++j) {
        if((a[i][j]!=mr[i])&&(a[i][j]!=mc[j])) { s=0; break; }
      }
      if(!s) break;
    }
    printf("Case #%d: %s\n", t, s?"YES":"NO");
  }
  fclose(f);
  return 0;
}

