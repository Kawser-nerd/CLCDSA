#include<stdio.h>

int main(void){
    int i,j,x,y;
    long long r,b,pc,pl,pr,pre,aa,bb;

    scanf("%lld %lld",&r,&b);
    scanf("%d %d",&x,&y);
    pl = 0;
    pr = r + b;

    pre = -1;

    for(;;){
        pc = (pl + pr) / 2;
        aa = (r - pc) / (x - 1);
        bb = (b - pc) / (y - 1);
        if(aa + bb >= pc && r - pc >= 0 && b - pc >= 0){
            if(pc == pre)
                break;
            pl = pc + 1;
        }
        else
            pr = pc - 1;
        pre = pc;
    }
    printf("%lld\n",pc);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld",&r,&b);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&x,&y);
     ^