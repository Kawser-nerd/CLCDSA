#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T, t, n, total;
    char prev, S[200];
    scanf("%d", &T);
    for (t=1; t<=T; t++) {
        scanf("%s", S);
        n=0;
        while (S[n])
            n++;
        n--;
        while ((n>=0) && (S[n]=='+'))
            n--;
        total=0;
        prev=' ';
        while (n>=0) {
            if (S[n]!=prev){
                prev=S[n];
                total++;
            }
            n--;
        }
        printf("Case #%d: %d\n", t, total);
    }
    return 0;
}
