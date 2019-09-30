#include<stdio.h>
#include<stdlib.h>

#define MAX(A, B) (((A) > (B)) ? (A) : (B))
#define MIN(A, B) (((A) < (B)) ? (A) : (B))
#define ABS(A) (MAX(A, 0-A))

typedef unsigned long long llu;

llu dtd(int* a) {
  llu b=0;
  llu d=1;
  for (int i=0; i<19; i++) {
    b += *(a + i) * d;
    d *= 10;
  }
  return b;
}

llu modify(int* a) {
  llu before = dtd(a);
  
  int d=0;
  for (int i=0; i<19; i++) {
    *(a + i) += d;
    d = 0;
    if (*(a + i) == 4) {
      *(a + i) += 1;
      for (int j=0; j<i; j++) {
        *(a + j) = 0;
      }
    }
    else if (*(a + i) == 9) {
      *(a + i) = 0;
      d = 1;
      for (int j=0; j<i; j++) {
        *(a + j) = 0;
      }
    }
    else if (*(a + i) == 10) {
      *(a + i) = 0;
      d = 1;
    }
  }
  return dtd(a) - before;
}


llu dto(int* a) {
  llu b=0;
  llu d=1;
  for (int i=0; i<19; i++) {
    if (*(a + i) > 4) {*(a + i) -= 1;}
    b += *(a + i) * d;
    d *= 8;
  }
  return b;
}

int main() {
  llu temp;
  int* a = malloc(19 * sizeof(int));
  int* b = malloc(19 * sizeof(int));
  
  scanf("%llu", &temp);
  for (int i=0; i<19; i++) {
    *(a + i) = temp % 10;
    temp /= 10;
  }
  scanf("%llu", &temp);
  for (int i=0; i<19; i++) {
    *(b + i) = temp % 10;
    temp /= 10;
  }
  
  llu am = modify(a);
  llu bm = modify(b);
  if (bm) {bm -= 1;}
  
  llu c = dtd(b) - dtd(a);
  llu d = dto(b) - dto(a);
  
  printf("%llu\n", am - bm + c - d);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:65:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%llu", &temp);
   ^
./Main.c:70:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%llu", &temp);
   ^