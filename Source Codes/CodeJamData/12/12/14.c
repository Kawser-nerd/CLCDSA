# include <stdio.h>
# include <string.h>

int ONE[10001], TWO[10001], vis[10001];


main(){
  int cnt, ncases, cases, sol, x, y, puntos, pos, n;
  for( scanf("%d", &ncases), cases = 1; cases <= ncases; cases++ ){
  	scanf("%d", &n);
  	for( x = 0; x < n; x++){
  	  scanf("%d %d", &ONE[ x ], &TWO[ x ]);	
  	}
  	memset( vis, 0, sizeof( vis ));
  	cnt = n ;
  	puntos = 0;
  	for( x = 0; cnt > 0 ; x++){
  	  pos = -1;
  	  for( y = 0; y < n; y++) if( vis[ y ] < 2){
  	    if( TWO[y] <= puntos ) { pos = y; break; }
  	    if(  vis[ y ] == 0 && ONE[y] <= puntos && ( pos == -1 || TWO[ pos ] <= TWO[ y ]) ) pos = y;
  	  }
  	  if( pos == -1) break;
  	  if( TWO[pos] <= puntos ){
  	  	puntos += 2 - vis[ pos ];
  	  	vis[ pos ] = 2;
  	  	cnt--;
  	  }else{
  	  	puntos++;
  	  	vis[ pos ] = 1;
  	  }
  	}
  	printf("Case #%d: ", cases);
  	if( cnt == 0 ) printf("%d\n", x);
  	else printf("Too Bad\n");
  	
  }
  return 0;	
}