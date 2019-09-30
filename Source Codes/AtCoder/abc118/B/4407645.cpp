#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    int K[31] = {0};
    int A = 0;

    int bkt[31] = {0};
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> K[i];
        for (int j = 0; j < K[i]; ++j) {
            cin >> A;
            ++bkt[A];
        }
    }
    int res = 0;
    for (int i = 0; i < 31; ++i) {
        if (bkt[i]==N) ++res;
    }
    cout << res;
    return 0;
}