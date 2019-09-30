#include <iostream>
#include <cstdlib>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
    long long r;
    while (b != 0) {
        r = a % b;
        a = b; 
        b = r;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int main()
{
    int n;
    long long ans=0;
    cin >> n;
    vector<long long> t(n);
    for(int i=0; i<n; ++i){
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    if(n == 1){
        ans = t[0];
    }
    else {
        for(int i=1; i<n; ++i){
            if(i == 1){
                ans = lcm(t[0], t[1]);
            }
            else {
                ans = lcm(ans, t[i]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}