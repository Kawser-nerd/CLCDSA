# include <stdio.h>
# include <string.h>

int n, L, H;
int list[10000];

int min( int a, int b){ return a < b ? a :b;}

main(){
  int x, y, cont, sol, cases, ncases;
  for( scanf("%d", &ncases), cases = 1; cases <= ncases; cases++){
     scanf("%d %d %d", &n, &L, &H);	
     for( x = 0; x < n; x++) scanf("%d", &list[ x ]);
     sol = (1<<22);
     for( x = L; x <= H; x++){
        cont = 0;
        for( y = 0; y < n; y++)	{
           if( (x % list[y]) == 0 ||( list[y] %  x ) == 0 )  cont++;
        }
        if( cont == n ){
        	sol = min( sol, x );
        }
     }
     printf("Case #%d: ", cases);
     if( sol == (1<<22)) printf("NO\n");
     else printf("%d\n", sol);
  }
  return 0;	
}