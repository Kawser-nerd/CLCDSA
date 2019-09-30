#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;

int check(const char *s, char *t, int flag) {
    int i;

    if (flag & 1) t[0] = 'W';
    else t[0] = 'S';
    if (flag & 2) t[1] = 'W';
    else t[1] = 'S';
    i = 0;
    while (++i < N-1) {
        if (t[i] == 'S') {
            if (s[i] == 'o') t[i+1] = t[i-1];
            else if (t[i-1] == 'S') t[i+1] = 'W';
            else t[i+1] = 'S';
        } else {
            if (s[i] == 'o') {
                if (t[i-1] == 'W') t[i+1] = 'S';
                else t[i+1] = 'W';
            } else t[i+1] = t[i-1];
        }
    }
    if (((t[N-2] == t[0] && t[N-1] == 'S' && s[N-1] == 'o') || 
         (t[N-2] != t[0] && t[N-1] == 'S' && s[N-1] == 'x') ||
         (t[N-2] == t[0] && t[N-1] == 'W' && s[N-1] == 'x') ||
         (t[N-2] != t[0] && t[N-1] == 'W' && s[N-1] == 'o')) && 
        ((t[N-1] == t[1] && t[0] == 'S' && s[0] == 'o') || 
         (t[N-1] != t[1] && t[0] == 'S' && s[0] == 'x') ||
         (t[N-1] == t[1] && t[0] == 'W' && s[0] == 'x') ||
         (t[N-1] != t[1] && t[0] == 'W' && s[0] == 'o'))) {
        t[N] = '\0';
        return 0;
    } else {
        return 1;
    }
}

int main(void) {
    int i, res;
    char S[100010], T[100010];
    scanf("%d%s", &N, &S);
    memset(T,0,100010);

    memset(T,0,100010);
    res = check(S, T, 0);
    while (res && ++i<4) {
        memset(T,0,100010);
        res = check(S, T, i);
    }
    if (!res) printf("%s\n", T);
    else printf("-1\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:45:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[100010]’ [-Wformat=]
     scanf("%d%s", &N, &S);
           ^
./Main.c:45:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%s", &N, &S);
     ^