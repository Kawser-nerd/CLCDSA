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
    int N = 12;
    vector<string> s(N);
    int cnt = 0;
    for (int i = 0; i < N; i++){
        cin >> s[i];
        for (int k = 0; k < (int)s[i].size(); k++){
            if (s[i][k] == 'r') {
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;


    return 0;
}