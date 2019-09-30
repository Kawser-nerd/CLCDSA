using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <iostream>
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
#define all(x) (x).begin(),(x).end()

void solve(){

}
int main(){
    string S;
    cin >> S;
    int cnt[200] = {};
    for (int i = 0; i < (int)S.size(); i++){
        cnt[(int)S[i]]++;
    }
    string ans = "None";
    for (int i = (int)'a'; i <= (int)'z'; i++){
        if (cnt[i] == 0){
            ans = (char)i;
            break;
        }
    }
    cout << ans << endl;

    return 0;
} ./Main.cpp:1:17: warning: using directive refers to implicitly-defined namespace 'std'
using namespace std;
                ^
1 warning generated.