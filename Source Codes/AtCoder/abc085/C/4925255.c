#include <stdio.h>
int main(){
    int x,y,z,n,Y;
    scanf("%d %d",&n,&Y);
    for(x=0;x<=n;x++){
        for(y=0;y<=n-x;y++){
            for(z=0;z<=n-x-y;z++){
            if(((10*x+5*y+z)==(Y/1000))&&(x+y+z==n)){
          printf("%d %d %d",x,y,z);
          return 0;
        }
            }
        }
    }
    printf("-1 -1 -1");
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&n,&Y);
     ^