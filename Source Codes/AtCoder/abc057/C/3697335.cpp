#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    long long n, tmp_a, tmp_b;
    cin >> n;
    int max = sqrt(n) + 1;
    int a, b, fab, ans;
    ans = 150;
    for(int i=1; i<=max; ++i){
        if(n % i != 0){
            continue;
        }
        tmp_a = (long long)i;
        tmp_b = (long long)(n) / (long long)i;
        a = (int)((to_string(tmp_a)).length());
        b = (int)((to_string(tmp_b)).length());
        fab = (a >= b) ? a : b;
        ans = min(ans, fab);
    }
    cout << ans << endl;
}