#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    // -- solve --
    int ans = 0;
    for (int i=0; i<n-1; ++i){
        if(a[i] == a[i+1]){
            ans++;
            a[i+1] = 10001;
        }
    }
    cout << ans << endl;
    return 0;
}