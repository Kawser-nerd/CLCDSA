#include <iostream>

using namespace std;

const int maxN = static_cast<const int>(1e5 + 10);

int fa[maxN], dis[maxN], N, M;

int find(int x) {
    if(x == fa[x]) {
        return x;
    }
    int temp = fa[x];
    fa[x] = find(temp);
    dis[x] = dis[x] + dis[temp];
    return fa[x];
}

bool merge(int x, int y, int d) {
    int fx = find(x), fy = find(y);
    if(fx == fy) {
        return dis[y] - dis[x] == d;
    } else {
        fa[fx] = fy;
        dis[fx] = dis[y] - dis[x] - d;
        return true;
    }
}


int main() {
#ifdef ACM_XYZHAO_TEST
    freopen("../test.in", "r", stdin);
//	freopen("../test.out", "w", stdout);
#endif

    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        fa[i] = i;
        dis[i] = 0;
    }
    int l, r, d;

    bool flag = true;
    for (int i = 0; i < M; ++i) {
        scanf("%d %d %d", &l, &r, &d);
        if(flag && !merge(l, r, d)) {
            flag = false;
        }
    }

    printf("%s\n", flag ? "Yes" : "No");

    return 0;
}