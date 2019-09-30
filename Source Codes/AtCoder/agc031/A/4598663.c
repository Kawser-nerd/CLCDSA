#include <stdio.h>
 
int main(){
  int n;
  long mod = 1000000007;
  scanf("%d\n",&n);
  char a[n];
  int b[26];
  for(int i = 0; i < 26; ++i) b[i] = 0;
  for(int i = 0; i < n; ++i) scanf("%c",&a[i]);
  for(int i = 0; i < n; ++i){
    b[a[i] - 'a']++;
  }
  long answer = 1;
  for(int i = 0; i < 26; ++i){
    answer *= (1 + (long)b[i]);
    answer = answer % mod;
  }
  answer--;
  answer = answer % mod;
  printf("%ld\n",answer);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d\n",&n);
   ^
./Main.c:10:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0; i < n; ++i) scanf("%c",&a[i]);
                              ^