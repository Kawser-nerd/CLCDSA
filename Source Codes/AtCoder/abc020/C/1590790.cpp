#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

vector<vector<long long>> getd(int H, int W, vector<string> &S, int x){
    vector<vector<long long>> d(H*W, vector<long long>(H*W, 1LL << 60));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            for(int k=0; k<4; k++){
                int ii = i + dy[k];
                int jj = j + dx[k];
                if(jj < 0 || jj >= W || ii < 0 || ii >= H) continue;
                int z1 = W*i+j;
                int z2 = W*ii+jj;
                if(S[ii][jj] == '.') d[z2][z1] = 1;
                else d[z2][z1] = x;
            }
        }
    }
    return d;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W, T;
    cin >> H >> W >> T;
    vector<string> S(H);
    for(int i=0; i<H; i++) cin >> S[i];
    int s, g;
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++){
            if(S[i][j] == 'S'){
                s = W*i+j;
                S[i][j] = '.';
            }else if(S[i][j] == 'G'){
                g = W*i+j;
                S[i][j] = '.';
            }
        }

    int N = H*W;
    int lb = 1;
    int ub = T+1;
    while(ub - lb > 1){
        int x = (ub - lb) / 2 + lb;
        vector<vector<long long>> d = getd(H, W, S, x);
        for(int k=0; k<N; k++)
            for(int i=0; i<N; i++)
                for(int j=0; j<N; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        if(d[g][s] <= T) lb = x;
        else ub = x;
    }
    cout << lb << endl;
    return 0;
}