#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
#define rep(i, a, b) for(int i = (a); i < (b); ++i )
#define rrep(i, a, b) for(int i = (a); i > (b); --i )
#define REP(i, a, b) for(int i = (a); i <= (b); ++i )
#define RREP(i, a, b) for(int i = (a); i >= (b); --i )

ll A, B;
ll h, w;

char G[101][101];

int main() {
    std::cin >> A >> B;
    ll cnt_a = 1, cnt_b = 1;
    rep(i, 0, 100) {
        rep(j, 0, 100) {
            if (i < 50) {
                //White
                if((i%2 == 0) && (j%2) && (cnt_b < B) && (j < 99)) {
                    G[i][j] = '#';
                    cnt_b++;
                }else{
                    G[i][j] = '.';
                }
            } else {
                //Black
                if((i%2 == 1) && (j%2) && (cnt_a < A) && (j < 99)) {
                    G[i][j] = '.';
                    cnt_a++;
                }else{
                    G[i][j] = '#';
                }
            }
        }
    }
    std::cout << 100 << " " << 100 << std::endl;
    rep(i, 0, 100) {
        rep(j, 0, 100) {
            std::cout << G[i][j];
        }
        std::cout << std::endl;
    }
}