#include <stdio.h>

int main(void)
{
  char S[100000];
  
  int i;
  
  for( i = 0; i < 100001; i++ ){
    S[i] = '\0';
  }
  
  scanf("%s", &S);
  
  int cnt[26];
  for( i = 0; i < 26; i++ ){
    cnt[i] = 0;
  }
  
  char j;
  int k;
  
  int num = 0;
  int sum;
  
  for( i = 0; i < 100001; i++ ){
    if( S[i] == '\0' ){
      sum = i;
      i = 100001;
    }
    
    k = 0;
    
    for( j = 'a'; j <= 'z'; j += ('b'-'a') ){
      if( S[i] == j ){
        cnt[k]++;
        j = 'z';
      }
      
      k++;
    }
    
  }
  
  for( i = 0; i < 26; i++ ){
    if( cnt[i] % 2 ) num++;
  }
    
  int a;
  
  if( num > 1 ){
    a = (sum - num) / num;
    if( a % 2 ) printf("%d\n", a);
    else{       printf("%d\n", a+1); }   
      
  }
  else{
    printf("%d\n", sum);
  }
  
 
  
  
  
   
  return 0;
 
} ./Main.c: In function ‘main’:
./Main.c:13:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100000]’ [-Wformat=]
   scanf("%s", &S);
         ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", &S);
   ^
./Main.c:10:10: warning: iteration 100000u invokes undefined behavior [-Waggressive-loop-optimizations]
     S[i] = '\0';
          ^
./Main.c:9:3: note: containing loop
   for( i = 0; i < 100001; i++ ){
   ^