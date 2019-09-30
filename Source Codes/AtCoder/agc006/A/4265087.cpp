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
    int N;
    cin >> N;
    string s,t;
    cin >> s >> t;
    int cnt = 0;
    for (int i = N; i >= 0; i--) {
        if (s.substr(N-i, i) == t.substr(0, i)) {
            cout << 2 * N - i << endl;
            break;
        }
    }


    return 0;
}