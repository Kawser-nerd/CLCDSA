#include <stdio.h>
int ng[3];
int min(int a, int b) {
    return a < b ? a : b;
}
int dfs(int n, int npos) {
    if (npos >= 3) {
        return n / 3 + (n % 3 == 0 ? 0 : 1);
    }
    if (n < ng[npos]) return dfs(n, npos+1);
    int pad = n - ng[npos] - 1;
    int conf1 = 0, conf2 = 0;
    for (int i = 1; npos + i < 3; i++) {
        if (ng[npos] - 1 == ng[npos + i]) conf1 = 1;
        if (ng[npos] - 2 == ng[npos + i]) conf2 = 2;
    }
    if (conf1 && conf2) {
        return 101;
    }
    if (conf2) {
        return pad / 3 + 1 + dfs(ng[npos] - 1, npos + 1) + (pad % 3 == 2 ? 1 : 0);
    }
    if (conf1) {
        return pad / 3 + 1 + dfs(ng[npos] - 2, npos + 1) + (pad % 3 == 0 ? 0 : 1);
    }
    return pad / 3 + 1 + min(dfs(ng[npos]-1,npos+1)+(pad % 3 == 2 ? 1 : 0), dfs(ng[npos]-2,npos+1)+(pad % 3 == 0 ? 0 : 1));
}
int main() {
    int n; scanf("%d%d%d%d", &n, ng, ng+1, ng+2);
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (ng[i] < ng[j]) {
                int tmp = ng[i];
                ng[i] = ng[j];
                ng[j] = tmp;
            }
        }
    }
    int npos = 0;
    while (npos < 3 && ng[npos] > n) npos++;
    if (npos < 3 && ng[npos] == n) {
        puts("NO");
        return 0;
    }
    if (dfs(n, npos) > 100) puts("NO");
    else puts("YES");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     int n; scanf("%d%d%d%d", &n, ng, ng+1, ng+2);
            ^