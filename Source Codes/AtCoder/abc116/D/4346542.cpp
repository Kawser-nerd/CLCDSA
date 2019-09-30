#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <cctype>
#include <list>
#include <limits>
using namespace std;

vector<pair<long long, int>> a;
int cnt[100005];
vector<long long> s;

int main(void){
    int N, K; cin >> N >> K;
    for (int i = 0; i < N; i++){
        int t;
        long long d;
        cin >> t >> d;
        a.push_back({d, t});
    }
    long long ans = 0;
    long long oic = 0;
    long long various = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < K; i++){
        oic += a[N-1-i].first;
        cnt[a[N-1-i].second] += 1;
        if (cnt[a[N-1-i].second] > 1){
            s.push_back(a[N-1-i].first);
        }else{
            various++;
        }
    }
    ans = various * various + oic;
    for (int i = N-1-K; i >= 0; i--){
        if (!cnt[a[i].second] && !s.empty()){
            cnt[a[i].second]++;
            oic += a[i].first;
            oic -= s.back();
            s.pop_back();
            various++;
            ans = ans > various * various + oic ? ans : various * various + oic;
        }
    }
    cout << ans << endl;
}