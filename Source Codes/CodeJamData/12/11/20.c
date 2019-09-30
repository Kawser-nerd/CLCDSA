#include <stdio.h>

int main(int argc, const char *argv[])
{
	int t, i, j;
	int a, b;
	double prob;
	double prob_now;
	double result, tmp_result;
	scanf("%d", &t);
	for (i = 0 ; i < t ; i++) {
	  result = 0;
	  scanf("%d %d", &a, &b);
	  result = b + 2;

	  if (result > a + b + 1) {
		result = a + b + 1;
	  }

	  for (j = 0; j < a; j++) {
		scanf("%lf", &prob);
		if ( j == 0 ) {
		  prob_now = prob;
		} else {
		  prob_now = prob * prob_now;
		}
		tmp_result = prob_now * ( b - j - j + a - 1 ) + (1 - prob_now) * (b - j -j + a  + b  );
		//printf("result %d %f\n", j ,tmp_result);
		if (tmp_result < result) {
		  result = tmp_result;
		}
	  }
	  printf("Case #%d: %.6f\n", i + 1, result);
	}
	return 0;
}
