// brute force solution
#include <stdio.h>
#define INF 50000

int numOccupants(int rooms) {
  int tmp = rooms;
  int count = 0;
  while (tmp) {
    if (tmp&1) count++;
    tmp >>= 1;
  }
  return count;
}

int getUnhappy(int rooms, int R, int C) {
  int i, count = 0;
  for (i = 0; i < R*C; i++) {
    // if a room is occupied, count neighbors
    if (rooms & (1 << i)) {
      if (i + C < R*C && (rooms & (1 << (i+C)))) count++;
      if (i % C + 1 < C && (rooms & (1 << (i+1)))) count++;
      //if (i - C >= 0 && (rooms & (1 << (i-C)))) count++;
      //if (i % C > 0 && (rooms & (1 << (i-1)))) count++;
      // only check two directions to avoid double counting
    }
  }
  return count;
}

int main() {
  int T, i, j, R, C, N, minUnhappy, unhappy;
  FILE *fin = fopen("B-noisy.in", "r");
  FILE *fout = fopen("B-noisy.out", "w");
  fscanf(fin, "%d\n", &T);
  for (i = 1; i <= T; i++) {
    minUnhappy = INF;
    fscanf(fin, "%d %d %d\n", &R, &C, &N);
    // treat j as a bit vector representing rooms
    for (j = 0; j < (1<<(R*C)); j++) {
      if (numOccupants(j) == N) {
        unhappy = getUnhappy(j, R, C);
        if (unhappy < minUnhappy) minUnhappy = unhappy;
      }
    }
    fprintf(fout, "Case #%d: %d\n", i, minUnhappy);
  }
  fclose(fin);
  fclose(fout);
  return 0;
}
