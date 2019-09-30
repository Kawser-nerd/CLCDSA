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

    string ans;
    if (N <= 59) ans = "Bad";
    else if (N <= 89) ans = "Good";
    else if (N <= 99) ans = "Great";
    else {
        ans = "Perfect";
    }
    cout << ans << endl;


    return 0;
}