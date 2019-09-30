#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int w, h, k;

int is_edge(int ii, int jj) {
  return ii == 0 || jj == 0 || ii == h-1 || jj == w-1;
}

int min(int ii, int jj) {
  if (ii < jj){
    return ii;
  } else {
    return jj;
  }
}

int main() {
  char a[800][800];
  int b[640000][2];
  int i, j;
  int x, y, xy;
  int si, sj;
  scanf("%d %d %d", &h, &w, &k);
  for (i = 0; i < h; i = i+1) {
    scanf("%s", a[i]);
  }
  for (i = 0; i < h; i = i+1) {
    for (j = 0; j < w; j = j+1) {
      if (a[i][j] == 'S') {
	si = i;
	sj = j;
      }
    }
  }

  b[0][0] = si;
  b[0][1] = sj;
  int l = 0;
  int r = 1;
  
  for (i = 0; i < k; i = i+1) {
    if (l == r) {
      break;
    }
    /*d is the number of points to be evaluated*/
    /*l is the number of points evaluated*/
    /*r is the number of points in the list b*/
    int d = 0;
    for (j = l; j < r; j = j+1) {
      int x = b[j][0];
      int y = b[j][1];
      if (!is_edge(x,y)) {
	/*search points around (x,y)*/
	if (a[x][y+1] == '.') {
	  b[r+d][0] = x;
	  b[r+d][1] = y+1;
	  a[x][y+1] = 'f';
	  d = d+1;
	}
	if (a[x][y-1] == '.') {
	  b[r+d][0] = x;
	  b[r+d][1] = y-1;
	  a[x][y-1] = 'f';
	  d = d+1;
	}
	if (a[x+1][y] == '.') {
	  b[r+d][0] = x+1;
	  b[r+d][1] = y;
	  a[x+1][y] = 'f';
	  d = d+1;
	}
	if (a[x-1][y] == '.') {
	  b[r+d][0] = x-1;
	  b[r+d][1] = y;
	  a[x-1][y] = 'f';
	  d = d+1;
	}
      }
    }
    l = r;
    r = r+d;
  }
  /*
  for (i = 0; i < r; i = i+1) {
    printf("%d %d\n", b[i][0], b[i][1]);
  }
  */
  
  
  /*    for (i = 0; i < h; i = i+1) {
    for (j = 0; j < w; j = j+1) {
      printf("%d", b[i][j]);
    }
    printf("\n");
    }  */
  

  int ans = 800;

  for (i = 0; i < r; i = i+1) {
    x = ceil(((double)min(b[i][0], h-b[i][0]-1))/k) + 1;
    y = ceil(((double)min(b[i][1], w-b[i][1]-1))/k) + 1;
    xy = min(x, y);
    ans = min(xy, ans);
  }

  printf("%d\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &h, &w, &k);
   ^
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", a[i]);
     ^