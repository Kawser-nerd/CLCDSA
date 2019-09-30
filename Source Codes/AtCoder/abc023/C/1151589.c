#include <stdio.h>

int a[112345];
int b[112345];
int c[112345];
int r[112345];
int RK[112345];
int CK[112345];

int main(void){
  
  int R, C, K;
  int N;
  
  scanf("%d %d %d", &R, &C, &K);
  scanf("%d", &N);
  
  int i;
  /*int a[N];
  int b[N];
  int c[C];
  int r[R];
  int RK[K+1];
  int CK[K+1];
  */
  
  for( i = 0; i < C; i++ ){
    c[i] = 0;
  }
  
  for( i = 0; i < R; i++ ){
    r[i] = 0;
  }
  
  for( i = 0; i <= K; i++ ){
    RK[i] = 0;
    CK[i] = 0;
  }
  
  for( i = 0; i < N; i++ ){
    scanf("%d %d",a+i, b+i);
    r[a[i]-1]++;
    c[b[i]-1]++;
  }
  
  
  for( i = 0; i < C; i++ ){
    if( c[i] <= K ) CK[c[i]]++;
  }
  
  for( i = 0; i < R; i++ ){
    if( r[i] <= K ) RK[r[i]]++;
  }
  
  
  
  long long ans = 0;
  
  for( i = 0; i <= K; i++ ){
    //printf("%d %d\n", CK[i], RK[K-i]);
    ans += CK[i] * RK[K-i]; 
  }
  
  //printf("%d\n", ans);
  
  for( i = 0; i < N; i++ ){
    if( r[a[i]-1] + c[b[i]-1] == K ) ans--;
    if( r[a[i]-1] + c[b[i]-1] == K+1 ) ans++;
  }
    
  
  
  printf("%lld\n", ans );
  
  return 0;
  
} ./Main.c: In function ‘main’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &R, &C, &K);
   ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:41:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",a+i, b+i);
     ^