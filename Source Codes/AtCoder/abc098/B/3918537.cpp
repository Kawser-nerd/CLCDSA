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
    string s;
    cin >> N;
    cin >> s;
    int ans = 0;
    for (int i = 1; i < N; i++){
        map<char,int> m1,m2;
        for (char k = 'a'; k <= 'z'; k++){
            m1.insert(make_pair(k, 0));
            m2.insert(make_pair(k, 0));
        }
        for (int k = 0; k < i; k++){
            m1[s[k]]++;
        }
        for (int k = i; k < N; k++){
            m2[s[k]]++;
        }
        int cnt = 0;
        for (char k = 'a'; k <= 'z'; k++){
            if (m1[k] >= 1 && m2[k] >= 1){
                cnt++;
            }
        }
        ans = max(ans,cnt);
    }
    cout << ans << endl;

    return 0;
}