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
    int A,B;
    cin >> A >> B;
    int ans = 0;
    for (int i = A; i <= B; i++){
        string t;
        t = to_string(i);
        if (t[0] == t[4] &&  t[1] == t[3]){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}