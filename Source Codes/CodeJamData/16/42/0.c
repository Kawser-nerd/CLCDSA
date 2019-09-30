#include <stdio.h>
#include <stdlib.h>

int compar(void *a, void *b) {
  if (**(double **)a < **(double **)b) {
    return -1;
  } else if (**(double **)a > **(double **)b) {
    return 1;
  } else {
    return 0;
  }
}

double getprob(int K, double *kprobs) {
  double grid[210][210]; // number of committee members considered, number of yeas, value = P(yeas | committee)
  int yeas;
  int committee;
  
  grid[0][0] = 1;
  
  for (yeas = 1; yeas < K; yeas++) {
    grid[0][yeas] = 0;
  }
  
  for (committee = 1; committee <= K; committee++) {
    for (yeas = 0; yeas <= committee; yeas++) {
      grid[committee][yeas] = grid[committee - 1][yeas - 1] * kprobs[committee - 1] + grid[committee - 1][yeas] * (1 - kprobs[committee - 1]);
    }
  }
  
  return grid[K][K / 2];
}

int main(int argc, char **argv) {
  int T;
  
  scanf(" %d", &T);
  
  int Q;
  
  double probs[210];
  double *ups[210];
  double kprobs[210];
  
  for (Q = 1; Q <= T; Q++) {
    int N;
    int K;
    
    scanf(" %d", &N);
    scanf(" %d", &K);
    
    int i;
    
    for (i = 0; i < N; i++) {
      scanf(" %lf", &probs[i]);
      ups[i] = &probs[i];
    }
    
    qsort(ups, N, sizeof(double *), compar);
    
    double maxprob = 0;
    
    for (i = 0; i <= K; i++) {
      int j;
    
      for (j = 0; j < i; j++) {
        kprobs[j] = *ups[j];
      }
      
      for (; j < K; j++) {
        kprobs[j] = *ups[N - K + j];
      }
      
      
      double prob = getprob(K, kprobs);
      
      if (prob > maxprob) {
        maxprob = prob;
      }
    }
    
    printf("Case #%d: %.6f\n", Q, maxprob);
  }

}