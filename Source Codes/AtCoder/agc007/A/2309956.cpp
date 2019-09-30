#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <cctype>
#include <list>
//#include <boost/multiprecision/cpp_int.hpp>

#define BIT(a) (1 << (a))

using namespace std;
//using namespace boost::multiprecision;

long long MOD = 1000000007;


long long mod_pow(long long x, long long n){
    long long res = 1;
    for(int i = 0;i < 60; i++){
        if(n >> i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

char field[10][10];
int H, W;

int dfs(int x, int y){
    int nx = x+1;
    int ny = y+1;
    field[x][y] = '.';
    int flag = 0;
    if (nx < W && field[nx][y] == '#'){
        flag = 1;
        dfs(nx, y);
    }
    if (ny < H && field[x][ny] == '#'){
        if (flag) return 0;
        dfs(x, ny);
    }
    return 0;
}

int main(void){
    cin >> H >> W;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            scanf(" %c", &field[j][i]);
        }
    }
    dfs(0, 0);
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            if (field[j][i] == '#'){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    cout << "Possible" << endl;
    return 0;
}