#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long LL;

// import here

void solve_three(vector<vector<char>>& ans, LL& a, LL& b, LL y, LL x){
  ans[y+0][x+0] = '<'; ans[y+0][x+1] = '>'; ans[y+0][x+2] = '^';
  ans[y+1][x+0] = '^'; ans[y+1][x+1] = '.'; ans[y+1][x+2] = 'v';
  ans[y+2][x+0] = 'v'; ans[y+2][x+1] = '<'; ans[y+2][x+2] = '>';
  a -= 2;
  b -= 2;
}

int main(){
    LL n, m, a, b;
    cin >> n >> m >> a >> b;
    LL block = (n/2) * (m/2);
    LL h_line = min<LL>(a, (n%2) * (m/2));
    LL v_line = min<LL>(b, (m%2) * (n/2));
    LL a_block = (max<LL>(0, a-h_line) + 1) / 2;
    LL b_block = (max<LL>(0, b-v_line) + 1) / 2;
    vector<vector<char>> ans(2002, vector<char>(2002, '.'));
    for(LL i = 0; i < h_line; ++i){
        ans[n-1][i*2+0] = '<';
        ans[n-1][i*2+1] = '>';
        --a;
    }
    for(LL i = 0; i < v_line; ++i){
        ans[i*2+0][m-1] = '^';
        ans[i*2+1][m-1] = 'v';
        --b;
    }
    for(LL y = 0; y < n/2; ++y){
        for(LL x = 0; x < m/2; ++x){
            if(a >= 2){
                ans[y*2+0][x*2+0] = '<';
                ans[y*2+0][x*2+1] = '>';
                ans[y*2+1][x*2+0] = '<';
                ans[y*2+1][x*2+1] = '>';
                a -= 2;
                continue;
            }
            if(b >= 2){
                ans[y*2+0][x*2+0] = '^';
                ans[y*2+1][x*2+0] = 'v';
                ans[y*2+0][x*2+1] = '^';
                ans[y*2+1][x*2+1] = 'v';
                b -= 2;
                continue;
            }
            if(a > 0){
                ans[y*2+0][x*2+0] = '<';
                ans[y*2+0][x*2+1] = '>';
                --a;
                continue;
            }
            if(b > 0){
                ans[y*2+0][x*2+0] = '^';
                ans[y*2+1][x*2+0] = 'v';
                --b;
                continue;
            }
        }
    }
    if(n >= 3 && m >= 3 && n % 2 == 1 && m % 2 == 1 && b == 1 && ans[n-3][m-3]=='<' && ans[n-2][m-3]=='.'){
        solve_three(ans, a, b, n-3, m-3);
    }
    if(a > 0 || b > 0){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for(LL y = 0; y < n; ++y){
        for(LL x = 0; x < m; ++x){
            cout << ans[y][x];
        }
        cout << endl;
    }
    return 0;
}