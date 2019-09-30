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

int div(int t) {
    while(t % 2 == 0) {
        t /= 2;
    }
    return t;
}
int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    set<int> s;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        s.insert(div(a[i]));
    }
    cout << s.size() << endl;

    

    return 0;
}