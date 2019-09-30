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
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int left = a+b;
    int right = c+d;
    string ans;
    if (left > right){
        ans = "Left";
    } else if (left == right) {
        ans = "Balanced";
    } else {
        ans = "Right";
    }
    cout << ans << endl;

    return 0;
}