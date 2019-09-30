#include<stdio.h>

int main () {

  int t, n, i, j, k, l;
  scanf ("%d", &t);

  long long int A, B, C, D, x0, y0, M;
  long long int count;

  int num=0;

  long long int x[100];
  long long int y[100];

  while (t--) {
    num++;
    count=0;
    
    scanf ("%d %llu %llu %llu %llu %llu %llu %llu", &n, &A, &B, &C, &D, &x0, &y0, &M);
    
    x[0]=x0;
    y[0]=y0;
    for (i=1;i<n;i++) {
      x[i]=(x[i-1]*A+B)%M;
      y[i]=(y[i-1]*C+D)%M;
    }

    for (i=0;i<n;i++) {
      for (j=0;j<i;j++) {
        for(k=0;k<j;k++) {
          if (((x[i]+x[j]+x[k])%3==0) && ((y[i]+y[j]+y[k])%3==0))
            count++;
        }
      }
    }

    printf ("Case #%d: %llu\n", num, count);
  }

  return 0;
}

