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
    int N;
    cin >> N;
    ll sum = 0;
    const int d = N;
    int t[8] = {0};
    vector<string> ans;
    for (int i = 0; i < pow(3,d); i++){
        int x = i;
        for (int k = 0; k < d; k++){
            t[k] = x % 3;
            x /= 3;
        }
        string t1;
        for (int k = 0; k < d; k++){
            if (t[k] == 0){
                t1 += 'a';
            } else if (t[k] == 1){
                t1 += 'b';
            } else {
                t1 += 'c';
            }
        }
        ans.push_back(t1);
    }
    sort(all(ans));

    for (int i = 0; i < pow(3,d); i++){
        cout << ans[i] << endl;
    }
    return sum;

    return 0;
}