#include <stdio.h>

int main(void){
    int n,a,cnt=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
      scanf("%d",&a);
      for(;;) {
        if(a%2!=0 && a%3!=2) break;
        else if(a%2==0) {
          a--;
          cnt++;
        }
        else{
          a--;
          cnt++;
        }
      }
    }
    printf("%d\n",cnt);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:7:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&a);
       ^