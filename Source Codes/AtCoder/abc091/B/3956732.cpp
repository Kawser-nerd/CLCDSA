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
    int N,M;
    map<string,int> m;
    cin >> N;
    vector<string> s(N);
    for (int i = 0; i < N; i++){
        cin >> s[i];
        m[s[i]] = 0;
    }
    cin >> M;
    vector<string> t(M);
    for (int i = 0; i < M; i++){
        cin >> t[i];
        m[t[i]] = 0;
    }

    for (int i = 0;  i < N; i++){
        m[s[i]]++;
    }
    for (int i = 0; i < M; i++){
        m[t[i]]--;
    }
    int maxv = 0;
    for (int i = 0; i < N; i++){
        maxv = max(maxv,m[s[i]]);
    }
    cout << maxv << endl;
    /*
    if (maxv < 0){
        cout << 0 << endl;
    } else {
        cout << maxv << endl;
    }
    */
    



    return 0;
}