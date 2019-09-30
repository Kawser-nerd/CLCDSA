#include <stdio.h>

int main(void){
  
  int N;
  scanf("%d", &N );
  
  int i;
  long long sum = 0;
  long long wa = 0;
  int A[N];
  int sa[N];
  int ans;
  int shou;
  long long min = 1123456789;
  
  for( i = 0; i < N; i++ ){
    scanf("%d", A+i);
    sum += A[i];
    wa += i+1;
  }
  
  if( sum % wa ) ans = 0;
  else{
    shou = sum/wa;
    for( i = 0; i < N; i++ ){
    sa[i] = A[(i+1)%N] - A[i]-shou;
    }
    
    for( i = 0; i < N-1; i++ ){    
      if( sa[i] <= 0 && !(sa[i] % N))
      ans = 1;
      else{
        ans = 0;
        break;
      }
    }
  }  
  
  
  if( ans ) puts("YES");
  else{     puts("NO");}
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N );
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", A+i);
     ^