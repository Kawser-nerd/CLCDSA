#include <stdio.h>
int HABATSU(long *R, int size, long group)
{
  int ret = 0, count = 0;
  int i;
  for(i=0;i<size;++i){
    if( group&(1<<i) ){
      if( (R[i]&group)==group ){
        ++count;
      } else {
        break;
      }
    }
  }
  if( i== size ){
    ret = count;
  }
  return ret;
}

int main(void)
{
  char buffer[10];
  int N, M;
  int i;
  long R[12], group;
  int max = 0;

  fgets(buffer, sizeof(buffer), stdin);
  sscanf(buffer, "%d %d", &N, &M);
  for( i=0; i<N; ++i ){
    R[i] = 1<<i;
  }
  for( i=0; i<M; ++i ){
    int x, y;
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d %d", &x, &y);
    --x; --y;
    R[x] |= 1<<y;
    R[y] |= 1<<x;
  }
  for( group=1;group<(1<<N); ++group){
    int cnt = HABATSU(R, N, group);
    if( cnt > max ) max = cnt;
  }
  printf("%d\n", max);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buffer, sizeof(buffer), stdin);
   ^
./Main.c:36:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(buffer, sizeof(buffer), stdin);
     ^