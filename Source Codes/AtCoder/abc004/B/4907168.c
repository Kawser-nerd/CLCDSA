#include <stdio.h>
     
    int main(void) {
      char C[4][4];
      for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
          scanf(" %c",&C[i][j]);
        }
      }
     
      for(int i=3;i>=0;i--) {
        for(int j=3;j>=0;j--) {
          printf("%c ",C[i][j]);
        }
        printf("\n");
      }
      return 0;
    } ./Main.c: In function ‘main’:
./Main.c:7:11: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
           scanf(" %c",&C[i][j]);
           ^