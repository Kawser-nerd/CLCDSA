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
int N;

//????
int getDigit(int n) {
    int ret = 0;
    while (n != 0) {
        ++ret;
        n /= 10;
    }
    return ret;
}

//n?? d???????
//Need setting data type of return value 
int allDec(int n, int d){
    int ret = 0;
    vector<int> t(d,0);
    for (int i = 0; i < pow(n,d); i++){
        int x = i;
        for (int k = 0; k < d; k++){
            t[k] = x % n;
            x /= n;
        }

        bool f[3] = {};
        string num = "";
        for (int k = 0; k < d; k++){
            //t[k] == 0 ~ N-1???????????
            //3,5,7?1??????????
            if (t[k] == 0){
                f[0] = true;
                num += '3';
            } else if (t[k] == 1){
                f[1] = true;
                num += '5';
            } else {
                f[2] = true;
                num += '7';
            }
        }

        if (f[0] && f[1] && f[2]) { 
            if (stoi(num) <= N) {
                ret++;
            }
        }
    }
    return ret;
}
int main(){
    cin >> N;

    int ans = 0;
    for (int i = 3; i <= getDigit(N); ++i) {
        ans += allDec(3, i);
    }
    cout << ans << endl;

    return 0;
}