#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int

using namespace std;

typedef pair<int, int> P;

const int inf = 1e15;

signed main(){
    int n, l;
    cin >> n >> l;
    string s;
    cin >> s;

    int tab = 1;
    int ans = 0;
    for(char c: s){
        if(c == '+'){
            tab++;
        }
        if(c == '-'){
            tab--;
        }
        if(tab > l){
            tab = 1;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}