
#include <stdio.h>

int ovation(void) {
    int i;
    static char S[2000];
    int smax;
    scanf("%d %s",&smax, S);
    int total=0;
    int extra=0;
    int s_i;
    //printf("%d %s = ",smax,S);
    for (i=0;i<=smax;i++) {
        s_i=S[i]-'0';
        //printf("i=%d si=%d t+x=%d x=%d\n",i,s_i,extra+total,extra);
        if (s_i>0 && total+extra < i) extra+=i - (extra+total);
        total+=s_i;
    }
    printf("%d\n",extra);
    return extra;
}

int ovation2(void) {
    int i;
    static char S[2000];
    int smax;
    scanf("%d %s",&smax, S);
    int total=0;
    int extra=0;
    int s_i;
    printf("%d %s = ",smax,S);
    for (extra=0;extra<10;extra++) {
        for (i=0;i<=smax;i++) {
            s_i=S[i]-'0';
            if (s_i>0 && total+extra < i) goto more;
            total+=s_i;
        }
    printf("%d\n",extra);
    return extra;
        more:
        ;
    }
    extra=-1;
    printf("%d\n",extra);
    return extra;
}


int main(int argc, char **argv) {
    int i,tc;
    scanf ("%d",&tc);
    for (i=1;i<=tc;i++) {
        printf("Case #%d: ",i);
        ovation();
    }
    return 0;
}
