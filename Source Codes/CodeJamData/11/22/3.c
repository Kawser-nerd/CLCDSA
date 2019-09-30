#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double points[1000001];

int main() {

  int T, C;
  double D;

  scanf("%d", &T);

  int i, j, k;

  for(i=1; i<=T; i++) {
    scanf("%d %lf", &C, &D);
    int count = 0;
    for(j=0; j<C; j++) {
      double a;
      int b;
      scanf("%lf %d", &a, &b);
      for(k=0; k<b; k++) {
	points[count++] = a;
      }
    }
    double time_used = 0.0;
    double right_most = points[0];
    for(j=1; j<count; j++) {
      double time_needed = fabs(right_most+D-points[j]);
      if(time_needed<=time_used) {
	right_most +=D;
      }
      else if((right_most+D)<points[j]) {
	right_most = points[j]-time_used;
      }
      else {
	time_used = (time_used+time_needed)/2;
	right_most = points[j]+time_used;
      }
    }

    printf("Case #%d: %.12lf\n", i, time_used);

  }

  return 0;

}
