#include <stdio.h>

int solve1(int R, int C) {
   return 1;
}

int solve2(int R, int C) {
   if ((R*C % 2) != 0) return 0;
   return 1;
}

int solve3(int R, int C) {
   if ((R*C % 3) != 0) return 0;
   if (R == 1) return 0;
   return 1;
}

int solve4(int R, int C) {
   if ((R*C % 4) != 0) return 0;
   if (R <= 2) return 0;
   return 1;
}

int main(int argc, char* argv[]) {
   int TC, tc;
   scanf("%d", &TC);
   for (tc = 1; tc <= TC; ++tc) {
      int X, R, C, res;
      scanf("%d %d %d", &X, &R, &C);
      if (R > C) {
         int t = R;
         R = C;
         C = t;
      }
      switch (X) {
         case 1: res = solve1(R, C); break;
         case 2: res = solve2(R, C); break;
         case 3: res = solve3(R, C); break;
         case 4: res = solve4(R, C); break;
      }
      printf("Case #%d: %s\n", tc, res ? "GABRIEL" : "RICHARD");
   }
   return 0;
}
