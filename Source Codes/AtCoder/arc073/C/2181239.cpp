#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

//#define LOCAL 0
//#ifdef LOCAL
//#define DEBUG(s) cout << (s) << endl
//#define dump(x)  cerr << #x << " = " << (x) << endl
//#define BR cout << endl;
//#else
//#define DEBUG(s) do{}while(0)
//#define dump(x) do{}while(0)
//#define BR
//#endif


//??
typedef long long int ll;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007
//????????
ll part1(vector<pair<ll,ll>> xy){
    vector<ll> B,R;
    for(auto e : xy){
        B.push_back(e.first);
        R.push_back(e.second);
    }
    sort(all(B));
    sort(all(R));
    return (B.back() - B.front()) * (R.back() - R.front());
}
ll part2(vector<pair<ll,ll>> xy){
    sort(all(xy));
    ll Bmax = xy.back().first;
    ll Bmin = xy.front().first;
    ll Rmax = -1;
    ll Rmin = INFl;
    rep(i,0,xy.size()){
        Rmax = max({Rmax,xy[i].first,xy[i].second});
        Rmin = min({Rmin,xy[i].first,xy[i].second});
    }
    priority_queue<ll> pq;
    rep(i,0,xy.size()){
//        if(xy[i].second <= Bmax){
//            swap(xy[i].first,xy[i].second);
//        }
        //???????
        ll tmpBmax = max(Bmax,xy[i].second);
        ll tmpBmin;
        if(i == 0){
            tmpBmin = INFl;
        }else{
            tmpBmin = -pq.top();
        }
        if(i == xy.size() - 1){
//            tmpBmin = xy[i].second;
            tmpBmin= min({tmpBmin,xy[i].second});
        }else{
            tmpBmin= min({tmpBmin,xy[i].second,xy[i+1].first});
        }
        if(tmpBmax - tmpBmin <= Bmax - Bmin){
            Bmax = tmpBmax;
            Bmin = tmpBmin;
            swap(xy[i].first,xy[i].second);
        }
        pq.push(-xy[i].first);
    }
    vector<ll> B,R;
    for(auto e : xy){
        B.push_back(e.first);
        R.push_back(e.second);
    }
    sort(all(B));
    sort(all(R));
    return (B.back() - B.front()) * (R.back() - R.front());
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<pair<ll,ll>> xy;

    rep(i,0,N){
        ll x,y;
        cin >> x >> y;
        if(x > y) swap(x,y);
        xy.emplace_back(x,y);
    }
//    cout << part1(xy) << endl;
//    cout << part2(xy) << endl;

    cout << min(part1(xy),part2(xy)) << endl;

    return 0;
}