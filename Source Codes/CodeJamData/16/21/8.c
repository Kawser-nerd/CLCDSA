#include <stdio.h>

int count(char *word, char c) {
  int num = 0;

  while (*word) {
    if (*word == c) {
      num++;
    }
    
    word++;
  }
  
  return num;
}

int main() {
  int T;
  int Q;
  
  scanf(" %d", &T);
  
  for (Q = 1; Q <= T; Q++) {
    char word[3000];
    
    scanf(" %[^\n]", word);
    
    int n[10];
    
    n[0] = count(word, 'Z');
    n[2] = count(word, 'W');
    n[8] = count(word, 'G');
    n[4] = count(word, 'U');
    n[1] = count(word, 'O') - n[0] - n[2] - n[4];
    n[3] = count(word, 'H') - n[8];
    n[5] = count(word, 'F') - n[4];
    n[7] = count(word, 'V') - n[5];
    n[6] = count(word, 'S') - n[7];
    n[9] = count(word, 'I') - n[5] - n[6] - n[8];
    
    int i;
    
    printf("Case #%d: ", Q);
    
    for (i = 0; i < 10; i++) {
      while (n[i]) {
        putchar('0' + i);
        n[i]--;
      }
    }
    
    putchar('\n');
  }
}