#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, c, k, ans, itr, lim;
    ans = 0;
    itr = 0;
    cin >> n >> c >> k;
    vector<int> t(n);
    for(int i=0; i<n; ++i){
        cin >> t[i];
    }
    // sort
    sort(t.begin(), t.end());
    // greedy
    while(itr < n){
        ans++;
        lim = t[itr] + k;
        for(int i=0; i<c; ++i){
            if(itr + i < n && t[itr + i] <= lim){
                if(i == c-1){
                    itr = itr + i + 1;
                }
                continue;
            }
            else {
                itr = itr + i;
                break;
            }
        }
    }
    cout << ans << endl;
}