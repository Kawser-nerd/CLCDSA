
#include <stdio.h>

#define even(x) (((x) & 1)==0)

int main(int argc, char **argv) {
    int X,W,H;
    int t;
    int TC,C;
    int possible;
    scanf("%d",&TC);
    for (C=1;C<=TC;C++) {
        scanf("%d %d %d", &X, &W, &H);
        if (H>W) {t=H;H=W;W=t;}
        if (X==1) possible=1;
        if (X==2) possible=(even(W) || even(H));
        if (X==3) possible=((W==4 && H==3) || (W==3 && H==2) ||
                            (W==3 && H==3));
        if (X==4) possible=((W==4 && H==4) || (W==4 && H==3)) ;
        printf("Case #%d: %s\n",C,possible ? "GABRIEL" : "RICHARD");
    }
    return 0;
}
