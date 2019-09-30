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
    string o,e;
    cin >> o >> e;
    string ans;

    if ((int)o.size() == (int)e.size()){
        for (int i = 0; i < (int)o.size(); i++){
            ans += o[i];
            ans += e[i];
        }
    } else {
        for (int i = 0; i < (int)e.size(); i++){
            ans += o[i];
            ans += e[i];
        }
        ans += o[(int)o.size()-1];
    }
    cout << ans << endl;


    return 0;
}