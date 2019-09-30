#include<stdio.h>
#include<string.h>

int main()
{
  char s[11], t[11];
  scanf("%s", s);
  scanf("%s", t);
  
  char atcoder[] = {'a', 't', 'c', 'o', 'd', 'e', 'r'};
  
  int l = strlen(s);
  int i, j;
  for(i = 0; i < l; i++)
  {
    if(strncmp(s+i, "@", 1) != 0 & strncmp(t+i, "@", 1) != 0)
    {
      if(strncmp(s+i, t+i, 1) != 0)
        break;
    } else if(strncmp(s+i, "@", 1) == 0 & strncmp(t+i, "@", 1) != 0)
    {
      for(j = 0; j < 7; j++)
      {
        if(strncmp(t+i, atcoder+j, 1) == 0)
          break;
      }
      if(j == 7)
        break;
    } else if(strncmp(s+i, "@", 1) != 0 & strncmp(t+i, "@", 1) == 0)
    {
      for(j = 0; j < 7; j++)
      {
        if(strncmp(s+i, atcoder+j, 1) == 0)
          break;
      }
      if(j == 7)
        break;
    }
  }
  
  if(i < l)
    printf("You will lose\n");
  else
    printf("You can win\n");
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", t);
   ^