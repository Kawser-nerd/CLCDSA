#include<stdio.h>
#include<string.h>

int main() {
  char s[110], act[110];
  int len;
  int i;
  int distance[30];
  for (i = 0; i < 31; i++) {
    distance[i] = 0;
  }
  scanf("%s", s);
  
  strcpy(act, s);
  char *toka = strtok(act, "a");
  while (toka != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(toka) >= distance[1]) {
      distance[1] = strlen(toka);
    }
    toka = strtok(NULL, "a");
  }
  strcpy(act, s);
  char *tokb = strtok(act, "b");
  while (tokb != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(tokb) >= distance[2]) {
      distance[2] = strlen(tokb);
    }
    tokb = strtok(NULL, "b");
  }
  strcpy(act, s);
  char *tokc = strtok(act, "c");
  while (tokc != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(tokc) >= distance[3]) {
      distance[3] = strlen(tokc);
    }
    tokc = strtok(NULL, "c");
  }
  strcpy(act, s);
  char *tokd = strtok(act, "d");
  while (tokd != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(tokd) >= distance[4]) {
      distance[4] = strlen(tokd);
    }
    tokd = strtok(NULL, "d");
  }
  strcpy(act, s);
  char *toke = strtok(act, "e");
  while (toke != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(toke) >= distance[5]) {
      distance[5] = strlen(toke);
    }
    toke = strtok(NULL, "e");
  }
  strcpy(act, s);
  char *tokf = strtok(act, "f");
  while (tokf != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(tokf) >= distance[6]) {
      distance[6] = strlen(tokf);
    }
    tokf = strtok(NULL, "f");
  }
  strcpy(act, s);
  char *tokg = strtok(act, "g");
  while (tokg != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(tokg) >= distance[7]) {
      distance[7] = strlen(tokg);
    }
    tokg = strtok(NULL, "g");
  }
  strcpy(act, s);
  char *tokh = strtok(act, "h");
  while (tokh != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(tokh) >= distance[8]) {
      distance[8] = strlen(tokh);
    }
    tokh = strtok(NULL, "h");
  }
  strcpy(act, s);
  char *toki = strtok(act, "i");
  while (toki != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(toki) >= distance[9]) {
      distance[9] = strlen(toki);
    }
    toki = strtok(NULL, "i");
  }
  strcpy(act, s);
  char *tokj = strtok(act, "j");
  while (tokj != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(tokj) >= distance[10]) {
      distance[10] = strlen(tokj);
    }
    tokj = strtok(NULL, "j");
  }
  strcpy(act, s);
  char *tokk = strtok(act, "k");
  while (tokk != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(tokk) >= distance[11]) {
      distance[11] = strlen(tokk);
    }
    tokk = strtok(NULL, "k");
  }
  strcpy(act, s);
  char *tokl = strtok(act, "l");
  while (tokl != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(tokl) >= distance[12]) {
      distance[12] = strlen(tokl);
    }
    tokl = strtok(NULL, "l");
  }
  strcpy(act, s);
  char *tokm = strtok(act, "m");
  while (tokm != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(tokm) >= distance[13]) {
      distance[13] = strlen(tokm);
    }
    tokm = strtok(NULL, "m");
  }
  strcpy(act, s);
  char *tokn = strtok(act, "n");
  while (tokn != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(tokn) >= distance[14]) {
      distance[14] = strlen(tokn);
    }
    tokn = strtok(NULL, "n");
  }
  strcpy(act, s);
  char *toko = strtok(act, "o");
  while (toko != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(toko) >= distance[15]) {
      distance[15] = strlen(toko);
    }
    toko = strtok(NULL, "o");
  }
  strcpy(act, s);
  char *tokp = strtok(act, "p");
  while (tokp != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(tokp) >= distance[16]) {
      distance[16] = strlen(tokp);
    }
    tokp = strtok(NULL, "p");
  }
  strcpy(act, s);
  char *tokq = strtok(act, "q");
  while (tokq != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(tokq) >= distance[17]) {
      distance[17] = strlen(tokq);
    }
    tokq = strtok(NULL, "q");
  }
  strcpy(act, s);
  char *tokr = strtok(act, "r");
  while (tokr != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(tokr) >= distance[18]) {
      distance[18] = strlen(tokr);
    }
    tokr = strtok(NULL, "r");
  }
  strcpy(act, s);
  char *toks = strtok(act, "s");
  while (toks != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(toks) >= distance[19]) {
      distance[19] = strlen(toks);
    }
    toks = strtok(NULL, "s");
  }
  strcpy(act, s);
  char *tokt = strtok(act, "t");
  while (tokt != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(tokt) >= distance[20]) {
      distance[20] = strlen(tokt);
    }
    tokt = strtok(NULL, "t");
  }
  strcpy(act, s);
  char *toku = strtok(act, "u");
  while (toku != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(toku) >= distance[21]) {
      distance[21] = strlen(toku);
    }
    toku = strtok(NULL, "u");
  }
  strcpy(act, s);
  char *tokv = strtok(act, "v");
  while (tokv != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(tokv) >= distance[22]) {
      distance[22] = strlen(tokv);
    }
    tokv = strtok(NULL, "v");
  }
  strcpy(act, s);
  char *tokw = strtok(act, "w");
  while (tokw != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(tokw) >= distance[23]) {
      distance[23] = strlen(tokw);
    }
    tokw = strtok(NULL, "w");
  }
  strcpy(act, s);
  char *tokx = strtok(act, "x");
  while (tokx != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(tokx) >= distance[24]) {
      distance[24] = strlen(tokx);
    }
    tokx = strtok(NULL, "x");
  }
  strcpy(act, s);
  char *toky = strtok(act, "y");
  while (toky != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(toky) >= distance[25]) {
      distance[25] = strlen(toky);
    }
    toky = strtok(NULL, "y");
  }
  strcpy(act, s);
  char *tokz = strtok(act, "z");
  while (tokz != NULL) {
    /*printf("%s\n", tok);*/
    if (strlen(tokz) >= distance[26]) {
      distance[26] = strlen(tokz);
    }
    tokz = strtok(NULL, "z");
  }
  int min = 100;
  for (i = 1; i < 27; i++) {
    if (min >= distance[i]) {
      min = distance[i];
    }
  }
  printf("%d\n", min);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^
./Main.c:10:17: warning: iteration 30u invokes undefined behavior [-Waggressive-loop-optimizations]
     distance[i] = 0;
                 ^
./Main.c:9:3: note: containing loop
   for (i = 0; i < 31; i++) {
   ^