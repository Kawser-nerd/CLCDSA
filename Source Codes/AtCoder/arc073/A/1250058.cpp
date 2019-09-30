#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long t, total = 0, t_i, t_prev = 0;
    cin >> n >> t;
    cin >> t_prev;
    for (int i = 1; i < n; ++i) {
        cin >> t_i;
        if (t_i - t_prev < t) total += t_i - t_prev;
        else total += t;
        t_prev = t_i;
    }
    total += t; // last
    
    cout << total << endl;
    
    return 0;
}