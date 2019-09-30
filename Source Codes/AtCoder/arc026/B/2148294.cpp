#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n;
    cin >> n;

    int sum = -n;
    for(int i = 1; i * i <= n; i++){
        if(n % i != 0){
            continue;
        }
        if(i * i == n){
            sum += i;
            continue;
        }
        sum += i + n / i;
    }

    if(sum == n){
        cout << "Perfect" << endl;
        return 0;
    }
    if(sum > n){
        cout << "Abundant" << endl;
        return 0;
    }
    cout << "Deficient" << endl;

    return 0;
}