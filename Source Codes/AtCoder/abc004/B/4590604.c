#include<stdio.h>

int main(void)
{
  char first[4]={'\0'};
  char second[4]={'\0'};
  char third[4]={'\0'};
  char forth[4]={'\0'};
  char dummy;

  scanf("%c %c %c %c",&first[0],&first[1],&first[2],&first[3]);
  scanf("%c",&dummy);
  scanf("%c %c %c %c",&second[0],&second[1],&second[2],&second[3]);
  scanf("%c",&dummy);
  scanf("%c %c %c %c",&third[0],&third[1],&third[2],&third[3]);
   scanf("%c",&dummy);
  scanf("%c %c %c %c",&forth[0],&forth[1],&forth[2],&forth[3]);

  printf("%c %c %c %c\n",forth[3],forth[2],forth[1],forth[0]);
  printf("%c %c %c %c\n",third[3],third[2],third[1],third[0]);
  printf("%c %c %c %c\n",second[3],second[2],second[1],second[0]);
  printf("%c %c %c %c\n",first[3],first[2],first[1],first[0]);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c %c %c %c",&first[0],&first[1],&first[2],&first[3]);
   ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c",&dummy);
   ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c %c %c %c",&second[0],&second[1],&second[2],&second[3]);
   ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c",&dummy);
   ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c %c %c %c",&third[0],&third[1],&third[2],&third[3]);
   ^
./Main.c:16:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    s...