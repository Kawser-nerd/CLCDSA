#include <stdio.h>
#include <stdbool.h>

#define sml(ch) (('a' <= ch && ch <= 'z') ? true : false)
#define TR(flg) ((flg == true) ? 1 : 0)

int main(void) 
{
  char str[11];
  scanf("%s", str);
  int i, len, c_pos = -1;
  bool flg1 = false, flg2 = false, flg3 = true;
  for(len = 0; str[len] != '\0'; ++len);
  
  if( str[0] == 'A') { flg1 = true; }
  for(i = 2; i < len-1; ++i) {
    if( str[i] == 'C') {
      if(flg2) { flg2 = false; break; }
      else { flg2 = true; c_pos = i; }
    }
  }
  
  for(i = 1; i < len; ++i) {
    if( (i != c_pos) && (!sml(str[i])) ) { flg3 = false; break; }
  }
  
  
  //printf("c_pos = %d\n", c_pos);
  //printf("len = %d\n", len);
  //printf("1: %d 2: %d 3: %d\n", TR(flg1), TR(flg2), TR(flg3));
  if( flg1 && flg2 && flg3) { printf("AC\n"); } 
  else { printf("WA\n"); }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", str);
   ^