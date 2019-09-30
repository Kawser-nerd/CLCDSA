#include <iostream>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#define all(x) (x).begin(),(x).end()

const int MOD = 1e9 + 7;

void solve(){

}
int main(){
    int N;
    cin >> N;
    char s[55][55] = {};
    char ans[55][55] = {};
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            cin >> s[i][k];
            ans[k][N-1-i] = s[i][k];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            cout << ans[i][k];
        }
        cout << endl;
    }





    return 0;
}