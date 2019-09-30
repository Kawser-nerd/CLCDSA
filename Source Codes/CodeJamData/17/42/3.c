#include <stdio.h>

int main() {
  int T;
  int Q;

  scanf(" %d", &T);

  for (Q = 1; Q <= T; Q++) {
    int N;
    int C;
    int M;

    scanf(" %d", &N);
    scanf(" %d", &C);
    scanf(" %d", &M);

    int i;

    int ones = 0;
    int twos = 0;

    int one[1005];
    int two[1005];

    for (i = 0; i < M; i++) {
      int position;
      int customer;

      scanf(" %d", &position);
      scanf(" %d", &customer);

      if (customer == 1) {
	one[ones++] = position;
      } else {
	two[twos++] = position;
      }
    }

    int most_pos = 0;
    int most_times = 0;

    for (i = 1; i <= N; i++) {
      int times = 0;
      int j;

      for (j = 0; j < ones; j++) {
	if (one[j] == i) {
	  times++;
	}
      }

      for (j = 0; j < twos; j++) {
	if (two[j] == i) {
	  times++;
	}
      }

      if (times > most_times) {
	most_times = times;
	most_pos = i;
      }
    }

    int rides;

    if (ones > twos) {
      rides = ones;
    } else {
      rides = twos;
    }

    int promotions = 0;

    if (most_times > rides) {
      if (most_pos == 1) {
	// only pushes out the ride number if we can't promote
	rides = most_times;
      } else {
	promotions = most_times - rides;
      }
    }

    printf("Case #%d: %d %d\n", Q, rides, promotions);
  }
}
