// I'm too sleepy... Let's try a greedy solution

#include <stdio.h>

#define MAX 105

int rows, cols, m[MAX][MAX];

int verify() {
  int i, j, maxx, maxy, max;

  while (1) {

    /*puts("-----");
    for (i=0; i<rows; i++) {
      for (j=0; j<cols; j++) 
	printf("%2d ", m[i][j]);
      putchar('\n');
    }*/

    maxx = maxy = 0;
    for (i=0; i<rows; i++)
      for (j=0; j<cols; j++)
	if (m[i][j]>m[maxy][maxx]) {
	  maxy = i;
	  maxx = j;
	}

    max = m[maxy][maxx];
    if (max<0) return 1;
    
    for (i=0; i<rows; i++)
      if (m[i][maxx]<0 && m[i][maxx]<-max) break;
    if (i==rows) {
      for (i=0; i<rows; i++)
	if (m[i][maxx] == max) m[i][maxx]=-max;
      continue;
    }
    
    for (j=0; j<cols; j++)
      if (m[maxy][j]<0 && m[maxy][j]<-max) break;
    if (j==cols) {
      for (j=0; j<cols; j++)
	if (m[maxy][j] == max) m[maxy][j]=-max;
      continue;
    }

    return 0;
  }

  return -1;
}

int main() {
  int t, c, i, j;

  scanf("%d", &t);
  for (c=1; c<=t; c++) {

    scanf("%d %d", &rows, &cols);
    for (i=0; i<rows; i++)
      for (j=0; j<cols; j++)
	scanf("%d", &m[i][j]);

    printf("Case #%d: %s\n", c, verify()?"YES":"NO");
  }


  return 0;
}
