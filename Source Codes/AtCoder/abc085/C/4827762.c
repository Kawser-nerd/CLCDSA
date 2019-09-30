#include <stdio.h>

enum STATUS {NOTFIN, FIN};

int main(){
  int n, y;
  enum STATUS s = NOTFIN;
  int result[3], p0, p1, p2;
  scanf("%d %d", &n, &y);
  if(n < 1 || 2000 < n || y < 1000 || 20000000 < y || (y%1000))
    return 1;

  for(p0 = 0; p0 <= n + 1; p0++){
    if(s == NOTFIN){
      for(p1 = 0; p1 <= n - p0; p1++){
        if(s == NOTFIN){
          p2 = n - p1 - p0;
            if(s == NOTFIN){
              if((p0 * 10000 + p1 * 5000 + p2 * 1000) == y){
                result[0] = p0;
                result[1] = p1;
                result[2] = p2;
                s = FIN;
              }
            }
        }
      }
    }
  }

  if(s == FIN)
    printf("%d %d %d\n", result[0], result[1], result[2]);
  else
    printf("%d %d %d\n", -1, -1, -1);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &n, &y);
   ^