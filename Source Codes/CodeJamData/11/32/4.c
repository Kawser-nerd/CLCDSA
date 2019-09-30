# include <string.h>
# include <stdio.h>

int L,  C;
long long t;

int list[1000002];
int hash[100002];

long long abso( long long  x ){ return x < 0 ? -x : x; }
long long min( long long a , long long b ){ return a< b ? a : b; }
main(){
  int x, y, ncases, cases, n;
  long long sum = 0, tiempo, calc;
  for( scanf("%d", &ncases), cases = 1; cases <= ncases; cases++ ){
  	 scanf("%d %lld %d %d", &L, &t, &n, &C);
  	 for( x = 0; x< C; x++){
  	    scanf("%d", &list[ x]);
  	 }
  	 for( x = C ; x < n; x++) list[x] = list[ x % C ];
  	 tiempo = 0;
  	 memset( hash, 0, sizeof( hash ));
  	 for( x = 0; x < n; x++){
  	    tiempo += list[x] * 2; 
  	    if( t <= tiempo ){
  	        hash[ (int)abso( min( list[ x ] * 2 , tiempo - t ) ) ]++;
  	    }
  	 }
  	 calc = 0;
  	 for( x = 100000; x >= 1 && L > 0 ; x--){
  	 	while( hash[ x ] > 0 && L > 0  ){
  	 	  calc += x;
  	 	  hash[x]--;
  	 	  L--;
  	 	}
  	 }
  	 printf("Case #%d: %lld\n", cases, tiempo - (calc / 2));
  }
  return 0;	
}