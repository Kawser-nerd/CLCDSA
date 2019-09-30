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
#include <set>
#define all(x) (x).begin(),(x).end()

const int MOD = 1e9 + 7;

void solve(){

}
int main(){
    int H,W;
    cin >> H >> W;
    vector<string> a(H);
    for (int i = 0; i < H; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < H+2; ++i) {
        string out;
        if (i == 0 || i == H+1) {
            out = string(W+2,'#');
        } else {
            out = '#' + a[i-1] + '#';
        }
        cout << out << endl;
    }


    return 0;
}