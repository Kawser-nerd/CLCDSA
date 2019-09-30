# include <stdio.h>

int n;
int m;


int G[ 10002 ], C[ 10002];
int val[ 10002];

int din[ 3 ][ 10002 ];

int min( int a, int b){ return a < b ? a : b; }

int solve( int V, int nodo ){
    int res = (1<<22), carry , X = nodo;
    if( nodo > m ) return ( val[ nodo ] == V ? 0 : (1<<22) ) ;
    if( din[ V ][ nodo ] != -1 ) return din[ V ][ nodo ];
    if( C[ nodo ] == 1){
       if( G[ nodo ] == 1 ) carry  = 0;
       else carry = 1;
          if( V == 0 ){
            res = min( solve( 0, X* 2 ) + solve( 1, X*2 + 1) + carry, res ); 
            res = min( solve( 1, X* 2 ) + solve( 0, X*2 + 1) + carry, res ); 
            res = min( solve( 0, X* 2 ) + solve( 0, X*2 + 1) + carry , res ); 
          }
          if( V == 1 ){
            res = min( solve( 1, X* 2 ) + solve( 1, X*2 + 1) + carry , res); 
          }
       
       if( G[ nodo ] == 0) carry = 0;
       else carry = 1;
          if( V == 0){
            res = min( solve( 0, X* 2 ) + solve( 0, X*2 + 1) + carry, res );             
          }    
          if( V == 1){
            res = min( solve( 0, X* 2 ) + solve( 1, X*2 + 1) + carry, res ); 
            res = min( solve( 1, X* 2 ) + solve( 0, X*2 + 1) + carry , res ); 
            res = min( solve( 1, X* 2 ) + solve( 1, X*2 + 1) + carry , res );               
          }
       
    }else{
       if( G[ nodo ] == 1 ){ // AND
          if( V == 0 ){
            res = min( solve( 0, X* 2 ) + solve( 1, X*2 + 1), res ); 
            res = min( solve( 1, X* 2 ) + solve( 0, X*2 + 1), res ); 
            res = min( solve( 0, X* 2 ) + solve( 0, X*2 + 1), res ); 
          }
          if( V == 1 ){
            res = min( solve( 1, X* 2 ) + solve( 1, X*2 + 1) , res); 
          }
       }
       if( G[ nodo ] == 0){
          if( V == 0){
            res = min( solve( 0, X* 2 ) + solve( 0, X*2 + 1), res );             
          }    
          if( V == 1){
            res = min( solve( 0, X* 2 ) + solve( 1, X*2 + 1), res ); 
            res = min( solve( 1, X* 2 ) + solve( 0, X*2 + 1), res ); 
            res = min( solve( 1, X* 2 ) + solve( 1, X*2 + 1), res );               
          }
       }
    }
    return din[ V ][ nodo ] = res;
}


main(){
  int casos, r, x, pos, set, v; 
  freopen("a2.in","r", stdin);
  freopen("a2.out","w", stdout);
  
  for( scanf("%d", &casos), set = 1 ; set <= casos ; set++ ){
     scanf("%d %d", &n, &v);
     m = (n - 1) / 2;
     for( pos = 1, x = 0; x < m; x++, pos++){
        scanf("%d %d", &G[pos], &C[ pos ]);
     }
     for(  x = 0; pos <= n; x++, pos++){
        scanf("%d", &val[ pos ]);
     }
     memset( din, -1, sizeof( din ));
     r = solve(v, 1 );
     printf("Case #%d: ", set);
     if( r == (1<<22)) printf("IMPOSSIBLE\n");
     else printf("%d\n", r );
  }
  return 0; 
}
