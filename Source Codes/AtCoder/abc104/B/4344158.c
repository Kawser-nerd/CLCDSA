// Ver19.02
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF 1 << 29
#define LLINF 4545454545454545454
#define MOD 1000000007
#define ll long long
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int upll(const void *a, const void *b) { return *(ll *)a < *(ll *)b ? -1 : *(ll *)a > *(ll *)b ? 1 : 0; }
int downll(const void *a, const void *b) { return *(ll *)a < *(ll *)b ? 1 : *(ll *)a > *(ll *)b ? -1 : 0; }
void sortup(ll *a, int n) { qsort(a, n, sizeof(ll), upll); }
void sortdown(ll *a, int n) { qsort(a, n, sizeof(ll), downll); }

int main()
{
  char s[11];
  int count=0;
  scanf("%s", s);
  if (s[0] == 'A')
  {
    for (int i = 1; i < strlen(s); i++)
    {
      if (s[i] == 'C')
      {
        count++;
        if(i<2 || i>=strlen(s)-1){
          puts("WA");
          return 0;
        }
      }else{
        if(s[i]>='A' && s[i]<='Z'){
          puts("WA");
          return 0;
        } 
      }
    }
    if(count!=1){
          puts("WA");
          return 0;
    }else{
          puts("AC");
          return 0;
    }
  }
  puts("WA");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^