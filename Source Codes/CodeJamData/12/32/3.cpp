#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <iostream>
#include <cmath>


using namespace std;

typedef long double dbl;
#define eps 1e-9

int main (void) {
	int tests_n;
	scanf ("%d", &tests_n);
	for (int test_id = 1; test_id <= tests_n; test_id++) {
		printf ("Case #%d:\n", test_id);

    dbl D;
    int n, an;
    cin >> D >> n >> an;
    vector <dbl> as(an);
    vector <dbl> ts(n), xs(n);

    for (int i = 0; i < n; i++) {
    	cin >> ts[i] >> xs[i];
    }

    for (int i = 0; i < an; i++) {
      cin >> as[i];
    }


    for (int j = 0; j < an; j++) {
	    dbl A = as[j];

	    dbl prev_t = ts[0], prev_x = xs[0];
	    

	    dbl V = 0, X = 0, T = 0;

      bool flag = true;
	    for (int i = 1; i < n && flag; i++) {
	    	dbl t = ts[i], x = xs[i];
	    	
	    	dbl max_v = (x - prev_x) / (t - prev_t);

	    	if (x >= D - eps) {
	        x = D;
	        t = prev_t + (x  - prev_x) / max_v;
	        flag = false;
	    	}

        //fprintf (stderr, "T = %lf, D = %lf, V = %lf A = %lf\n", (double)T, (double)(x - X), (double)V, (double)A);
	      dbl to_travel = x - X;
	      dbl time_to_travel = (-2 * V + sqrt (4 * V * V + 8 * A * to_travel)) / (2 * A);
	      T += time_to_travel;
	      V += A * time_to_travel;
	      X = x;
	      if (T < t) {
	      	T = t;
	      }
	      prev_x = x;
	      prev_t = t;
      }
      if (n == 1) {
      	T = (-2 * V + sqrt (4 * V * V + 8 * A * D)) / (2 * A);
      }
	    printf ("%.20lf\n", (double)T);
	  }
	}
	return 0;
}