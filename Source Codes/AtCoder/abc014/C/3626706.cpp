#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <queue>
using namespace std;

int main()
{
    int n, a, b, ans;
    ans = 0;
    cin >> n;
    vector<int> p(1000003, 0);
    vector<int> s(1000003, 0);
    for(int i=0; i<n; ++i){
        cin >> a >> b;
        p[a]++;
        p[b+1]--;
    }
    for(int i=0; i<=1000001; ++i){
        if(i == 0){
            s[i] = p[i];
        }
        else {
            s[i] = s[i-1] + p[i];
        }
        //cout << i << ":" << s[i] << endl;
    }
    for(int i=0; i<=1000001; ++i){
        ans = max(ans, s[i]);
    }
    cout << ans << endl;
}