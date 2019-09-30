#include <cstdio>
#include <cstdint>
#include <memory>
using namespace std;

int64_t h, w, m = 1000000007;
unique_ptr<unique_ptr<int64_t[]>[]> xs, ys;

void update(int x, int y) {
    ys[x][y] = 1;
    for (int i = x - 1; i <= x + 1; i += 2) {
        if (i < 0 || i >= h || xs[x][y] >= xs[i][y]) {
            continue;
        }

        if (!ys[i][y]) {
            update(i, y);
        }

        ys[x][y] += ys[i][y];
        ys[x][y] %= m;
    }
    for (int j = y - 1; j <= y + 1; j += 2) {
        if (j < 0 || j >= w || xs[x][y] >= xs[x][j]) {
            continue;
        }

        if (!ys[x][j]) {
            update(x, j);
        }

        ys[x][y] += ys[x][j];
        ys[x][y] %= m;
    }
}

int main() {
    scanf("%lld %lld", &h, &w);

    xs = make_unique<unique_ptr<int64_t[]>[]>(h);
    ys = make_unique<unique_ptr<int64_t[]>[]>(h);
    for (int i = 0; i < h; ++i) {
        xs[i] = make_unique<int64_t[]>(w);
        ys[i] = make_unique<int64_t[]>(w);
        for (int j = 0; j < w; ++j) {
            scanf("%lld", &xs[i][j]);
            ys[i][j] = 0;
        }
    }

    int64_t res = 0;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!ys[i][j]) {
                update(i, j);
            }

            res += ys[i][j];
            res %= m;
        }
    }

    printf("%lld\n", res);
    return 0;
} ./Main.cpp:38:24: warning: format specifies type 'long long *' but the argument has type 'int64_t *' (aka 'long *') [-Wformat]
    scanf("%lld %lld", &h, &w);
           ~~~~        ^~
           %ld
./Main.cpp:38:28: warning: format specifies type 'long long *' but the argument has type 'int64_t *' (aka 'long *') [-Wformat]
    scanf("%lld %lld", &h, &w);
                ~~~~       ^~
                %ld
./Main.cpp:46:27: warning: format specifies type 'long long *' but the argument has type 'long *' [-Wformat]
            scanf("%lld", &xs[i][j]);
                   ~~~~   ^~~~~~~~~
                   %ld
./Main.cpp:64:22: warning: format specifies type 'long long' but the argument has type 'int64_t' (aka 'long') [-Wformat]
    printf("%lld\n", res);
            ~~~~     ^~~
            %ld
4 warnings generated.