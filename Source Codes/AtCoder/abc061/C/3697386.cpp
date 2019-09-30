#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    long long n, k, a, b, sum;
    cin >> n >> k;
    vector<pair<int, int>> p(n);
    for (int i=0; i<n; ++i){
        cin >> a >> b;
        p[i] = make_pair(a, b);
    }
    // sort int a
    sort(p.begin(), p.end());
    sum = 0;
    for(int i=0; i<n; ++i){
        sum += p[i].second;
        if(sum >= k){
            cout << p[i].first;
            break;
        }
    }
}