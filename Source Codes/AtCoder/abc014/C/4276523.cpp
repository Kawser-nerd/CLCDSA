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
const int range = 1e6 + 1;

int main(){
    int N;
    cin >> N;
    vector<int> a(N),b(N);
    vector<int> cnt(range,0);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
        cnt[a[i]]++;
        cnt[b[i]+1]--;
    }
    for (int i = 1; i <= range; i++) {
        cnt[i] += cnt[i-1];
    }
    cout << *max_element(all(cnt)) << endl;

    


    return 0;
}