#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;
using ll = long long;

const int nmax = 500;
int C[nmax], S[nmax], F[nmax];

int func(int v,int N);

int main() {
        int N;
        cin >> N;
        for (int i = 1; i < N; i++) {
                cin >> C[i] >> S[i] >> F[i];
        }

        for (int i = 1; i < N; i++) {
                cout << func(i, N) << endl;
        }

        cout << 0 << endl;

        return 0;
}


int func(int v,int N) {
        int ret = C[v] + S[v];

        for (int i = v+1; i < N; i++) {
                if(ret > S[i]) {
                        if (ret % F[i] == 0) {
                                ret += C[i];
                        }
                        else {
                                ret += F[i] - (ret % F[i]) + C[i];
                        }
                }
                else {
                        ret = S[i] + C[i];
                }
        }

        return ret;
}