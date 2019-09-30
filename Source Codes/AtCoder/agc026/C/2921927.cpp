#include <map>
#include <iostream>
using namespace std;
typedef pair<string,string> pa;
int main() {
    int n;
    long long ans = 0;
    string s;
    map<pa,int> mp;
    cin>>n>>s;
    for(int i = 0;i < 1 << n;i ++) {
        string a = "";
        string b = "";
        for(int j = 0;j < n;j ++) {
            if(i >> j & 1)a += s[j];
            else b += s[j];
        }
        mp[pa(a,b)] ++;
    }
    for(int i = 0;i < 1 << n;i ++) {
        string a = "";
        string b = "";
        for(int j = 0;j < n;j ++) {
            if(i >> j & 1)a += s[n * 2 - 1 - j];
            else b += s[n * 2 - 1 - j];
        }
        ans += mp[pa(a,b)];
    }
    cout<<ans;
}