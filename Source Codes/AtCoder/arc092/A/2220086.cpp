#include <iostream>
#include <algorithm>
#include <vector>

int N;
constexpr int MAXN = 100;
struct Node{int id, x, y, flag;};
std::vector<Node> P;

int main() {
    std::cin >> N;
    P.resize(N * 2);
    for (int i = 0; i < N; i++) {
        P[i].id = 0;
        std::cin >> P[i].x  >> P[i].y;
    }
    for (int i = N; i < 2*N; i++) {
        P[i].id = 1;
        std::cin >> P[i].x  >> P[i].y;
    }

    std::sort(P.begin(), P.end(), [](auto a, auto b){return a.x < b.x;});
    int r_count = 0;
    int b_count = 0;
    int cnt = 0;
    for (int i = 0; i < 2 * N; ++i) {
        if (P[i].id == 1) {
            //blue
            int m = -1;
            int my = -1;
            for (int j = 0; j < i; j++) {
                if ((P[j].id == 0) && (P[j].flag == 0) && (P[j].y < P[i].y)) {
                    if(my < P[j].y) {
                        m = j;
                        my = P[j].y;
                    }
                }
            }
            if (m >= 0) {
                P[m].flag = 1;
                cnt++;
            }
        }
    }
    std::cout << cnt << std::endl;
}