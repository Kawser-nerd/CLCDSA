using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <iostream>
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
    ll N;
    cin >> N;
    ll cp = N;
    int sum = 0;
    while(N){
        sum += N % 10;
        N /= 10;
    }
    if (cp % sum == 0){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
} ./Main.cpp:1:17: warning: using directive refers to implicitly-defined namespace 'std'
using namespace std;
                ^
1 warning generated.