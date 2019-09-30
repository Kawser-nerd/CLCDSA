#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

long long comb(long long a, long long b) {
    b = min(a - b, b);
    long long r = 1;
    for (long long i = 1; i <= b; i++)
    r = r * (a - b + i) / i;
    return r;
}

int main()
{
    int n, m;
    long long r, tmp, N, answer;
    answer = 0;
    cin >> n >> m;
    
    vector<long long> a(n);
    vector<long long> mod_key;
    vector<long long> sum(n+1);
    map<long long, long long> mod;
    
    // data input
    for (int i=0; i<n+1; ++i){
        if(i != n){
            cin >> a[i];
        }
        if(i == 0){
            sum[0] = 0;
        }
        else {
            sum[i] = sum[i-1] + a[i-1];
        }
        // cout << sum[i] << endl;
    }
    for (int i=0; i<n+1; ++i){
        r = (long)(sum[i] % (long)m);
        if(mod.find(r) == mod.end()){
            mod.insert(make_pair(r, 1));
            mod_key.push_back(r);
        }
        else {
            tmp = mod.at(r);
            mod.erase(r);
            mod.insert(make_pair(r, tmp+1));
        }
    }
    for (auto itr=mod_key.begin(); itr != mod_key.end(); ++itr){
        N = mod.at(*itr);
        if(N >= 2){
            answer += comb(N, 2);
        }
    }
    cout << answer << endl;
}