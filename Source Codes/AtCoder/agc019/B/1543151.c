#include<stdio.h>
#include<string.h>

int main() {
  char a[200010];
  scanf("%s", a);
  int ptr;
  int i;
  long long length = strlen(a);
  long long dame = 0;
  long long num_words[26] = {};
  for (i = 0; i < length; i++) {
    if (a[i] == 'a') {
      num_words[0] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'b') {
      num_words[1] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'c') {
      num_words[2] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'd') {
      num_words[3] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'e') {
      num_words[4] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'f') {
      num_words[5] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'g') {
      num_words[6] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'h') {
      num_words[7] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'i') {
      num_words[8] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'j') {
      num_words[9] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'k') {
      num_words[10] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'l') {
      num_words[11] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'm') {
      num_words[12] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'n') {
      num_words[13] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'o') {
      num_words[14] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'p') {
      num_words[15] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'q') {
      num_words[16] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'r') {
      num_words[17] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 's') {
      num_words[18] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 't') {
      num_words[19] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'u') {
      num_words[20] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'v') {
      num_words[21] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'w') {
      num_words[22] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'x') {
      num_words[23] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'y') {
      num_words[24] += 1;
    }
  }
  for (i = 0; i < length; i++) {
    if (a[i] == 'z') {
      num_words[25] += 1;
    }
  }
  for (i = 0; i < 26; i++) {
    dame += (num_words[i]*(num_words[i]-1))/2;
  }
  long long ans = length*(length-1)/2 + 1 - dame;
  printf("%lld\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", a);
   ^