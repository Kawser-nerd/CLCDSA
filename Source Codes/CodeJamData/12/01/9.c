#include <stdio.h>
#include <stdlib.h>

#define TRUE         1
#define FALSE        0

void handleCase ();
//             a    b    c    d    e    f    g    h    i    j    k    l    m    n    o    p    q    r    s    t    u    v    w    x    y    z
char map[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};


int main () {
   int n;
   freopen ("in.txt", "r", stdin);
   freopen ("out.txt", "w", stdout);
   scanf ("%d ", &n);
   int i;
   for (i = 0; i < n; i++) {
      printf ("Case #%d: ", i + 1);
      handleCase ();
   }
}


void handleCase () {
   char line[2000];
   char c;
   int i = 0;
   scanf ("%c", &c);
   while (c != '\n') {
      line[i] = c;
      i++;
      scanf ("%c", &c);
   }
   line[i] = '\0';
   for (i = 0; line[i] != '\0'; i++) {
      if (line[i] >= 'a' && line[i] <= 'z') {
         printf ("%c", map[line[i] - 'a']);
      } else {
         printf (" ");
      }
   }
   printf ("\n");
}



