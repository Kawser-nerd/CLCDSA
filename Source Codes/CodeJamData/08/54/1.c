# include <stdio.h>
# include <string.h>

# define MOD 10007

int mat[ 102 ][ 102 ];
int din[ 102 ][ 102 ], w, h;

int solve( int a, int b){
  int x, y;
  int res = 0;
  if( mat[a][b] == 1 ) return 0;
  if( a > h || b > w) return 0;
  if( a == h && b == w) return 1;

  if( din[a][b] != -1) return din[ a ][b];
  for( x = 0; x <= 3; x++)
  for( y = 0; y <= 3; y++){
    if( x == 0 && y == 0) continue;
    if( x* x + y * y != 5 ) continue;
    res +=solve( a + x, b + y);
    res %= MOD;
  }
  return din[a][b] = res;
}

main(){
  int casos, set, r, x, a, b;
  freopen("a.in","r", stdin);
  freopen("d.out","w", stdout);
  for( scanf("%d", &casos), set = 1 ; set <= casos; set++){
    scanf("%d %d %d", &h, &w, &r);
    memset( mat , 0, sizeof( mat ));
    for( x = 0; x < r; x++){
      scanf("%d %d", &a, &b);
      mat[a][b] = 1;     
    } 
    memset( din , -1, sizeof( din ));
    printf( "Case #%d: %d\n", set , solve( 1, 1));
  }       
}
