#include <stdio.h>

#define SEP 100
#define MAX 1005

typedef struct {
  int x, y;
} Point;

typedef struct {
  Point p1, p2;
} Line;

Line l[MAX];

int ccw(Point p1, Point p2, Point p3) {
  int dx1, dx2, dy1, dy2;
  dx1 = p2.x - p1.x; dy1 = p2.y - p1.y;
  dx2 = p3.x - p2.x; dy2 = p3.y - p2.y;
  if(dy1*dx2 < dy2*dx1) return 1;
  else return 0;
}

int intersect(Line l1, Line l2) {
  return
    ((ccw(l1.p1, l1.p2, l2.p1) != ccw(l1.p1, l1.p2, l2.p2))
     && (ccw(l2.p1, l2.p2, l1.p1) != ccw(l2.p1, l2.p2, l1.p2)));
}

int main() {
  int i, j, k, t, n, count;

  scanf("%d", &t);
  for (i=1; i<=t; i++) {
    scanf("%d", &n);
    count = 0;
    for (j=0; j<n; j++) {
      l[j].p1.x = 0;
      l[j].p2.x = SEP;
      scanf("%d %d", &l[j].p1.y, &l[j].p2.y);
      for (k=0; k<j; k++)
	if (intersect(l[j], l[k])) count++;
    }
    printf("Case #%d: %d\n", i, count);
  } 

  return 0;
}
