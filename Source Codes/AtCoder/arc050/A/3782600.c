#include<stdio.h>

void run(void) {
  char C,c;
  scanf(" %c %c", &C, &c);
  if(C+32 == c)
    printf("Yes\n");
  else
    printf("No\n");
}
int main(){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf(" %c %c", &C, &c);
   ^