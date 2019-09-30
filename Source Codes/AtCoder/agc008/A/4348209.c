#include <stdio.h>
#define abs(a) ((a)>(0)?(a):-(a))

int main() {
    int x,y,ans;

    scanf("%d%d",&x,&y);
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

    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&x,&y);
     ^