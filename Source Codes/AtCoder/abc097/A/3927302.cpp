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
    bool ok = false;
    if (abs(a-c) <= d){
        ok = true;
    } else if (abs(a-b) <= d && abs(b-c) <= d){
        ok = true;
    }
    if (ok){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
}