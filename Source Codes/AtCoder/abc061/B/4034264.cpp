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
int main(){
    int N,M;
    cin >> N >> M;
    vector<int> a(M),b(M),cnt(N);
    for (int i = 0; i < M; i++){
        cin >> a[i] >> b[i];
        cnt[--a[i]]++;
        cnt[--b[i]]++;
    }

    for (int i = 0; i < N; i++){
        cout << cnt[i] << endl;
    }



    return 0;
}