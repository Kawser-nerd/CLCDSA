#include<stdio.h>

int main(void)
{
  int p = 0, i;
  char s[4];
  
  for(i = 0 ; i < 4 ; i++)
  {
    scanf("%c", &s[i]);
    if(s[i] == '+')
      p += 1;
    else
      p -= 1;
  }
  
  printf("%d", p);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c", &s[i]);
     ^