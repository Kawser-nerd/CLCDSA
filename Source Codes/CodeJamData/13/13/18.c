#include <stdio.h>

FILE *fin = NULL;
FILE *fout = NULL;

int R, N, M, K;

long p[6][6][6] = {0};

void clear() {
  int a, b, c;
  for (a = 2; a <= M; a++)
    for (b = a; b <= M; b++)
      for (c = b; c <= M; c++) 
	p[a][b][c] = 0;
}

void oneCase() {
  int i, j, k, now;
  int a, b, c;
  int A, B, C;
  long max = 0;
  for (i = 0; i < K; ++i) {
    fscanf(fin, "%d", &now);
    if(now == 1)
      continue;
    for (a = 2; a <= M; a++)
      for (b = a; b <= M; b++)
	for (c = b; c <= M; c++) {
	  if (a == now || b == now || c == now)
	    p[a][b][c] += 1;
	  if (a*b == now || a*c == now || b*c == now)
	    p[a][b][c] += 2;
	  if (a*b*c == now)
	    p[a][b][c] += 4;
	  if (max < p[a][b][c]) {
	    max = p[a][b][c];
	    A = a;
	    B = b;
	    C = c;
	  }
	}
  }

  fprintf(fout, "%d%d%d\n", A, B, C);
}

void work(int caseNum) {
  fscanf(fin, "%d %d %d %d", &R, &N, &M, &K);
  int i;
  fprintf(fout, "Case #%d:\n", caseNum);

  for(i = 0; i < R; ++i) {
    clear();
    oneCase();
  }
}

int main() {
  int cases, i;
  fin = fopen("c.in", "r");
  fout = fopen("c.out", "w");
  
  fscanf(fin, "%d", &cases);  
  for(i = 1; i <= cases; ++i) 
    work(i);
  close(fin);
  close(fout);
  
  return 0;
}

