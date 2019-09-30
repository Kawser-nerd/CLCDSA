#include <stdio.h>
#include <string.h>

void solve(int cas){
    char s[128];
    int i, L, c;
    char last;
    scanf("%s", s);
    L = strlen(s);
    last = '+';
    c = 0;
    for (i=L-1;i>=0;i--){
        if (s[i]!=last){
            last = s[i];
            c++;
        }
    }
    printf("Case #%d: %d\n", cas, c);
}

int main(){
    int cas, T;
    scanf("%d", &T);
    for (cas=1;cas<=T;cas++){
        solve(cas);
    }
    return 0;
}

