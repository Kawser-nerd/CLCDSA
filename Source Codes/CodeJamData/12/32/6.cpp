#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int T, N, A;
double a, t[2000], x[2000], D;

int main() {
  scanf("%d", &T);
  for (int ttt=1; ttt<=T; ttt++) {
    scanf("%lf %d %d", &D, &N, &A);
    for (int i=0; i<N; i++) {
      scanf("%lf %lf", t+i, x+i);
    }
    printf("Case #%d:\n", ttt);
    for (int aaa=0; aaa<A; aaa++) {
      scanf("%lf", &a);
      double tS = 0;
      for (int i = 1; i<N; i++) {
	double cX = x[i];
	double cT = t[i];
	
	if (cX >= D) {
	  double slope = (x[i] - x[i-1]) / (t[i] - t[i-1]);
	  // D - x[i-1] = slope * (t[i] - t[i-1]);
	  cT = (D - x[i-1]) / slope + t[i-1];
	  cX = D;
	}
	
	if (cT >= tS)
	  tS = max(tS, cT - sqrt(2*cX/a));
	if (cX >= D) break;
      }
      printf("%.7lf\n", sqrt(2*D/a) + tS);
    }
  }
}