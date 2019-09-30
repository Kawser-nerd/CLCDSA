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
    int m = 2025;
    int N;
    cin >> N;
    int d = m - N;
    for (int i = 1; i <= 9; i++) {
        for (int k = 1; k <= 9; k++) {
            if (i * k == d) {
                cout << i << " x " << k << endl;
            }
        }
    }
    

    return 0;
}