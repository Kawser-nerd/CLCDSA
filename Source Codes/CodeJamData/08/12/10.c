# include <string.h>
# include <stdio.h>

int graph[2002][2002*4];
int G[2002][2002*4];
int ngraph[ 2002 ];

main(){
  int set, casos, n, m, x, y, mask, ban, t, a, b;
  freopen("b.in","r", stdin);
  freopen("b.out","w", stdout);
  for( set = 1, scanf("%d", &casos); casos-- ; set++){
     scanf("%d", &n);
     scanf("%d", &m);
     memset( ngraph,0, sizeof( ngraph));
     for( x = 0; x < m; x++){
        scanf("%d", &t);
        for( ; t--; ){
    //      printf("--\n");
          scanf("%d %d", &a, &b);
          a--;
  //        printf("--\n");
          G[ x ][ a * 2 + b ] = set ;
//          printf("|%d %d|\n", x, a * 2 + 1);
          graph[ x ][ ngraph[ x ]++ ] = a *  2 + b ; 
        }
     }
     printf("Case #%d:", set);
     for( mask = 0; mask < (1<<n); mask++){
       ban = 0;
       for( x = 0; x < m && ban == 0 ; x++){
         for( y = 0; y < n; y++){
           t = ( mask & (1<<y) ) > 0 ? 1 : 0 ;
           if(  G[ x ][ y * 2 + t ] == set )
             break;
         }
         if( y >= n ) ban = 1;
       }
       if( ban == 0){
         for( x = 0;x < n; x++)
           printf(" %d", (mask & (1<<x) ) == 0 ? 0 : 1 );
         printf("\n");
         break;
       }
     }
     if( mask >= (1<<n)) printf(" IMPOSSIBLE\n");
  }
  return 0;       
}
