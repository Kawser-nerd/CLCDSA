#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>
#include <cstring>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

//??
typedef long long int ll;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//????????
class Solve {
public:
    int N, M, A, B;
    vector<vector<char> > ans;

    void input() {
        cin >> N >> M >> A >> B;
        ans.resize(N, vector<char>(M, '.'));
    }


    void kiki() {
        if (!(A <= M / 2 * N && B <= N / 2 * M && A + B <= (M * N) / 2)) {
            cout << "NO" << endl;
            return;
        }
        int a = A;
        int b = B;

        for (int i = 0; i < M / 2 * 2 - 2; i += 2) {
            if (a > 0) {
                ans[N - 1][i] = '<';
                ans[N - 1][i + 1] = '>';
                a--;
            }
        }

        for (int i = 0; i < N / 2 * 2 - 2; i += 2) {
            if (b > 0) {
                ans[i][M - 1] = '^';
                ans[i + 1][M - 1] = 'v';
                b--;
            }
        }

        for (int i = 0; i < N - 2; i += 2) {
            for (int j = 0; j < M - 2; j += 2) {
                if (i == N - 3 && j == M - 3) {
                    continue;
                }
                if (a > b) {
                    if (a > 1) {
                        ans[i][j] = '<';
                        ans[i + 1][j] = '<';
                        ans[i][j + 1] = '>';
                        ans[i + 1][j + 1] = '>';
                        a -= 2;
                    } else if (a > 0) {
                        ans[i][j] = '<';
                        ans[i][j + 1] = '>';
                        a--;
                    }
                } else {
                    if (b > 1) {
                        ans[i][j] = '^';
                        ans[i + 1][j] = 'v';
                        ans[i][j + 1] = '^';
                        ans[i + 1][j + 1] = 'v';
                        b -= 2;
                    } else if (b > 0) {
                        ans[i][j] = '^';
                        ans[i + 1][j] = 'v';
                        b--;
                    }
                }
            }
        }

        if (a == 2 && b == 2) {
            ans[N - 3][M - 3] = '<';
            ans[N - 3][M - 2] = '>';
            ans[N - 1][M - 2] = '<';
            ans[N - 1][M - 1] = '>';

            ans[N - 2][M - 3] = '^';
            ans[N - 1][M - 3] = 'v';
            ans[N - 3][M - 1] = '^';
            ans[N - 2][M - 1] = 'v';
            a -= 2;
            b -= 2;
        } else if (a > 1) {
            for (int i = max(0, N - 3); i < N; ++i) {
                if (a > 0) {
                    ans[i][M - 3] = '<';
                    ans[i][M - 2] = '>';
                    a--;
                }
            }
            if (b > 0) {
                ans[N - 3][M - 1] = '^';
                ans[N - 2][M - 1] = 'v';
                b--;
            }
        } else {
            for (int i = max(0, M - 3); i < M; ++i) {
                if (b > 0) {
                    ans[N - 3][i] = '^';
                    ans[N - 2][i] = 'v';
                    b--;
                }
            }
            if (a > 0) {
                ans[N - 1][M - 3] = '<';
                ans[N - 1][M - 2] = '>';
                a--;
            }
        }


        if (a != 0 || b != 0) {
//            exit(-1);
            cout << "NO" << endl;
        }

        cout << "YES" << endl;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cout << ans[i][j];
            }
            cout << endl;
        }

    }

    void kigu() {
        int a = A;
        int b = B;
        if (N % 2 == 1) {
            for (int i = 0; i + 1 < M; i += 2) {
                if (a > 0) {
                    ans[N - 1][i] = '<';
                    ans[N - 1][i + 1] = '>';
                    a--;
                }
            }
        } else {
            for (int i = 0; i + 1 < N; i += 2) {
                if (b > 0) {
                    ans[i][M - 1] = '^';
                    ans[i + 1][M - 1] = 'v';
                    b--;
                }
            }
        }

        for (int i = 0; i + 1 < N; i += 2) {
            for (int j = 0; j + 1 < M; j += 2) {
                if (a > b) {
                    if (a > 1) {
                        ans[i][j] = '<';
                        ans[i + 1][j] = '<';
                        ans[i][j + 1] = '>';
                        ans[i + 1][j + 1] = '>';
                        a -= 2;
                    } else if (a > 0) {
                        ans[i][j] = '<';
                        ans[i][j + 1] = '>';
                        a--;
                    }
                } else {
                    if (b > 1) {
                        ans[i][j] = '^';
                        ans[i + 1][j] = 'v';
                        ans[i][j + 1] = '^';
                        ans[i + 1][j + 1] = 'v';
                        b -= 2;
                    } else if (b > 0) {
                        ans[i][j] = '^';
                        ans[i + 1][j] = 'v';
                        b--;
                    }
                }
            }
        }

        if (a > 0 || b > 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    cout << ans[i][j];
                }
                cout << endl;
            }
        }


    }

    void guki() {
        kigu();
    }

    void gugu() {
        int a = A;
        int b = B;
        for (int i = 0; i + 1 < N; i += 2) {
            for (int j = 0; j + 1 < M; j += 2) {
                if (a > b) {
                    if (a > 1) {
                        ans[i][j] = '<';
                        ans[i + 1][j] = '<';
                        ans[i][j + 1] = '>';
                        ans[i + 1][j + 1] = '>';
                        a -= 2;
                    } else if (a > 0) {
                        ans[i][j] = '<';
                        ans[i][j + 1] = '>';
                        a--;
                    }
                } else {
                    if (b > 1) {
                        ans[i][j] = '^';
                        ans[i + 1][j] = 'v';
                        ans[i][j + 1] = '^';
                        ans[i + 1][j + 1] = 'v';
                        b -= 2;
                    } else if (b > 0) {
                        ans[i][j] = '^';
                        ans[i + 1][j] = 'v';
                        b--;
                    }
                }
            }
        }

        if (a > 0 || b > 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    cout << ans[i][j];
                }
                cout << endl;
            }
        }
    }

    void solve() {
        input();

        if (N % 2 == 1 && M % 2 == 1) {
            kiki();
        } else if (N % 2 == 1 && M % 2 == 0) {
            kigu();
        } else if (N % 2 == 0 && M % 2 == 1) {
            guki();
        } else if (N % 2 == 0 && M % 2 == 0) {
            gugu();
        }

    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}