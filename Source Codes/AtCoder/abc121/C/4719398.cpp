#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>

typedef long long ll;


using namespace std;
int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<int, int> > vc;
    for (int i=0; i<n; ++i){
        ll a, b;
        cin >> a >> b;
        pair<int, int> p = make_pair(a,b);
        vc.push_back(p);
    }
    sort(vc.begin(), vc.end(), [](auto it, auto jt){return it.first < jt.first;});
    ll ret = 0LL;
    ll ct = 0LL;
    for (auto it=vc.begin(); it!=vc.end(); ++it){
        auto a = it->first;
        auto b = it->second;
        if(ct+b >= m){
            ret += (m - ct)*a;
            break;
        }
        ret += b*a;
        ct += b;
    }
    cout << ret << endl;
    return 0;
}