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
    vector<int> a(3);
    for (int i = 0; i < 3; i++){
        cin >> a[i];
    }
    sort(all(a));
    if (a[0] == 5 && a[1] == 5 && a[2] == 7){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}