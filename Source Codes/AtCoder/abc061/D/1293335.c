#include<stdio.h>
#define INF -1000000000000000000
#define ll long long

int main() {
  int n, m, f;
  int i, j;
  ll score[1010] = {};
  scanf("%d %d", &n, &m);
  ll a[2010] = {};
  ll b[2010] = {};
  ll c[2010] = {};
  for (i = 1; i < m+1; i++) {
    scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
  }
  for (i = 2; i < n+1; i++) {
    score[i] = INF;
  }
  for (i = 1; i < n+1; i++) {
    f = 0;
    for (j = 1; j < m+1; j++) {
      int from = a[j];
      int to = b[j];
      /*????????????f=1
        i==n(n steps?)??????????????????f=1*/
      if (score[to] < score[from] + c[j]) {
	score[to] = score[from] + c[j];
	if (i >= n) {
	  if (b[j] == n) {
	    f = 1;
	  }
	} else {
	  f = 1;
	}
      }
    }
    /*??????????(f==0)??????*/
    if (f == 0) {
      break;
    }
    /*????????????????????????inf*/
    if (i == n) {
      printf("inf\n");
      return 0;
    }
  } 
  printf("%lld\n", score[n]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &n, &m);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
     ^