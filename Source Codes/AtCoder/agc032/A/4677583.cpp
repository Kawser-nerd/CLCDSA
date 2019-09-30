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
int liner_search(vector<int> a) {
    int ret;
    for (int i = a.size()-1; i >= 0; --i) {
        if (i+1 == a[i]) {
            return i;
        }
    } 
    return -1;
}

int main(){
    int N;
    cin >> N;
    vector<int> b(N);
    for (auto& x : b) {
        cin >> x;
    }

    vector<int> ans;
    int i;
    for (i = 0; i < N; ++i) {
        int d = liner_search(b);
        if (d != -1) {
            ans.push_back(b[d]);
            b.erase(b.begin() + d);
        } else {
            break;
        }
    }
    if (i == N) {
        reverse(all(ans));
        for (auto& x: ans) {
            cout << x << endl;
        }
    } else {
        cout << -1 << endl;
    }

    /*for (auto& x: ans) {
        cout << x << endl;
    }
    */




        

    return 0;
}