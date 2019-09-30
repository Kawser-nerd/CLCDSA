#include<stdio.h>
#include<stdlib.h>

#define MAX(A, B) (((A) > (B)) ? (A) : (B))

int checknum (long* list) {
  int a = *(list) * 100 + *(list + 1) * 10 + *(list + 2);
  if ((a == 132) || (a == 123) || (a == 312)) {
    return 0;
  }
  else {return 1;}
  
  return 0;
}

int checknumb(long* list) {
  
  int f = 0;
  f = checknum(list + 1);
  int a = *(list) * 100 + *(list + 1) * 10 + *(list + 3);
  int b = *(list) * 100 + *(list + 2) * 10 + *(list + 3);
  a -= 132;
  b -= 132;
  f *= a * b;
  return f;
}

int main() {
  long INF = 1000000000 + 7;
  int N;
  scanf("%d", &N);
  
  long** list = malloc(64 * sizeof(long*));
  
  for (int i=0; i<64; i++) {
    
    *(list + i) = malloc(6 * sizeof(long));
    
    *(*(list + i)) = i/16 + 1;
    *(*(list + i) + 1) = i%16/4 + 1;
    *(*(list + i) + 2) = i%4 + 1;
    
    if (checknum(*(list + i))) {
      *(*(list + i) + 4) = 1;
    }
    else {
      *(*(list + i) + 4) = 0;
    }
  }
  
  int digit = 3;
  long* p;
  int q;
  while (digit < N) {
    for (int i=0; i<64; i++) {
      p = *(list + i);
      for (int j=1; j<5; j++) {
        *(p + 3) = j;
      	q = *(p + 1) * 16 + *(p + 2) * 4 + *(p + 3) - 21;
        
        if (checknumb(p)) {
          *(*(list + q) + 5) += *(p + 4);
        }
      }
    }
    for (int i=0; i<64; i++) {
      p = *(list + i);
      *(p + 4) = *(p + 5) % INF;
      *(p + 5) =0;
    }
    digit++;
  }
  
  long ans = 0;
  for (int i=0; i<64; i++) {
    ans += *(*(list + i) + 4);
    ans %= INF;
  }
  ans %= INF;
  printf("%ld", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^