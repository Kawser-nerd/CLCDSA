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
#define INF (1 << 30)
#define INFl (ll)5e15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007
//????????
struct BIT{
    vector<int> bit;
    int n;
    /*
     * 1 ~ n???BIT???
     */
    BIT(int n){
        bit.resize(n+1,0);
        this->n = n;
    }
    int sum(int i){
        int s = 0;
        while(i > 0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    void add(int i,int x){
        while(i <= n){
            bit[i] += x;
            i += i & -i;
        }
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> a,b,v;
    rep(i,0,N){
        int tmp;
        cin >> tmp;
        if(i % 2){
            b.push_back(tmp);
        }else{
            a.push_back(tmp);
        }
    }

    sort(all(a));
    sort(all(b));

    rep(i,0,N){
        if(i % 2){
            v.push_back(b[i/2]);
        }else{
            v.push_back(a[i/2]);
        }
    }




    vector<int> w;
    w = v;
    sort(all(w));
    map<int,int> za;
    rep(i,0,w.size()){
        za[w[i]] = i+1;
    }
    vector<int> zv(N);//???????v

    rep(i,0,N){
        zv[i] = za[v[i]];
    }

//    rep(i,0,zv.size()){
//        cout << zv[i] << " ";
//    }
    int cnt = 0;
    rep(i,0,zv.size()){
        if( (i+1) % 2 != zv[i] % 2 ){
            cnt++;
        }
    }

    cout << cnt / 2 << endl;




    return 0;
}