#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i=0; i<N; i++) cin >> a[i];
    sort(a.begin(), a.end());
    map<int, bool> mp;

    int ans = 0;
    for(int i=0; i<N; i++){
        if(!mp[a[i]])
            ans++;
        long long b = a[i];
        while(b <= 1000000000){
            mp[b] = true;
            b *= 2;
        }
    }
    cout << ans << endl;
    return 0;
}