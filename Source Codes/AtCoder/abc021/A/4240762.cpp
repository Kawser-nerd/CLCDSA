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
    if (N % 2 == 1) {
        cout << N / 2 + 1 << endl;
        for (int i = 0; i < N/2; i++) {
            cout << 2 << endl;
        }
        cout << 1 << endl;
    } else {
        cout << N / 2 << endl;
        for (int i = 0; i < N/2; i++) {
            cout << 2 << endl;
        }
    }

    return 0;
}