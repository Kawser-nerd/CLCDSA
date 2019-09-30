#include<iostream>
using namespace std;
typedef long long ll;

ll p(int x){
    ll ret = 1;
    while(x-- > 0)  ret *= 10;
    return ret;
}

int main(){
    string s;
    cin >> s;

    int n = s.length();

    ll ans = 0;

    for(int i = 0; i < n; i++){
        string l = s.substr(0, n-1-i);
        string r = s.substr(n-i);

        int left = 1, right = 0;
        if(l != "") left = stoi(l)+1;
        if(r != "") right = stoi(r);
// cout << left << " " << right;
        if(s[n-1-i] >= '1'){
            ans += (ll)left * p(i);
            if(s[n-1-i] == '1'){
                ans -= p(i)-right-1;
            }
        }else if(s[n-1-i] == '0'){
            left--;
            ans += (ll)left * p(i);
        }
// cout << "->" << ans << endl;
    }

    cout << ans << endl;

    return 0;
}