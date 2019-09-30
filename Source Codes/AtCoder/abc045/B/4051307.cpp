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
    map<char,string> m;
    map<char,int> cnt;
    string s;
    for (char i = 'a'; i <= 'c'; i++){
        cin >> s;
        m[i] = s;
        cnt[i] = 0;
    }
    char ans;
    char t = m['a'][0];
    cnt['a']++;
    while(1){
        if (cnt[t] == m[t].size()) {
            ans = t;
            break;
        }
        t = m[t][cnt[t]++];
    }


    std::locale l = std::locale::classic();
    cout << toupper(ans,l) << endl;


        


    return 0;
}