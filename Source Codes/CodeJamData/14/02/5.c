#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

double cookies(void) {
   double cost, f, goal;
   double time = 0;
   scanf("%lf%lf%lf", &cost, &f, &goal);
   double cookie_rate = 2.0;
   double time_to_farm, time_to_goal, time_after_farm;
   while(true) {
      time_to_goal = goal/cookie_rate;
      time_to_farm = cost/cookie_rate;
      if(time_to_goal < time_to_farm) {
         time += time_to_goal;
         break;
      }
      time_after_farm = goal/(cookie_rate+f);
      if(time_after_farm + time_to_farm < time_to_goal) {
         cookie_rate += f;
         time += time_to_farm;
      } else {
         time += time_to_goal;
         break;
      }
   }
   return time;
}

int main(void) {
   int cases;
   scanf("%d", &cases);
   for (int i = 1; i <= cases; i++) {
      double answer = cookies();
      printf("Case #%d: ", i);
      printf("%lf\n", answer);
   }
}
