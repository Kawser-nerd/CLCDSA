# include <stdio.h>
# include <string.h>

int list[ 1001 ], list2[1001];

int compare( int *a, int *b){
  return *a - *b;    
}

main(){
  int x, y, n, casos, set = 1, a, b;
  long long res;
  freopen("a2.in","r", stdin);
  freopen("a.out","w", stdout);
  for( scanf("%d", &casos) ;casos--; ){
    
    scanf("%d", &n);
    for(x = 0; x < n; x++)
     scanf("%d", &list[ x ]);
    qsort( list, n, sizeof( int ), compare);
    for(x = 0; x < n; x++)
     scanf("%d", &list2[ x ]);
    qsort( list2, n, sizeof( int), compare);
    a = 0; b = n -1;
    res = 0;
    
    for( x = 0; x < n; x++ )
      res += (long long)list[ x ] * (long long)list2[ n - x - 1];
    printf("Case #%d: %I64d\n", set++, res);
  }
  return 0;       
}
