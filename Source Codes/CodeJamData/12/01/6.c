#include <stdio.h>

//                           abcdefghijklmnopqrstuvwxyz
const char decode_key[26] = "yhesocvxduiglbkrztnwjpfmaq";

int main(void)
{
  int N;
  scanf("%d", &N);
  int c;
  while((c = getchar()) != '\n' && c != EOF);

  int casenum = 1;
  printf("Case #1: ");
  while((c = getchar()) != EOF)
  {
    if(c == '\n')
    {
      if(casenum++ < N)
        printf("\nCase #%d: ", casenum);
      else
        break;
    }
    else
    {
      if(c >= 'a' && c <= 'z')
        putchar(decode_key[c - 'a']);
      else if(c >= 'A' && c <= 'z')
        putchar(decode_key[c - 'A'] + 'A' - 'a');
      else
        putchar(c);
    }
  }

  putchar('\n');
  
  return 0;
}
