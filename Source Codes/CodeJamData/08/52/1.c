# include <stdio.h>
# include <string.h>

char mapa[101][ 101];
int n, m;

char queue[ 2 ][ 15 * 15 * 16 * 16 * 16 * 16][ 7 ];
int vis[16][16][16][16][15][15], set;

int dx[ 4 ] = {1, -1, 0, 0};
int dy[ 4 ] = {0, 0, 1, -1};

int position[ 15 ][ 15 ][ 4 ][2];

void find( char c, int *a, int *b){
  int x, y;
  for(x = 0; x < n; x++)
  for(y = 0; y < m; y++)
    if( mapa[x][y] == c ){
      *a = x;
      *b = y;
      return;    
    }
}

int sale( int x, int y){
   if( x <0 || x >= n || y < 0 || y >= m || mapa[x][y] == '#') return 1;
   return 0;    
}

void take( int x, int y, int dir, int *a, int *b){
   //printf("{%d %d}", x, y);
   if( x < 0 || y < 0 || x >= n || y >= m) return;
 //  printf("{-- %d %d, %d %d}", x, y, x + dx[ dir ], y + dy[ dir]);
   if( sale( x + dx[ dir ], y + dy[ dir])){
  //    printf("%d %d <-", x, y );
      *a = position[ x ][ y ][ dir ][ 0 ] = x;
      *b = position[ x ][ y ][ dir ][ 1 ] = y;
      return;
   }
   if( position[ x ][ y ][ dir ][ 0 ] != -1){
    //  printf("**");
      *a = position[ x ][ y ][ dir ][ 0 ];
      *b = position[ x ][ y ][ dir ][ 1 ];
      return;
   }
   take( x +dx[ dir ], y + dy[ dir ], dir, a, b);
   position[ x ][ y ][ dir ][ 0 ] = *a;
   position[ x ][ y ][ dir ][ 1 ] = *b;
}

void insert(int pos, int *nq,  int yx, int yy, int bx, int by, int x, int y, int length){
  if( x < 0 || y < 0 || x >= n || y >= m) return;
  if( mapa[ x ][ y ] == '#') return;
  if( yx == -1 || bx == -1) return;
 // printf("{%d %d %d %d %d %d %d\n", yx, yy, bx, by,x, y, length);
  if( vis[ yx ][ yy ][ bx ][ by][x ][y] == set) 
    return;
  vis[ yx ][ yy ][ bx ][ by][x ][y] = set;
  
  queue[pos][ *nq ][ 0 ] = yx;
  queue[pos][ *nq ][ 1 ] = yy;
  queue[pos][ *nq ][ 2 ] = bx;
  queue[pos][ *nq ][ 3 ] = by;
  queue[pos][ *nq ][ 4 ] = x;
  queue[pos][ *nq ][ 5 ] = y;
  queue[pos][ *nq ][ 6 ] = length;
  (*nq)++;  
}

main(){
  int casos, x, a, b, y, dir, nq[2], len, yx, yy, bx, by, pos;
  freopen("b2.in","r", stdin);
  freopen("b2.out","w", stdout);
  for( scanf("%d", &casos), set = 1 ; set <= casos; set++){
    scanf("%d %d", &n, &m);
    for( x = 0; x < n; x++) scanf("%s", mapa[x]);
    memset( position , -1, sizeof( position ));
    for( x = 0; x < n; x++)
    for( y = 0; y < m; y++){
      if( mapa[x][y] == '#') continue;
      for( dir = 0; dir < 4; dir++){
        take( x, y, dir, &a, &b);
    //    printf("[%d %d %d, %d %d]\n", x, y, dir, a, b);
   //     while(1);
      }
    }
  //  while(1);
  //  printf("****\n");
    find( 'O', &a, &b);
    printf("Case #%d: ", set);
    memset( nq, 0, sizeof( nq ));
    insert(0, &nq[ 0 ], 16, 16, 16,16, a, b, 0);
    for( len = 0; ; len++){
      if( nq[ len % 2] == 0){
        printf("THE CAKE IS A LIE\n");
        break;
      }
      for( pos = 0; pos < nq[ len % 2]; pos++){
        yx = (int)queue[ len % 2][ pos ][ 0 ];
        yy = (int)queue[ len % 2][ pos ][ 1 ];
        bx = (int)queue[ len % 2][ pos ][ 2 ];
        by = (int)queue[ len % 2][ pos ][ 3 ];
        x = (int)queue[ len % 2][ pos ][ 4 ];
        y = (int)queue[ len % 2][ pos ][ 5 ];
        if( mapa[x][y] == 'X'){
          printf("%d\n", len);
          break;    
        }
      //  if( len  <= 2 && ( x >= 4 && y >= 0 ))
      //  printf("%d %d | %d %d %d %d %d , %d\n", x, y, yx, yy, bx, by, len , nq[ len % 2]);
        for( dir = 0; dir < 4; dir++){
          insert( (len) % 2 , &nq[ (len) % 2 ], position[x][ y ][ dir ][ 0], position[x][y][ dir ][ 1 ], bx, by, x, y, len);
          insert( (len) % 2 , &nq[ (len) % 2 ], yx, yy, position[x][ y ][ dir ][ 0], position[x][y][ dir ][ 1 ], x, y, len);
        }
        if( x == yx && y == yy && bx != 16 ){
       //   printf("*");
          insert( (len + 1) % 2 , &nq[ (len + 1) % 2 ], yx, yy, bx, by, bx, by, len + 1);
        }
        if( x == bx && y == by && yx != 16 ){
         // printf(".");
          insert( (len + 1) % 2 , &nq[ (len + 1) % 2 ], yx, yy, bx, by, yx, yy, len + 1);
        }
        for( dir = 0; dir < 4; dir++)
          insert( (len + 1) % 2 , &nq[ (len + 1) % 2 ], yx, yy, bx, by, x + dx[ dir ], y + dy[ dir ], len + 1);
      //  printf("_----------\n");
      }
      if( pos < nq[ len % 2] ) break;
      nq[ len % 2] = 0; 
    }
  }  
  return 0;       
}
