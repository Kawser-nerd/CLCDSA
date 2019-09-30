#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//standard
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define abs(a) ((a)>(0)?(a):-(a))


int main() {
    long x,y,ans;


    //input
    scanf("%ld%ld",&x,&y);
    ans = abs(abs(x)-abs(y));

    if(x == 0 || y == 0){
        if(x == 0){
            if(y < 0)ans += 1;
        }else{
            if(x > 0)ans += 1;
        }
    }else if(abs(x) > abs(y)){
        if(x < 0 && y < 0)ans += 0;
        if(x < 0 && y > 0)ans += 1;
        if(x > 0 && y < 0)ans += 1;
        if(x > 0 && y > 0)ans += 2;
    }else if(abs(x) == abs(y)){
        if(x < 0 && y < 0)ans += 0;
        if(x < 0 && y > 0)ans += 1;
        if(x > 0 && y < 0)ans += 1;
        if(x > 0 && y > 0)ans += 0;
    }else{
        if(x < 0 && y < 0)ans += 2;
        if(x < 0 && y > 0)ans += 1;
        if(x > 0 && y < 0)ans += 1;
        if(x > 0 && y > 0)ans += 0;
    }
    //calculation
    //quicksort(array, 0, n-1);

    //Output
    printf("%ld\n", ans);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld%ld",&x,&y);
     ^