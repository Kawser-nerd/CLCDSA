#include <stdio.h>
#include <string.h>

int main(void) {
    int i, j, len, c[26]={0}, t=0;
    char S[100010];
    scanf("%s", &S);
    len = strlen(S);
    for (i=1;i<len-1;i++) {
        c[S[i]-'a']++;
    }
    for (j=0;j<=25;j++) t += c[j];
    t += (S[0]==S[len-1]) ? 1 : 0;
    if (t%2) printf("First\n");
    else printf("Second\n");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100010]’ [-Wformat=]
     scanf("%s", &S);
           ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", &S);
     ^