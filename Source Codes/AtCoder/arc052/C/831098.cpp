#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
template<typename T>
using reversed_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T> >;
typedef unsigned long long int ull;
typedef long long int ll;
#define rep(i,a,b) for (ll i=(a); i<(b); i++)
typedef pair<int,int> PII;
typedef pair<int,pair<int,int> > PIII;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
typedef vector<VL> MATRIX;
typedef vector<char> VC;
typedef vector<VC> CMATRIX;

ll mpow(ll x, ll y, ll m) {
    x %= m;
    ll result = 1;
    while (y > 0) {
        if (y & 1) result = (result * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }
    return result;
}

// mod inverse ?m????x???
ull minverse(ull x, ull m) {
    return mpow(x, m-2, m);
}


// ??? O(n)
ll c (ll n, ll k, ll m) {
    static ll memo[1000][1000];
    if (memo[n][k]!=0) return memo[n][k];
    else if(n==k)      return memo[n][k]=1;
    else if(k==0)      return memo[n][k]=1;
    else               return memo[n][k]=(c(n-1,k-1,m)+c(n-1,k,m))%m;
}

// ??? O(n+k)
ll c2 (ll n, ll k, ll m){
    if(n==0 && k==0) return 1;
    if(k>n) return 0;
    if(n<=0) return 0;
    if(n==k) return 1;

    ll res=1;
    for(ll x=n-k+1; x<=n; x++){
        res = res*x;
        if(m!=-1) res %= m;
    }
    for(ll x=1; x<=k; x++) {
        if(m==-1) res = res/x;
        else      res = (res*minverse(x,m)) %m;
    }
    return res;
}

// ????? O(n)? c3_init ????O(1)?c3???
ll  fact[400000];
ll rfact[400000];
void c3_init(ll m){
    fact[0]  = rfact[0] = 1;
    for(int i=1; i<400000; i++){
        fact[i] = (fact[i-1]*i)%m;
        rfact[i] = minverse(fact[i],m);
    }
}
ll c3(ll n, ll k, ll m){
    return (((fact[n] * rfact[k])%m) * rfact[n-k])%m;
}


// ????? O(n+k)
ll hcomp(ll n, ll k, ll m) {
    return c(k+n-1,k,m);
}

// ??????? O(n)
ll hcomp2(ll n, ll k, ll m) {
    //return c(k+n-1,k,m);
    ll res=1;
    for (ll j=1; j<n; j++){
        res = (res * (k+j)) % m;
        res = (res * minverse(j, m)) % m;
    }
    return res;
}

//=========== Union find ============================
class UnionFind {
    public:
        int n;
        vector<int> par;
        vector<int> num;

        UnionFind(int n){ // [0 n)?union find
            this->n = n;
            this->par.resize(n);
            this->num.resize(n,1);
            for(int i=0;i<n;i++){
                this->par[i] = i;
            }
        }

        int root(int i) {
            if(par[i]==i) return i;
            else return par[i]=root(par[i]);
        }

        bool same(int i, int j){
            return root(i)==root(j);
        }

        void unite(int i,int j){
            int t = root(i);
            int k = root(j);

            if(t==k) return;

            par[t] = k;
            num[k] += num[t];
        }

        int size(int i){
            return num[root(i)];
        }
};

//=========== ???????? ============================

template <typename T>
class SegTree {
    private:
        int _n;
        T _init_val;
        vector<T> _data;
        function<T(T,T)> _f;

        T _query(int a, int b, int k, int l, int r) {
            // [a b)?[l r]??????
            if (r<=a || b <=l) return _init_val;

            // [a b)?[l r]???
            if (a<=l && r<=b) return _data[k];

            T vl = _query(a,b, k*2+1, l, (l+r)/2);
            T vr = _query(a,b, k*2+2, (l+r)/2, r);

            return _f(vl,vr);
        }

    public:
        SegTree (int n, T init_val, function<T(T, T)> f) {
            _init_val = init_val;
            _n = 1;
            _f = f;

            while(_n < n) _n *= 2;
            _data.resize(2*_n, init_val);
        }

        T get (int k) {
            return _data[k + _n -1];
        }

        void update(int k, T a) {
            k += _n-1;
            _data[k] = a;
            while(k>0){
                k = (k-1)/2;
                _data[k] = _f( _data[k*2+1], _data[k*2+2] );
            }
        }

        // [a b)????f???
        T query(int a,int b) {
            return _query(a,b,0,0,_n);
        }

        // ??????????????x???????????
        int lower_bound (T x) {
            return _lower_bound(x,0);
        }

        int _lower_bound (T x, int k){
            if (k >= _n-1){
                return k- (_n-1); // ?
            } else if (_data[k] < x) {
                return _n;        // ????
            } else if (x <= _data[k*2+1]){
                return _lower_bound(x,k*2+1);
            } else {
                return _lower_bound(x- _data[k*2+1] ,k*2+2);
            }
        }
};

// (1 + a + a^2 + a^3 ... + a^(n-1) ) % m
ll modpowsum(ll a, ll n, ll m) {
    if(n==0){
        return 0;
    } else if(n%2==1) {
        return (1+modpowsum(a,n-1,m)*a) % m;
    } else{
        ll t = modpowsum(a,n/2,m);
        return (t+t*mpow(a,n/2,m)) % m;
    }
}

// ?? 1-3, 5-7, 10-199
// ? 2-6???
// 1-7, 10-199
class Block {
    public:
        vector< pair<int,int> > block;

        void add(int l, int r) {
            // ???????
            auto it = lower_bound(begin(this->block),end(this->block),make_pair(l,r));
            auto jt = it; jt--;

            //if(it!=block.end()){
            //    cout<<"it: ("<<it->first<<"-"<<it->second<<endl;
            //}

            // 1.?????????????
            if(it != block.end() && r >= it->first){
                it->first  = min(l,  it->first);
                it->second = max(r, it->second);

                // ????????????????
                auto jt = it; jt--;
                if(it!=block.begin() && jt->second >= it->first){
                    it->first = min(it->first, jt->first);
                    it->second = max(it->second, jt->second);
                    this->block.erase(jt);
                }
            }
            // 2.?????????????
            else if(it!=block.begin() && jt->second >= l){
                jt->first = min(jt->first, l);
                jt->second = max(jt->second, r);
            }
            // 3.??????
            else {
                block.insert(it,make_pair(l,r));
            }
        }
};

// ?????
    template < class BidirectionalIterator >
bool next_combination ( BidirectionalIterator first1 ,
        BidirectionalIterator last1 ,
        BidirectionalIterator first2 ,
        BidirectionalIterator last2 )
{
    if (( first1 == last1 ) || ( first2 == last2 )) {
        return false ;
    }
    BidirectionalIterator m1 = last1 ;
    BidirectionalIterator m2 = last2 ; --m2;
    while (--m1 != first1 && !(* m1 < *m2 )){
    }
    bool result = (m1 == first1 ) && !(* first1 < *m2 );
    if (! result ) {
        while ( first2 != m2 && !(* m1 < * first2 )) {
            ++ first2 ;
        }
        first1 = m1;
        std :: iter_swap (first1 , first2 );
        ++ first1 ;
        ++ first2 ;
    }
    if (( first1 != last1 ) && ( first2 != last2 )) {
        m1 = last1 ; m2 = first2 ;
        while (( m1 != first1 ) && (m2 != last2 )) {
            std :: iter_swap (--m1 , m2 );
            ++ m2;
        }
        std :: reverse (first1 , m1 );
        std :: reverse (first1 , last1 );
        std :: reverse (m2 , last2 );
        std :: reverse (first2 , last2 );
    }
    return ! result ;
}

    template < class BidirectionalIterator >
bool next_combination ( BidirectionalIterator first ,
        BidirectionalIterator middle ,
        BidirectionalIterator last )
{
    return next_combination (first , middle , middle , last );
}
long long bit_count(unsigned long long i)
{
    i = i - ((i >> 1) & 0x5555555555555555);
    i = (i & 0x3333333333333333) + ((i >> 2) & 0x3333333333333333);
    return (((i + (i >> 4)) & 0x0F0F0F0F0F0F0F0F) * 0x0101010101010101) >> 56;
}

const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

class SuffixArray {
    public:
        string s; // ?????
        vector<int> sa;  // suffix array??     i -> sa[i]
        vector<int> rsa; // suffix array?? sa[i] -> i
        vector<int> lcp; // Longest Common Prefix Array?????
        SegTree<int> st_lcp; // lcp?????????

        // O(n log n)
        SuffixArray(string s): s(s), st_lcp(s.size()+1,1<<29,[](int a,int b){return min(a,b);}) {
            sa = construct_sa();
            lcp = construct_lcp();

            // sa?????
            rsa = vector<int>(s.size()+1,0);
            for(int i=0;i<sa.size();i++){
                rsa[sa[i]]=i;
            }

            // ???????????? O(n log n)
            for(int i=0;i<lcp.size();i++){
                st_lcp.update(i,lcp[i]);
            }
        }

        // (rank[i],rank[i+k])?(rank[j], rank[j+k])???
        bool compare_sa(int i, int j, int k, int n, vector<int> &rank){
            if(rank[i] != rank[j]){
                return rank[i] < rank[j];
            }else{
                int ri = i+k<=n ? rank[i+k] : -1;
                int rj = j+k<=n ? rank[j+k] : -1;
                return ri<rj;
            }
        }

        // O(n)
        vector<int> construct_sa(){
            int n = s.size();
            vector<int> res(n+1,0);
            vector<int> rank(n+1,0);
            vector<int> tmp(n+1,0);

            // ????????????????
            for (int i=0; i<=n; i++){
                res[i] = i;
                rank[res[i]] = i<n ? s[i] : -1;
            }

            // k????????????????????2k????????
            for(int k=1;k<=n;k*=2){
                auto f=  [&](int i, int j){ return this->compare_sa(i,j,k,n,rank);};
                sort(begin(res),end(res),f);
                tmp[res[0]] = 0;
                for(int i=1;i<=n;i++){
                    tmp[res[i]] = tmp[res[i-1]] + (f(res[i-1],res[i])?1:0);
                }
                rank=tmp;
            }

            return res;
        }

        // O(n)
        // ????lcp???
        vector<int> construct_lcp(){
            int n = s.size();
            vector<int> rank(n+1,0);
            vector<int> res(n+1,0);
            for(int i=0;i<=n;i++) rank[sa[i]]=i;

            int h = 0;
            res[0]=0;
            for(int i=0;i<n;i++){
                int j = sa[rank[i]-1];
                if(h>0) h--;
                for(; j+h<n && i+h<n; h++){
                    if(s[j+h] != s[i+h])
                        break;
                }

                res[rank[i]-1]=h;
            }
            return res;
        }

        void dump() {
            int n= s.size();
            cout<<"# SuffixArray dump"<<endl;
            cout<<"s = "<<s<<endl;
            cout<<"----------------------"<<endl;
            cout<<" i sa[i] lcp[i]  s[sa[i]...]"<<endl;
            for(int i=0;i<=n;i++){
                printf("%2d%6d%7d  %s\n",i,sa[i],lcp[i],s.substr(sa[i]).c_str());
            }
        }

        // O(1)
        // ?????s[i...]???????
        int getRank(int i){
            return rsa[i];
        }

        // O(log n)
        // suffix array ?????????pat?s???????
        // ????????-1???
        int find(const string &pat){
            int a=0, b=s.size();
            while(b-a>1){
                int c = (a+b)/2;
                if(s.compare(sa[c], pat.size(), pat) < 0) a = c;
                else b = c;
            }

            if(s.compare(sa[b],pat.size(),pat)==0){
                return sa[b];
            }else{
                return -1;
            }
        }

        // ???s? s[i..] ? s[j..] ???????????
        // O(log n)
        int prefixCommonLength(int i, int j){
            if(i==j)  return s.size()-i;

            i = rsa[i];
            j = rsa[j];

            return st_lcp.query(min(i,j), max(i,j));
        }
};
//============================================
struct State {
    int id, numb, cost;
};
bool operator < (const State &l, const State &r) {
    if(l.cost == r.cost)
        return l.numb < r.numb;
    else
        return l.cost < r.cost;
}
bool operator > (const State &l, const State &r) {
    if(l.cost == r.cost)
        return l.numb > r.numb;
    else
        return l.cost > r.cost;
}

ll N,M;
vector<vector<vector<int>>> edge; // edge[ 0:A, 1:B ][ id ] = { set of next_id }
vector<vector<int>> dp; // dp[ id ][ # of edge B ] = cost
reversed_priority_queue<State> q;
const int INF=1<<30;

signed main(){
    cin>>N>>M;
    edge.resize(2, vector<vector<int>>(N));
    dp.resize(N, vector<int>(1,INF)); // # of edge B ???????????

    rep(i,0,M){
        int c,a,b;
        cin>>c>>a>>b;
        edge[c][a].push_back(b);
        edge[c][b].push_back(a);
    }

    // dijkstra
    q.push({0,0,0});
    dp[0][0] = 0;
    while(!q.empty()){
        auto t = q.top(); q.pop();
        if(dp[t.id][t.numb] < t.cost) continue;

        // ??????
        rep(type,0,2) for(auto next_id : edge[type][t.id]) {
            State s;
            s.id = next_id;
            s.numb = t.numb + (type==0 ? 0 : 1);
            s.cost = t.cost + (type==0 ? 1 : t.numb+1);

            if(s.numb >= N) continue;
            ll p = *min_element(dp[s.id].begin(), dp[s.id].begin() + min<int>(s.numb, dp[s.id].size())); // 0 ? t.numb-1 ?????????
            if(s.cost >= p) continue; // numb?cost?????????

            if(s.numb+1 > dp[s.id].size()) {
                dp[s.id].resize(s.numb+1,INF); // ???????
            }
            if(dp[s.id][s.numb] <= s.cost) continue; // ??????????????

            dp[s.id][s.numb] = s.cost;

            q.push(s);
        }
    }

    rep(id,0,N){
        cout<< *min_element(dp[id].begin(), dp[id].end()) << endl;
    }

    return 0;
}