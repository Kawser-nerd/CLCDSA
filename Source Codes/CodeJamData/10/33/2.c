/* Ugly and slow, I know :) */

#include <stdio.h>
#include <string.h>

#define MAX 515

#define BLACK   0
#define WHITE   1
#define INVALID 2

int rows, cols;
char m[MAX][MAX];
char ok[MAX][MAX];
int ac[MAX][MAX];

void print_board() {
  int i,j;
  for (i=1; i<=rows; i++) {
    for (j=1; j<=cols; j++)
      putchar(m[i][j]+'0');
    putchar('\n');
  }    
}

int check(int y, int x, char c) {
  if (y<1 || y>rows || x<1 || x>cols) return 0;
  return (m[y][x] == c);
}

void make_ac() {
  int i,j;
  
  memset(ac, 0, sizeof(ac));

  for (i=1; i<=rows; i++)
    for (j=1; j<=cols; j++) 
      ac[i][j] = ok[i][j] + ac[i-1][j] + ac[i][j-1] - ac[i-1][j-1];

  /*for (i=1; i<=rows; i++) {
    for (j=1; j<=cols; j++)
      printf("%4d", ac[i][j]);
    putchar('\n');
    }*/
}


void make_ok() {
  int i,j;

  for (i=1; i<=rows; i++)
    for (j=1; j<=cols; j++)
      if (check(i+1,j,1-m[i][j]) &&
	  check(i,j+1,1-m[i][j]) &&
	  check(i+1,j+1,m[i][j]))
	ok[i][j]=1;
      else 
	ok[i][j]=0;
  
  /*puts("-----");
  for (i=1; i<=rows; i++) {
    for (j=1; j<=cols; j++)
      putchar(ok[i][j]+'0');
    putchar('\n');
    }*/
}

void decode(char *s, int r) {
  int i, j, val, pos;

  for (i=0, pos=1; s[i]; i++, pos+=4) {
    if (s[i]>='A') val=10+(s[i]-'A');
    else val=s[i]-'0';
    for (j=pos+3; j>=pos; j--, val/=2) 
      m[r][j] = val % 2;
  }
}

int verify(int i, int j, int size) {
  int y, x;
  
  if (i+size-1>rows) return 0;
  if (j+size-1>cols) return 0;

  if (size>1) {
    if ( (ac[i+size-2][j+size-2] -
	  ac[i-1][j+size-2] -
	  ac[i+size-2][j-1] + 
	  ac[i-1][j-1]) != (size-1)*(size-1))
      return 0;
	}

  for (y=i; y<i+size; y++)
    for (x=j; x<j+size; x++)
      if (m[y][x]==INVALID) return 0;
  
  return 1;
}

void invalidate(int i, int j, int size) {
  int y, x;
  for (y=i; y<i+size; y++)
    for (x=j; x<j+size; x++)
      m[y][x] = INVALID;
}

int main() {
  char buf[MAX];
  int nt, i, j, t, maxsize, size, nsizes, count[MAX];

  scanf("%d", &t);
  for (nt=1; nt<=t; nt++) {
    scanf("%d %d", &rows, &cols);
    for (j=1; j<=rows; j++) {
      scanf("%s", buf);
      decode(buf, j);
    }

    /*puts("");
      print_board();*/

    if (rows<cols) maxsize=rows;
    else maxsize = cols;
    
    make_ok();
    make_ac();
    
    nsizes = 0;
    for (size=maxsize; size>=1; size--) {
      count[size]=0;
      for (i=1; i<=rows; i++)
	for (j=1; j<=cols; j++)
	  if (verify(i, j, size)) {
	    count[size]++;
	    invalidate(i, j, size);
	  }
      if (count[size]>0) nsizes++;
    }

    printf("Case #%d: %d\n", nt, nsizes);
    for (size=maxsize; size>=1; size--)
      if (count[size]>0)
	printf("%d %d\n", size, count[size]);
  }


  return 0;
}
