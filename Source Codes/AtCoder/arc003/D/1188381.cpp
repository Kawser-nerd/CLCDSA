#include <cstdio>
#include <vector>
#include <cstdint>
#include <algorithm>

uint32_t xor128() {
    static uint32_t x=123456789;
    static uint32_t y=362436069;
    static uint32_t z=521288629;
    static uint32_t w=88675123;
    uint32_t t=x^(x<<11);
    x = y;
    y = z;
    z = w;
    return (w = (w^(w>>19)) ^ (t^(t>>8)));
}

int Z[16][16];

bool is_valid(int N, std::vector<int> P, int K) {
    for (int i=0; i<K; ++i) {
        uint32_t u=xor128()%N;
        uint32_t v=xor128()%(N-1);
        if (u <= v) ++v;

        std::swap(P[u], P[v]);
    }

    for (int i=N; --i;)
        if (Z[P[i]][P[i-1]])
            return false;

    return !Z[P[0]][P[N-1]];
}

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    xor128();
    for (int i=0; i<M; ++i) {
        int A, B;
        scanf("%d %d", &A, &B);
        Z[A][B] = Z[B][A] = 1;
    }

    std::vector<int> P(N);
    for (int i=1; i<N; ++i)
        P[i] = i;

    int suc=0, trial=293399;
    for (int i=0; i<trial; ++i)
        if (is_valid(N, P, K))
            ++suc;

    printf("%.4f\n", double(suc)/trial);
    return 0;
}