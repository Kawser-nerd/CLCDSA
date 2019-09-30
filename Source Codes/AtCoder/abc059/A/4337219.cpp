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
    array<string,3> s;
    string ans = "";
    for (int i = 0; i < 3; ++i) {
        cin >> s[i];
        ans += toupper(s[i][0]);
    }
    cout << ans << endl;

    return 0;
}