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
    int a,b;
    cin >> a >> b;
    string ans;
    if (a == 1 || b == 1){
        if (a == 1 && b == 1){
            ans = "Draw";
        } else if (a == 1){
            ans = "Alice";
        } else {
            ans = "Bob";
        }
    } else {
        if (a == b){
            ans = "Draw";
        } else if (a > b){
            ans = "Alice";
        } else {
            ans = "Bob";
        }
    }
    cout << ans << endl;



    return 0;
}