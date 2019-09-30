#include <stdio.h>

int
main(){
  int m, vv, status;
  status = scanf("%d", &m);
  if ( status == EOF ){
    return 1;
  }
  if ( 70000 < m && m <= 100000 ) {
    vv = 89;
  } else if ( 35000 <= m ) {
    vv = ( m - 30000 ) / 5000 + 80;
  } else if ( 6000 <= m && m <= 30000 ) {
    vv = m / 1000 + 50;
  } else if ( 100 <= m && m <= 5000 ){
    vv = m / 100;
  } else if ( m < 100 ) {
    vv = 0;
  } else {
    return 1;
  }

  printf("%02d\n",vv);
  return 0;
}