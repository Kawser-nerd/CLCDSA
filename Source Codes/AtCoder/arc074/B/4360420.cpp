#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <array>
#include <bitset>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long lint;

lint solve(lint n, vector<lint> &a){
    priority_queue<lint, vector<lint>, greater<lint>> queue_1;
    priority_queue<lint> queue_2;
    vector<lint> sum_fst(n+1, 0);
    vector<lint> sum_snd(n+1, 0);
    lint num, sum, ret;
    for (int i=0; i<n; ++i){
        queue_1.push(a[i]);
        sum_fst[0] += a[i];
    }
    for (int i=1; i<n+1; ++i){
        queue_1.push(a[n + i - 1]);
        sum_fst[i] = sum_fst[i-1];
        sum_fst[i] += a[n + i - 1];
        num = queue_1.top();
        queue_1.pop();
        sum_fst[i] -= num;
    }
    for (int i=0; i<n; ++i){
        queue_2.push(a[3 * n - i - 1]);
        sum_snd[n] += a[3 * n - i - 1];
    }
    for (int i=1; i<n+1; ++i){
        queue_2.push(a[2 * n - i]);
        sum_snd[n - i] = sum_snd[n - i + 1];
        sum_snd[n - i] += a[2 * n - i];
        num = queue_2.top();
        queue_2.pop();
        sum_snd[n - i] -= num;
    }
    ret = -10000000000000000;
    for (int i=0; i<=n; ++i){
        ret = max(ret, sum_fst[i] - sum_snd[i]);
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    lint n;
    cin >> n;
    vector<lint> a(3 * n);
    for (int i=0; i<3 * n; ++i){
        cin >> a[i];
    }
    cout << solve(n, a) << endl;
    return 0;
}