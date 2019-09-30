#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int cases;
  scanf("%d", &cases);
  int barbers, N;
  int *barber_speed;
  int test_case, i;
  int customer, my_barber;
  int skippable, skip_time;
  int *time_remaining;
  int time_step, min_time_remaining;
  for (test_case = 1; test_case <= cases; ++test_case) {
    //printf("Case %d\n", test_case);
    scanf("%d %d", &barbers, &N);
    barber_speed = (int *)malloc(sizeof(int) * barbers);
    time_remaining = (int *)malloc(sizeof(int) * barbers);
    skippable = 0, skip_time = 1;
    for (i = 0; i < barbers; ++i) {
      scanf("%d", barber_speed + i);
      time_remaining[i] = 0;
      skip_time *= barber_speed[i];
    }
    for (i = 0; i < barbers; ++i)
      skippable += skip_time / barber_speed[i];
    N %= skippable;
    if (N == 0)
      N += skippable;

    //printf("Barbers ready. Starting Haircuts\n");

    customer = 1;
    my_barber = -1;
    time_step = 1;
    while (1) {
      // for each barber
      min_time_remaining = INT_MAX;
      for (i = 0; i < barbers; ++i) {
        time_remaining[i] -= time_step;
        //printf("barber %d time remaining %d\n", i, time_remaining[i]);
        // if they are finished, assign a new customer
        if (time_remaining[i] <= 0) {
          if (customer == N) {
            my_barber = i;
            break;
          }
          //printf("assigning customer %d to barber %d\n", customer, i);
          time_remaining[i] = barber_speed[i];
          ++customer;
        }
        if (my_barber >= 0)
          break;
        min_time_remaining = min_time_remaining < time_remaining[i] ? min_time_remaining : time_remaining[i];
      }
      if (my_barber >= 0)
        break;
      time_step = min_time_remaining;
    }

    printf("Case #%d: %d\n", test_case, my_barber + 1);

    free(time_remaining);
    free(barber_speed);
  }
}
