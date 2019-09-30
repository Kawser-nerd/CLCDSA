#include <cstdio>

int N, M;
int c[100005];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0, a, b; i < M; i++) scanf("%d %d", &a, &b), c[a]++, c[b]++;
    for (int i = 1; i <= N; i++) if (c[i]&1) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
}