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
    string s;
    cin >> s;
    string ans;
    for (int i = 0; i < (int)s.size(); i++){
        if (s[i] == 'B'){
            if (!ans.empty()){
                ans.pop_back();
            }
        } else {
            ans.push_back(s[i]);
        }
    }
    cout << ans << endl;



    return 0;
}