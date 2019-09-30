#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

map<long long, bool> mp;
priority_queue<long long, vector<long long> > pq;

int main()
{
    /*
     * ??????????????2??????priority_queue???
     * priority_queue?????2?????
     */
    long long N, A, rt = 1;
    cin >> N;
    while (N--) {
        cin >> A;
        if (mp[A]) {
            mp[A] = false;
            pq.push(A);
        } else {
            mp[A] = true;
        }
    }
    if (pq.size() > 1) {
        rt *= pq.top();
        pq.pop();
        rt *= pq.top();
    } else {
        rt = 0;
    }
    cout << rt << endl;
    return 0;
}