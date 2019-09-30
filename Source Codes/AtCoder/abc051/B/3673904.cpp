#include <iostream>
#include <cstdlib>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int k, s, s_p;
    long long ans;
    ans = 0;
    cin >> k >> s;
    for(int x=0; x<=k; ++x){
        s_p = s - x;
        if(0 <= s_p && s_p <= 2 * k){
            for(int y=0; y<=k; ++y){
                if(0 <= s_p - y && s_p - y <= k){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}