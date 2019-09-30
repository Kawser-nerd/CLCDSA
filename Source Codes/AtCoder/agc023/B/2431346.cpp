#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    char S[N][N+1];
    for (int i=0; i<N; ++i) {
        cin >> S[i];
    }
    int count = 0;
    for (int i=0; i<N; ++i) {
        bool flg = true;
        for (int j=0; j<N; ++j) {
            for (int k=0; k<N; ++k) {
                if (S[(j+i)%N][k] != S[(k+i)%N][j]) {
                    flg = false;
                    break;
                }
            }
            if (!flg) break;
        }
        if (flg) {
            count += N;
        }
    }
    cout << count << '\n';
    return 0;
}