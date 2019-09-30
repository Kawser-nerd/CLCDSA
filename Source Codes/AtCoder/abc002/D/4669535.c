#include <stdio.h>

static int N;
static int M;
static int XY[12][12];

int search(int id, int flag) {
  if(id == N) {
    int num = 0;
    int OK  = 1;
    for(int i = 0; i < N; i++) {
      if((flag & (0x1 << i)) == 0)
	continue;
      num++;

      for(int j = 0; j < i; j++) {
	if((flag & (0x1 << j)) == 0)
	  continue;
	if(XY[i][j] == 0) {
	  OK = 0;
	}
      }
    }

    if(OK) {
      return num; 
    } else {
      return 1;
    }
  }

  int s1 = search(id+1, flag | (0x1 << id));// yes
  int s2 = search(id+1, flag);// no
  return (s1 > s2) ? s1 : s2; 
}

int main(void) {
  scanf("%d%d", &N, &M);
  for(int i = 0; i < M; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    XY[x-1][y-1] = XY[y-1][x-1] = 1;
  }
  printf("%d\n", search(0, 0));
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:38:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &N, &M);
   ^
./Main.c:41:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &x, &y);
     ^