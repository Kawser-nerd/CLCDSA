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

    int a[4] = {};
    int i = 0;
    while (N != 0) {
        a[i++] = N % 10;
        N /= 10;
    }
    if ((a[0] == a[1] && a[1] == a[2]) || (a[1] == a[2] && a[2] == a[3])) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
}