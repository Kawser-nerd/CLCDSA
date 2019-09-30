#include <cstdio>
#include <cstdlib>
#define AMAX 90001
int main() {
  int h, w, d;
  scanf("%d %d %d", &h, &w, &d);
  int x[AMAX];
  int y[AMAX];
  for(int i=1; i<=h; i++) {
    for(int j=1; j<=w; j++) {
      int tmp;
      scanf("%d", &tmp);
      x[tmp] = i;
      y[tmp] = j;
    }
  }
  bool b[AMAX];
  for(int i=0; i<AMAX; i++) {
    b[i] = false;
  }
  int acc[AMAX];
  for(int i=0; i<AMAX; i++) {
    acc[i] = 0;
  }
  for(int i=1; i<=h*w; i++) {
    if(b[i]) continue;
    b[i] = true;
    int c = i;
    int next = i+d;
    while(next<=h*w) {
      b[next] = true;
      int dis = std::abs(x[c]-x[next])+std::abs(y[c]-y[next]);
      //      printf("cost of %d -> %d = %d\n", c, next , dis);
      acc[next] = dis+acc[c];
      next += d;
      c += d;
    }
  }
  // for(int i=1; i<=h*w; i++) {
  //   printf("A(i=%d, j=%d)=%d\n", x[i], y[i], i);
  // }
  // printf("@@@@@@@@@@\n");
  // for(int i=0; i<=h*w; i++) {
  //   printf("acc[%d]=%d\n", i, acc[i]);
  // }
  // printf("@@@@@@@@@\n");
  int q;
  scanf("%d", &q);
  for(int _i=0; _i<q; _i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    if(acc[l]==0) {
      printf("%d\n", acc[r]);
    } else {
      printf("%d\n", acc[r]-acc[l]);
    }
  }
  return 0;
}