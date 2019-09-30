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
    int a,b,c,d,ans;
    cin >> a >> b >> c >> d;
    if (a * b == c * d){
        ans = a*b;
    } else {
        if (a * b > c * d){
            ans = a * b;
        } else {
            ans = c * d;
        } 
    }

    cout << ans << endl;

    return 0;
}