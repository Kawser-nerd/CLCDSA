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
    long long ans = 0;
    vector<long long> a(n);
    vector<long long> t(n);
    for (int i=0; i<n; ++i){
        cin >> t[i] >> a[i];
    }
    // --- solve ---
    long long a_tmp;
    long long t_tmp;
    for (int i=0; i<n; ++i){
        if(i == 0){
            a_tmp = a[0];
            t_tmp = t[0];
        }
        else {
            long long a_d = a_tmp / a[i] + ((a_tmp % a[i] == 0) ? 0 : 1);
            long long t_d = t_tmp / t[i] + ((t_tmp % t[i] == 0) ? 0 : 1);
            long long max_v = max(a_d, t_d);
            a_tmp = a[i] * max_v;
            t_tmp = t[i] * max_v;
            // cout << i << " -> " << a_tmp << " " << t_tmp << endl;
        }
    }
    ans = a_tmp + t_tmp;
    cout << ans << endl;
    return 0;
}