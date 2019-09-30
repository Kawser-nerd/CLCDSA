
#include <stdio.h>

int K;
char pattern[2000];

void flip(char *p, int k, int *toohigh) {
    int i;
    for (i=0;i<k;i++) {
        if (!p[i]) {*toohigh=1; return; }
        if (p[i]=='+') p[i]='-';
        else if (p[i]=='-') p[i]='+';
    }
}

int pancake(void) {
    int i;
    int bcnt;
    int toohigh=0;
    scanf("%s %d",pattern,&K);
    i=0;
    bcnt=0;
    while (pattern[i]) {
        if (pattern[i]=='-') {
            flip(pattern+i,K,&toohigh);
            if (toohigh) return -1;
            bcnt++;
        }
        i++;
    }
    return bcnt;
}

int main(int argc, char **argv) {
    int tc,i,r;
    scanf("%d", &tc);
    for (i=1;i<=tc;i++) {
        printf("Case #%d: ",i);
        r=pancake();
        if (r>=0) printf("%d\n",r);
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
