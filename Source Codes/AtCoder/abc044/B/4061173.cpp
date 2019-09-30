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
    string w;
    cin >> w;
    map<char,int> cnt;
    for (char i = 'a'; i <= 'z'; i++){
        cnt[i] = 0;
    }
    for (int i = 0; i < (int)w.size(); i++){
        cnt[w[i]]++;
    }

    bool ok = true;
    for (char i = 'a'; i <= 'z'; ++i) {
        if (cnt[i] % 2 != 0){
            ok = false;
        }
    }
    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}