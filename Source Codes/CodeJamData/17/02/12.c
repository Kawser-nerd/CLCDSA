
#include <stdio.h>

char N[30];

char *problem(void) {
    int i, very=0;
    scanf("%s",N);
    for (i=1;N[i];i++) {
        if (N[i-1]>N[i]) break;
        if (N[i-1]<N[i]) very=i;
    }
    if (!N[i]) return N;
    N[very]--;
    i=very+1;
    while (N[i]) N[i++]='9';
    if (N[0]=='0') return N+1;
    else return N;
}

int main(int argc, char **argv) {
    int i,tc;
    scanf("%d",&tc);
    for (i=1;i<=tc;i++) {
        printf("Case #%d: %s\n",i, problem());
    }
    return 0;
}
