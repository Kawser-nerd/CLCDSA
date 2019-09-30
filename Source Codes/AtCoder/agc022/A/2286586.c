#include<stdio.h>

int main()
{
  char S[27];
  int i,j;
  int isUsed[27];
  char alphabet_map[27];//\0,a,b,...,z
  char before_a = 'a'-1;//alphabet -> 1-origin
  int end = 0;
  int isFound = 0;
  for(i = 0;i < 27;i++)
  {
    alphabet_map[i] = before_a+i;
    isUsed[i] = 0;
    S[i] = '\0';
  }
  alphabet_map[0] = '\0';
  isUsed[0] = 1;
  scanf("%s",S);
  for(i = 0;i < 27 && S[i] != '\0';i++)
  {
    isUsed[S[i]-before_a] = 1;
  }
  end = i;
  for(i = end;i >= 0;i--)
  {
    for(j = (S[i] == '\0'?1:S[i]-before_a+1);j<27;j++)
    {

      if(isUsed[j] == 0)
      {
        S[i] = j+'a'-1;
        goto SUCCESS;
      }
    }
    if(S[i] != '\0')
    {
      isUsed[S[i]-before_a] = 0;
      S[i] = '\0';
    }
  }
  printf("-1\n");
  return 0;
SUCCESS:
  printf("%s\n",S);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^