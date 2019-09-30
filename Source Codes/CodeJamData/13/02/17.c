#include <stdio.h>
int main() {
    int t, T, N, M, fail, i, j, wmaks[100], kmaks[100], s[100][100];
    scanf("%d", &T);
    for (t=1; t<=T; t++) {
        scanf("%d %d", &N, &M);
        fail=0;
        for (i=0; i<N; i++) wmaks[i]=0;
        for (j=0; j<M; j++) kmaks[j]=0;
        for (i=0; i<N; i++) {
            for (j=0; j<M; j++) {
                scanf("%d", &s[i][j]);
                if (s[i][j] > wmaks[i]) wmaks[i] = s[i][j];
                if (s[i][j] > kmaks[j]) kmaks[j] = s[i][j];
                if (s[i][j]>100 || s[i][j]<=0) fail=1;
            }
        }
        for (i=0; i<N; i++) {
            for (j=0; j<M; j++) {
                if (s[i][j]<wmaks[i] && s[i][j]<kmaks[j]) fail=1;
            }
        }
        printf("Case #%d: ", t);
        if (fail) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
