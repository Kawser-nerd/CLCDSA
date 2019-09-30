#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;
#define LL long long 
char d[105][105];

int main(){
    LL n, k;
    LL c;
    LL H, W;
    LL ans = 1e18;
    cin >> n >> k;
    vector<LL> a(n),b(n);
    vector<pair<LL, LL> > E; 
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        E.push_back(make_pair(a[i], b[i]));
    }
    sort(E.begin(), E.end());
    
    for(int i = 0; i < n; i++){
        H = E[i].first;
        W = E[i].second;    
        // cout << H << W << endl;

        k -= W;
        if(k <= 0){
            cout << H << endl;
            return 0;
        }
    }
}