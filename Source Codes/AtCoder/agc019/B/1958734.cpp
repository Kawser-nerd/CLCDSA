#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int cnt[26] = {0};

int main(){
    string s;
    cin >> s;
    ll ans = 1;
    for (int i = 0; i < s.size(); ++i) {
        ans += i - cnt[s[i] - 'a'];
        //cout << ans << endl;
        cnt[s[i] - 'a']++;
    }
    cout << ans << endl;
}