
#include <stdio.h>

char words[100000][200];
char guess[1000][500];
  int M, N;


int consistent(char* word, char* curword, int len, int g, int p) {
  int i,j;
  for(i=0;i<len;i++) {
    for(j=0;j<p;j++) {
      if(!curword[i] && word[i] == guess[g][j]) return 0;
    }
    if(!curword[i]) continue;
    if(curword[i] != word[i]) return 0;
  }
  return 1;
}

int sim(int word, int list) {
  int len;
  int p;
  int score = 0;
  int counts[256];
  char curword[20];
  char avail[10000];
  int i,j;

  memset(curword, 0, sizeof(curword));
  memset(avail, 1, sizeof(avail));

  len = strlen(words[word]);

    for(i=0;i<N;i++) {
      if(strlen(words[i]) != len) avail[i] = 0;
    }

  for(p=0;p<strlen(guess[list]);p++) {
    memset(counts, 0, sizeof(counts));
    for(i=0;i<N;i++) { if(!avail[i]) continue;
      if(consistent(words[i], curword, len, list, p)) {
        for(j=0;j<len;j++) counts[words[i][j]]++;
      } else avail[i] = 0;
    }

    if(counts[guess[list][p]]) {
      if(strchr(words[word], guess[list][p])) {
        for(i=0;i<len;i++) if(words[word][i] == guess[list][p]) curword[i] = guess[list][p];
      } else score++;
    } else continue;
  }

  return score;
}


int main() {
  int T = 0;
  int i, j, cz, r;
  int maxr, whichr;

  scanf("%d", &T);
  for(cz=1;cz<=T;cz++) {
    scanf("%d %d", &N, &M);
    for(i=0;i<N;i++) scanf("%s", words[i]);
    for(i=0;i<M;i++) scanf("%s", guess[i]);

      printf("Case #%d:", cz);
    for(j=0;j<M;j++) {
      maxr = -1;
//printf("---%s---\n", guess[j]);
      for(i=0;i<N;i++) {
        r = sim(i, j);
//printf("%s : %d\n", words[i], r);
        if(r > maxr) {
          maxr = r;
          whichr = i;
        }
      }
      printf(" %s", words[whichr]);
    }
    printf("\n");
  }



  return 0;
}
