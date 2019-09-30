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

void solve(){

}
int calc(int x){
    int ret = 0;
    while(x % 2 == 0) {
        x /= 2;
        ++ret;
    }
    return ret;
}

int main(){
    int N;
    cin >> N;
    vector<ll> a(N,0);
    ll sum = 0;
    for (int i = 0; i < N; i++){
        cin >> a[i];
        sum += calc(a[i]);
    }
    cout << sum << endl;


    return 0;
}