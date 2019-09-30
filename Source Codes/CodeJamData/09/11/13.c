#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NUM 100000
bool *flags;
int flags_size;

int sqdigits(int number, int base) {
   int ac = 0;
   while (number) {
      int digit = number % base;
      ac += digit * digit;
      number /= base;
   }
   return ac;
}

bool happy(int number, int base) {
   int k = number;
   memset(flags, 0, flags_size);
   do {
      if (k < 0 || k >= MAX_NUM) {
         fprintf(stderr, "*** %d blew up\n", k);
         exit(2);
      }
      if (flags[k]) return false;
      flags[k] = true;
      k = sqdigits(k, base);
   } while (k != 1);
   return true;
}

int main(int argc, char **argv) {
   int T;
   int bases[3];
   char buf[128];
   int i, j;
   flags = malloc(flags_size = sizeof(bool) * MAX_NUM);

   T = atoi(gets(buf));
   for (i = 1; i <= T; i++) {
      printf("Case #%d: ", i);
      gets(buf);
      bases[0] = bases[1] = bases[2] = 0;
      if (3 != sscanf(buf, "%d %d %d", &bases[0], &bases[1], &bases[2]) &&
          2 != sscanf(buf, "%d %d", &bases[0], &bases[1]))
           { puts("*** bad input"); exit(2); }
      
      int n;
      for (n = 2; ; n++) {
         bool allHappy = true;
         for (j = 0; j < 3 && allHappy; j++) {
            if (bases[j] && !happy(n, bases[j])) allHappy = false;
         }

         if (allHappy) {
            printf("%d\n", n);
            break;
         }
      }
   }
}

