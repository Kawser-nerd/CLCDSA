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
    int H,W;
    cin >> H >> W;
    vector<string> C(H);
    for (int i = 0; i < H; i++){
        cin >> C[i];
    }
    for (int i = 0; i < 2*H; i++){
        cout << C[i/2] << endl;
    }


    return 0;
}