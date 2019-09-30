#include<iostream>
#include<cstring>
using namespace std;
const int MAX_N = 16;


int N, M;
int rule[MAX_N * MAX_N][2];

void read() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rule[i][0] = a - 1;
        rule[i][1] = b - 1;
    }
}


void work() {
    static long long dp[1 << MAX_N];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int mask = 0; mask < (1 << N); ++mask) {
        for (int nextGoal = 0; nextGoal < N; ++nextGoal) {
            if (mask & (1 << nextGoal)) continue;

            for (int i = 0; i < M; ++i) {
                if (nextGoal == rule[i][0] && (mask & (1 << rule[i][1]))){
                    goto _fail;
                }
            }
            
            dp[mask | (1 << nextGoal)] += dp[mask];
            
        _fail:;
        }
    }

    cout << dp[(1 << N) - 1] << endl;
}


int main() {
    read();
    work();
    return 0;
}