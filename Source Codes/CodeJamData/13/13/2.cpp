#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory.h>
using namespace std;

int R, N, M, K;

double C[20][20];

class TestCase {
public:
    typedef long long ll;
    vector<ll> prods;
    vector< unordered_map< ll, int > > expected;
    vector< vector<int> > digsStorage;
    vector< double > digsProb;
    void doPrecalc() {
        vector<int> digs(N, 2);
        for (int id = 0; true; ++id) {
            double w = 0.0;
            vector<int> cnt(M - 1);
            for (int i = 0; i < N; ++i) {
                cnt[digs[i] - 2] += 1;
            }
            for (int i = 0, left = N; i < M - 1; ++i) {
                w += log(C[left][cnt[i]]);
                left -= cnt[i];
            }
            digsStorage.push_back(digs);
            digsProb.push_back(w);
            expected.resize(expected.size() + 1);
            for (int mask = 0; mask < (1<<N); ++mask) {
                ll pr = 1;
                for (int i = 0; i < N; ++i) {
                    if (mask & (1<<i)) {
                        pr *= digs[i];
                    }
                }
                expected[id][pr] += 1;
            }
            {
                if (digs == vector<int>(N, M))
                    break;
                int t = 0;
                while (digs[t] == M) {
                    ++t;
                }
                ++digs[t];
                while (t != 0) {
                    digs[t - 1] = digs[t];
                    --t;
                }
            }
        }
    }
    void Solve() {
        prods.resize(K);
        for (int i = 0; i < K; ++i) {
            cin >> prods[i];
        }
        vector<int> ans(N, 1);
        double wAns = -100000.0;
        for (int id =0; id < (int)digsStorage.size(); ++id) {
            double w = digsProb[id];
            for (int i = 0; i < K; ++i) {
                auto it = expected[id].find(prods[i]);
                if (it == expected[id].end())
                    w -= 100000000.0;
                else
                    w += log(it->second);
            }
            if (w > wAns) {
                wAns = w;
                ans = digsStorage[id];
            }
        }
        for (int i = 0; i < N; ++i) {
            cout << ans[i];
        }
        cout << endl;
    }
};

int main(void) {
    memset(C, 0, sizeof(C));
    C[0][0] = 1;
    for (int i = 1; i < 20; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    int T;
    cin >> T;
    cin >> R >> N >> M>> K;
    cout << "Case #1:" << endl;
    TestCase testCase;
    testCase.doPrecalc();
    for (int i = 0; i < R; ++i) {
        testCase.Solve();
        if (i % 100 == 0)
            cerr << "Solved " << i << endl;
    }
}