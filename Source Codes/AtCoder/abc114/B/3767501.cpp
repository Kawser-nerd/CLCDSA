#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <queue>
#include <stack>
#include <numeric>
#include <cmath>
#include <map>
#include <set>
#define ull unsigned long long
#define ll long long
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    string t = "";
    int ans=1e9;
    for(int i=1;i<s.size()-1;i++){
        t+=s[i-1];
        t+=s[i];
        t+=s[i+1];
        ans=min(ans,abs(stoi(t)-753));
        t="";
    }
    cout << ans << endl;

    return 0;
}