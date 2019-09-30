#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

map<Int, int> M[66666];
Int pat[66666], comb[16][16];
int ns[66666][12];

int main()
{
    for (int i = 0; i < 16; ++i) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
        }
    }

    Int S = 0;
    for (int a = 2; a <= 8; ++a) {
    for (int b = a; b <= 8; ++b) {
        cerr << b << endl;
    for (int c = b; c <= 8; ++c) {
    for (int d = c; d <= 8; ++d) {
    for (int e = d; e <= 8; ++e) {
    for (int f = e; f <= 8; ++f) {
    for (int g = f; g <= 8; ++g) {
    for (int h = g; h <= 8; ++h) {
    for (int i = h; i <= 8; ++i) {
    for (int j = i; j <= 8; ++j) {
    for (int k = j; k <= 8; ++k) {
    for (int l = k; l <= 8; ++l) {
        int v[12] = {a,b,c,d,e,f,g,h,i,j,k,l};
        for (int x = 0; x < 12; ++x) {
            ns[S][x] = v[x];
        }
        for (int x = 0; x < (1<<12); ++x) {
            Int p = 1;
            for (int y = 0; y < 12; ++y) {
                if (x & (1<<y)) p *= v[y];
            }
            ++M[S][p];
        }
        int cnt[10] = {};
        for (int x = 0; x < 12; ++x) {
            cnt[v[x]]++;
        }
        pat[S] = 1;
        for (int x = 2, y = 12; x <= 8; ++x) {
            pat[S] *= comb[y][cnt[x]];
            y -= cnt[x];
        }
        ++S;
    }
    } 
    }
    }
    }    
    }        
    }    
    }        
    }    
    }        
    }    
    }

    int T, R, N, M_, K;
    cin >> T >> R >> N >> M_ >> K;

    cout << "Case #1:" << endl;
    for (int i = 0; i < R; ++i) {
        Int prod[12];
        for (int j = 0; j < K; ++j) {
            cin >> prod[j];
        }

        int v[12];
        for (int j = 0; j < 12; ++j) {
            v[j] = 2;
        }
        double best = 0;
        for (int j = 0; j < S; ++j) {
            bool ok = true;
            double score = pat[j];
            for (int k = 0; k < K; ++k) {
                ok &= M[j].find(prod[k]) != M[j].end();
                if (!ok) break;
                score *= M[j][prod[k]] / 4096.0;
            }
            if (ok && best < score) {
                best = score;
                memcpy(v, ns[j], sizeof(v));
            }
        }
        cerr << i << ' ';
        for (int j = 0; j < 12; ++j) {
            cout << v[j];
        }
        cout << endl;
    }
    
    return 0;
}
