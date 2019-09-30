#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const pair<long long, long long> &lhs,  const pair<long long, long long> &rhs) {
    return lhs.second > rhs.second;
}

int main()
{
    int N;
    cin >> N;
    long long T = 0;
    long long TMax = 0;
    vector<pair<long long, long long>> before(N);
    vector<pair<long long, long long>> after(N);
    
    for (int i=0; i<N; i++) {
        long long a, b;
        cin >> a >> b;
        if (a < b) {
            before[i] = make_pair(a, b);
            after[i] = make_pair(0, 0);
        } else {
            before[i] = make_pair(0, 0);
            after[i] = make_pair(a, b);
        }
    }
    sort(before.begin(), before.end());
    sort(after.begin(), after.end(), comp);
    
    for (int i=0; i<N; i++) {
        T += before[i].first;
        if (TMax < T) {
            TMax = T;
        }
        T -= before[i].second;
    }
    for (int i=0; i<N; i++) {
        T += after[i].first;
        if (TMax < T) {
            TMax = T;
        }
        T -= after[i].second;
    }
    cout << TMax << endl;
    
    return 0;
}