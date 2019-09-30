#include<stdio.h>
#include<string.h>

int main() {
  int n, m;
  int x, y;
  int i, j, k;
  int count;
  char sw[100001];

/*read header*/
  scanf("%d %d", &n, &m);

/*hairetsu initialize*/
  memset(sw,0x31,n);/*00110001*/
  sw[n+1] = 0x00;

/*read data*/
  for (i=0; i < m; i = i+1){
    scanf("%d %d", &x, &y);
    sw[x] = sw[x]^0x01;
    sw[y] = sw[y]^0x01;
  }

/*hantei*/
  if (strchr(sw, 0x30) == 0x00){
      printf("YES\n");
  }
  else {
      printf("NO\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &n, &m);
   ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &x, &y);
     ^