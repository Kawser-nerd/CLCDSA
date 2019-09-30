#include <stdio.h>
#include <string.h>

int main(void) {
    int i, len;
    long long T;
    char S[100010];
    scanf("%s", &S);
    len = strlen(S);
    T = 0;
    for (i=0;i<len;i++) {
        T += len-1;
        if (i>0 && i<len-1) {
            if (S[i] == 'U') T += i;
            if (S[i] == 'D') T += (len-1)-i;
        }
    }
    printf("%lld\n", T);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100010]’ [-Wformat=]
     scanf("%s", &S);
           ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", &S);
     ^