#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int i, j;
  int n;
  long long int na;
  int data[100001];
  int dif[100001];
  //  long int times[100001];
  long long int sum = 0;
  int times;
  int tme[100001];
  long long int one;
  int sum2 = 0;
  int flag = 0;

  scanf("%d", &n);
  na = (long long int)n;

  for (i = 0; i < n; i++) {
    scanf("%d", & data[i]);
    sum += data[i];
  }

  one = na * (na + 1) / 2;
  if (sum % one != 0) {
    flag = 1;
  } else {
    times = sum / one;
    for (i = 0; i < n-1; i++) {
      dif[i] = data[i+1] - data[i];
    }
    dif[n-1] = data[0] - data[n - 1];

    for (i = 0; i < n; i++) {
      if ((times - dif[i]) % n != 0) {
        flag = 1;
        break;
      } else {
        tme[i] = (times - dif[i]) / n;
        if(tme[i]<0){
          flag = 1;
          break;
        }
      }
    }
    if (flag == 0) {
      for (i = 0; i < n; i++) {
        sum2 += tme[i];
      }
    }
   }
  if (flag == 0) {
    printf("YES");
/*
    if (sum2 == times) {
      printf("YES");

    } else {
      printf("NO");
    }
*/
  } else {
    printf("NO");
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", & data[i]);
     ^