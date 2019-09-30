#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int x, y, z, k, s;
    int ans = 0;
    cin >> k >> s;
    for (int i=0; i<=k; ++i){
        for (int j=0; j<=k; ++j){
            x = i;
            y = j;
            z = s - x - y;
            if(0 <= z && z <= k){
                ans++;
            }
        }
    }
    cout << ans << endl;
}