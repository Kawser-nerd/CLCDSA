#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef long long int llint;

int bisect(llint* a, int size, llint value)
{
  int left,right,mid;
  
  left = 0;
  right = size -1;
    while(left <= right) {
        mid = (left + right) / 2; /* calc of middle key */
        if (a[mid] == value) {
            return mid;
        } else if (a[mid] < value) {
	  if (a[mid+1] > value) {
	    return mid+1;
	  } else {
            left = mid + 1; /* adjustment of left(start) key */
	  }
        } else {
	  if (a[mid-1] < value) {
	    return mid;
	  } else {
            right = mid - 1; /* adjustment of right(end) key */
	  }
	}
    }
    return -1;
}

llint llint_min(int len, ...) {
    int i;
    llint _min, num;
    va_list ap;
    va_start(ap, len);

    _min = va_arg(ap, llint);
    for (i = 1; i < len; i++) {
      num = va_arg(ap, llint);
      if (num < _min)
        _min = num;
    }
    va_end(ap);
    return _min;
}

llint mmax(llint a, llint b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int main(void)
{
  int A, B, Q;
  llint inf = 1000000000000;
  llint *s, *t, x, ans;
  int i, p, q;

  scanf("%d%d%d",&A,&B,&Q);
  s = malloc(sizeof(llint)*(A+2));
  t = malloc(sizeof(llint)*(B+2));
  s[0] = t[0] = -inf;
  s[A+1] = t[B+1] = inf;
  for(i=1;i<=A;i++) {
    scanf("%lld", &(s[i]));
  }
  for(i=1;i<=B;i++) {
    scanf("%lld", &(t[i]));
  }
  for(i=1;i<=Q;i++) {
    scanf("%lld", &x);
    p = bisect(s,A+2,x);
    q = bisect(t,B+2,x);
    ans = llint_min(6,
		  mmax(s[p]-x,t[q]-x),
		  mmax(x-s[p-1],x-t[q-1]),
		  (s[p]-x)*2 + (x-t[q-1]),
		  (s[p]-x) + (x-t[q-1])*2,
		  (t[q]-x)*2 + (x-s[p-1]),
		  (t[q]-x) + (x-s[p-1])*2);
    printf("%lld\n",ans);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:65:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&A,&B,&Q);
   ^
./Main.c:71:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &(s[i]));
     ^
./Main.c:74:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &(t[i]));
     ^
./Main.c:77:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &x);
     ^