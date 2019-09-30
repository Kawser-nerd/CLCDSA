# include <stdio.h>
# include <string.h>

# define INF 1e100

double list[200000];
double correct[200000];

double min( double a, double b ){ return a < b ? a : b; }

main(){
  int ncases, cases, A, B, x;
  double sol, R, solution;
  for( scanf("%d", &ncases), cases = 1; cases <= ncases ; cases++ ){
    scanf("%d %d", &A, &B);
    for( x = 0; x < A; x++) scanf("%lf", &list[ x ]);
    correct[ 0 ] = 1.0;
    for( x = 1; x <= A ; x++){
    	 correct[ x ] = correct[ x - 1 ] * list[ x - 1];
    }
    sol = 0.0;
    correct[ x ] = 0;
    solution = INF;
    for( x = 0; x <= A; x++){
      /* Correct   */
      sol = correct[ x ] * ( B - A + 1.0 + (A - x)*2  );
      /* Incorrect */
      sol += ( 1.0 - correct[ x ] ) * ( B - A + 1.0 + B + 1.0 +  (A - x)*2 );
      solution = min( sol , solution );
    }
    solution = min( solution, B + 2);
    printf("Case #%d: %.9lf\n", cases, solution);
  }
  return 0;	
}