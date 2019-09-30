# include <stdio.h>
# include <string.h>

char map[1000][1000];

main(){
  int x, y, n, m, notsol, cases, ncases;
  for( scanf("%d", &ncases), cases = 1; cases <= ncases ; cases++ ){
     scanf("%d %d", &n, &m);
     notsol = 0;
     for( x = 0; x < n; x++) scanf("%s", map[x]);
     for( x = 0; x < n; x++){
        for( y = 0; y < m; y++){
          if( map[x][y] == '#' ){
            if( map[x+ 1][y] == '#' && map[x+ 1][y + 1] == '#' && map[x][y + 1] == '#'){
            	map[x][y] = '/';
            	map[x][y + 1] = '\\';
            	map[x+1][y] = '\\';
            	map[x+1][y+1] = '/';
            }else notsol = 1;
          }	
        }	
     }	
     printf("Case #%d:\n", cases);
     if( notsol == 1 ){
       printf("Impossible\n");	
     }else{
       for( x = 0; x < n; x++) printf("%s\n", map[x]);	
     }
  }	
  return 0;
}