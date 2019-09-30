#include <iostream>
#include <string>



constexpr int N = 101;
int n;
int A[2][N];
int C[2][N];

struct Pos{int x, y;};

int main() {
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> A[0][i];
    }
    for(int i = 0; i < n; i++) {
        std::cin >> A[1][i];
    }

    Pos p{0,0};
    C[0][0] = A[0][0];
    C[1][0] = A[1][0] + C[0][0];
    while (true) {
        if (p.x == (n -1)) {
            break;
        }
        C[0][p.x+1] = C[0][p.x] + A[0][p.x + 1];
        C[1][p.x+1] = std::max(C[0][p.x+1]+A[1][p.x+1], C[1][p.x]+A[1][p.x+1]);
        p.x += 1;
    }
    std::cout << C[1][n-1] << std::endl;
}