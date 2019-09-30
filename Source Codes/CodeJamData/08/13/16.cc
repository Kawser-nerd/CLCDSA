#include <cstdio>

using namespace std;

struct mat {
  int a,b,c,d;
  mat(int A, int B, int C, int D) : a(A % 1000), b(B % 1000), c(C % 1000), d(D % 1000) {}
  mat operator*(mat &q) {
    return mat(a*q.a + b*q.c, a*q.b + b*q.d, c*q.a + d*q.c, c*q.b + d*q.d);
    }
  };

mat mPow(mat b, int e) {
  mat r(1,0,0,1);
  while (e) {
    if (e & 1) r = r * b;
    e >>= 1;
    b = b * b;
    }
  return r;
  }

int main() {
  int T; scanf("%d", &T);
  for (int c = 1; c <= T; ++c) {
    int n; scanf("%d", &n);
    mat x = mPow(mat(3,1,5,3), n);
    printf("Case #%d: %03d\n", c, (2*x.a+999)%1000);
    }
  }