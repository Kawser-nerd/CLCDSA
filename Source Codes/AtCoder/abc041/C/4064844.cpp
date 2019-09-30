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
    vector<pair<int,int>> a(N);
    int x;
    for (int i = 0; i < N; i++){
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a.rbegin(),a.rend());
    for (int i = 0; i < N; i++){
        cout << a[i].second << endl;
    }

    

    return 0;
}