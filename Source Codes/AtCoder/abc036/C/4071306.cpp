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
    vector<int> a(N);
    map<int,int> m;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        m[a[i]] = 0;
    }

    int cnt = 0;
    for (auto itr = m.begin(); itr != m.end(); ++itr) {
        itr -> second = cnt++;
    }

    for (int i = 0; i < N; i++){
        cout << m[a[i]] << endl;
    }





    return 0;
}