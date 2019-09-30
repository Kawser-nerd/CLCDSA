#include <stdio.h>

int main(void)
{
  int num_of_codes;
  int num_of_characters;
  int bias;
  scanf("%d%d%d",
    &num_of_codes, &num_of_characters, &bias);

  int character;
  int weights[num_of_characters];

  int i, j;
  int sum;
  int answer = 0;
  for(i = 0; i < num_of_characters; i++)
    {
      scanf("%d", &weights[i]);
    }
  for(i = 0; i < num_of_codes; i++)
    {
      sum = 0;
      for(j = 0; j < num_of_characters; j++)
        {
          scanf("%d", &character);
          sum += weights[j] * character;
        }

      if(sum + bias > 0)
        answer++;
    }
  printf("%d\n", answer);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",
   ^
./Main.c:19:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d", &weights[i]);
       ^
./Main.c:26:11: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
           scanf("%d", &character);
           ^