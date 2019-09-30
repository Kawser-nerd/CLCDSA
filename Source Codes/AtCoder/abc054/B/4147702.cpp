#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;
using P = pair<int, int>;


char A[55][55];
char B[55][55];

ull E = 1000000007;

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }
    for (int w = 0; w <= N - M; ++w) {
        for (int h = 0; h <= N - M; ++h) {
            bool flag = true;
            for (int i = 0; i < M; ++i) {
                for (int j = 0; j < M; ++j) {
                    if (A[w + i][h + j] != B[i][j]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
            if (flag) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}