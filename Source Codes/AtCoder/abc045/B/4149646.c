#include <stdio.h>

int main(void){
  char sa[101] = { '\0' };
  char sb[101] = { '\0' };
  char sc[101] = { '\0' };
  scanf("%s", sa);
  scanf("%s", sb);
  scanf("%s", sc);
  int na = 0;
  int nb = 0;
  int nc = 0;
  int ma = 0;
  int mb = 0;
  int mc = 0;
  while(sa[ma] != '\0') ma++;
  while(sa[mb] != '\0') mb++;
  while(sa[mc] != '\0') mc++;
    int select = 3;
  char turn = 'a';
  while(select == 3){
    switch(turn){
    case 'a':
      if(na == ma) select = 0;
      turn = sa[na];
      na++;
      break;
    case 'b':
      if(nb == mb) select = 1;
      turn = sb[nb];
      nb++;
      break;
    default:
      if(nc == mc) select = 2;
      turn = sc[nc];
      nc++;
      break;
    }
  }

  if(select == 0) printf("A\n");
  else if(select == 1) printf("B\n");
  else printf("C\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", sa);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", sb);
   ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", sc);
   ^