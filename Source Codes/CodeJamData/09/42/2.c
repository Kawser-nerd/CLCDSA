#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

char cave[60][60];
int R, C, F;

void kaboom() {
   fprintf(stderr, "*****************\nkaboom.\n");
   exit(2);
}

bool fall(int *r, int *c, int ignore_row) {
   int f = 0;
   while (*r < R-1 && ( ((*r)+1 == ignore_row) || (cave[(*r)+1][*c] == '.') )) {
      (*r)++;
      f++;
      if (f > F) return false;
   }
   return true;
}

int solve(int sr, int sc, int current_digs, int best_so_far,
                        int recurse_level) {
   int r = sr, c = sc;
   int t;

   //fprintf(stderr,"solve(sr=%d,sc=%d,cur_digs=%d,best=%d,rl=%d)\n", 
   //     sr, sc, current_digs, best_so_far, recurse_level);

   if (sr == R-1) return current_digs;
   if (current_digs > best_so_far) return INT_MAX;

   // move as much to the left as we can
   while (c >= 1 && cave[r][c-1] == '.' && cave[r+1][c-1] == '#') c--;

   while (1) {
      // at current position, try possibilities
      if (c >= 1 && cave[r][c-1] == '.' && cave[r+1][c-1] == '.') {
         // fall left
         int newr = r, newc = c-1;
         if (fall(&newr,&newc,-1)) {
            t = solve(newr, newc, current_digs, best_so_far, recurse_level+1);
            if (t < best_so_far) best_so_far = t;
         }
      }
      
      if (c < C-1 && cave[r][c+1] == '.' && cave[r+1][c+1] == '.') {
         // fall right
         int newr = r, newc = c+1;
         if (fall(&newr,&newc,-1)) {
            t = solve(newr, newc, current_digs, best_so_far, recurse_level+1);
            if (t < best_so_far) best_so_far = t;
         }
      }

      if (c >= 1 && cave[r][c-1] == '.' && cave[r+1][c-1] == '#') {
         // dig left 
         cave[r+1][c-1] = '.';
         t = solve(r, c, current_digs + 1, best_so_far, recurse_level+1);
         cave[r+1][c-1] = '#'; // restore
         if (t < best_so_far) best_so_far = t;
      }
      
      if (c < C-1 && cave[r][c+1] == '.' && cave[r+1][c+1] == '#') {
         // dig right
         cave[r+1][c+1] = '.';
         t = solve(r, c, current_digs + 1, best_so_far, recurse_level+1);
         cave[r+1][c+1] = '#'; // restore
         if (t < best_so_far) best_so_far = t;
      }

      // move right
      if (c < C-1 && cave[r][c+1] == '.' && cave[r+1][c+1] == '#') c++;
      else break;
   }

   return best_so_far;
}

void doCase(int caseno) {
   char buf[512];
   memset(&cave, 0, sizeof(cave));
   gets(buf);
   if (3 != sscanf(buf, "%d %d %d", &R, &C, &F)) kaboom();
   //fprintf(stderr, "R = %d, C = %d, F = %d\n", R, C, F);
   int r;
   for (r = 0; r < R; r++) {
      gets(cave[r]);
      //fprintf(stderr, "cave[%d] = '%s'\n", r, cave[r]);
   }

   int t = solve(0, 0, 0, INT_MAX, 0);
   if (t == INT_MAX) printf("Case #%d: No\n", caseno);
   else printf("Case #%d: Yes %d\n", caseno, t);
}

int main() {
   char buf[512];
   int N = atoi(gets(buf));
   int i;

   for (i = 1; i <= N; i++) 
      doCase(i);

   return 0;
}

