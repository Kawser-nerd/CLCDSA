#include <stdio.h>

int main(void)
{
  int T;
  int i,j,k,ttt;
  int a[4][4],b[4][4],s,t,c,res;
  scanf("%d",&T);
  for( ttt = 1; ttt <= T; ttt++ ) {
    printf("Case #%d: ",ttt);
    c = 0;
    scanf("%d",&s); --s;
    for( i = 0; i < 4; i++ ) {
      for( j = 0; j < 4; j++ ) scanf("%d",a[i]+j);
    }
    scanf("%d",&t); --t;
    for( i = 0; i < 4; i++ ) {
      for( j = 0; j < 4; j++ ) {
        scanf("%d",b[i]+j);
        if( t == i ) {
          for( k = 0; k < 4; k++ ) if( a[s][k] == b[i][j] ) {
              ++c;
              res = a[s][k];
            }
        }
      }
    }
    if( c == 0 ) puts("Volunteer cheated!");
    if( c == 1 ) printf("%d\n",res);
    if( c > 1 ) puts("Bad magician!");
  }
  return 0;
}
