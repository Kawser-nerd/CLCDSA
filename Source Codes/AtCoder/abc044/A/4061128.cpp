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
    int N,K,X,Y;
    cin >> N >> K >> X >> Y;
    int ans = 0;
    if (N <= K){
        ans += X*N;
    } else {
        ans += X*K+(N-K)*Y;
    }
    cout << ans << endl;



    return 0;
}