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
    int N,K;
    cin >> N >> K;
    vector<int> l(N);
    for (int i = 0; i < N; i++){
        cin >> l[i];
    }
    sort(l.rbegin(),l.rend());
    int sum = 0;
    for (int i = 0; i < K; i++){
        sum += l[i];
    }
    cout << sum << endl;


    return 0;
}