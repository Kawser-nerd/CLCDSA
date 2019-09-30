#include <stdio.h>
#include <stdint.h>

#define MOD_NUM 1000000007
enum {A = 0, G, C, T};
static uint32_t N;
static uint64_t memo[100][4][4][4];
static uint64_t mvld[100][4][4][4];

int isOK(int *last4) {
  for(int i = 0; i < 4; i++) {
    int chk [4];
    for(int j = 0; j < 4; j++) {
      chk[j] = last4[j];
    }
    if(i >= 1) {
      int tmp;
      tmp = chk[i-1];
      chk[i-1] = chk[i];
      chk[i] = tmp;
    }
    if((chk[0] == A && chk[1] == G && chk[2] == C) ||
       (chk[1] == A && chk[2] == G && chk[3] == C)) { 
      return 0;
    }
  }
  return 1;
}

uint64_t search(uint32_t i, int *last){
  if(mvld[i][last[0]][last[1]][last[2]] == 1) {
    return memo[i][last[0]][last[1]][last[2]];
  }
  if(i == N) return 1;

  uint64_t ret = 0;
  for(int j = 0; j < 4; j++) {
    int new_last [4];
    new_last[0] = last[0];
    new_last[1] = last[1];
    new_last[2] = last[2];
    new_last[3] = j;
    if(isOK(new_last) == 1)
      ret = (ret + search(i+1, &new_last[1])) % MOD_NUM;
  }
  memo[i][last[0]][last[1]][last[2]] = ret;
  mvld[i][last[0]][last[1]][last[2]] = 1;
  return ret;
}

int main(void) {
  scanf("%d", &N);
  int TTT[3] = {T, T, T};
  printf("%ld\n", search(0, TTT));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:52:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^