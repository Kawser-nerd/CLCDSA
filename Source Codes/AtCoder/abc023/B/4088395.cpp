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
    int N;
    cin >> N;
    string s;
    cin >> s;
    string a = "b";

    int ans;

    for (int i = 0; i < (N-1)/2; i++) {
        if (i % 3 == 0) {
            a.insert(0, "a");
            a.insert(a.end(), 'c');
        } else if (i % 3 == 1) {
            a.insert(0, "c");
            a.insert(a.end(), 'a');
        } else {
            a.insert(0, "b");
            a.insert(a.end(), 'b');
        }
    }

    if (N % 2 == 0 || a != s){
        ans = -1;
    } else {
        ans = (N-1)/2;
    }

    cout << ans << endl;



    return 0;
}