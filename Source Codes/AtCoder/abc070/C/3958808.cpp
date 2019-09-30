#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b){
    long long r;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long lcm(long long a, long long b){
    return (a / gcd(a, b)) * b;
}

int main()
{
    int n;
    cin >> n;
    vector<long long> t(n);
    for (int i=0; i<n; ++i){
        cin >> t[i];
    }
    long long ans = t[0];
    for (int i=1; i<n; ++i){
        ans = lcm(ans, t[i]);
    }
    cout << ans << endl;
    return 0;
}