#include <stdio.h>
int main(){
    long long y,x,cnt=1;
    scanf("%ld%ld",&x,&y);
    while(x*2<=y){
        x*=2;
        cnt++;
    }
    printf("%ld",cnt);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
     scanf("%ld%ld",&x,&y);
           ^
./Main.c:4:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 3 has type ‘long long int *’ [-Wformat=]
./Main.c:9:12: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘long long int’ [-Wformat=]
     printf("%ld",cnt);
            ^
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld%ld",&x,&y);
     ^