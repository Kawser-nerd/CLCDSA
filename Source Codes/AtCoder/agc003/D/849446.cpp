//C++14 (Clang 3.8.0)
     
    #include <vector>
    #include <list>
    #include <map>
    #include <set>
    #include <queue>
    #include <deque>
    #include <stack>
    #include <bitset>
    #include <algorithm>
    #include <functional>
    #include <numeric>
    #include <utility>
    #include <sstream>
    #include <iostream>
    #include <iomanip>
    #include <cstdio>
    #include <cmath>
    #include <cstdlib>
    #include <ctime>
    #include <string>
     
    #include <bitset>
     
     
    typedef long long ll;
    using namespace std;


    const ll MAX_N=1e5+1;
    const ll MAX_S=1e10+10;
    const ll MAX_S_square=3000;

    vector<long long> enumerate_primes(long long a, long long b) {
    bool * memo_all = new bool[b];
    bool * memo_small = new bool[(int)pow(b, 1.0 / 2) + 10];
    for (int i = 0; (long long)i * i < b; i++) memo_small[i] = true;
    for (int i = 0; i < b - a; i++)     memo_all[i] = true;

    for (int i = 2; (long long)i * i < b; i++) {
        if (memo_small[i]) {
            for (int j = 2 * i; (long long)j * j < b; j += i) memo_small[j] = false;
            for (long long j = max(2LL, (a + i - 1) / i) * i; j < b; j += i) memo_all[j - a] = false;
        }
    }


    vector<long long> primes;
    for (long long i = a; i < b; i++) {
        if (memo_all[i-a]) primes.push_back(i);
    }
    delete [] memo_all;
    delete [] memo_small;
    return primes;
    }

    map<ll, ll> prime_factor(ll n,vector<ll> primes) {
        map<ll, ll> res;
        for(ll i = 0; i<primes.size(); i++) {
            if(primes[i] * primes[i] > n) break;
            while(n % primes[i] == 0) {
                ++res[primes[i]];
                n /= primes[i];
            }
        }
        if (n > 1) res[n] += 1;
        return res;
    }
    
vector<ll> normalize_pairlize(ll x,vector<ll> primes){
    vector<ll> np;
    map<ll,ll> pf=prime_factor( x,primes);
    ll n=1,p=1;
    
    for (map<ll,ll>::iterator itr = pf.begin(); itr != pf.end(); itr++){
        ll xx=itr->first,yy=itr->second;
        if (yy >= 3){
            yy%=3;
        }
        if(yy!=0) {n *= (ll)pow(xx,yy); p *= (ll)pow(xx,3 - yy);}
    }
    np.push_back(n);
    np.push_back(p);
    return np;
}     
     
     
     
     
     
    int main(){
        ll N;
        vector<ll> A;
        cin>>N;
        int ans=0;
        for(int i=0;i<N;i++) {ll a; cin>>a; A.push_back(a); }
        vector<ll> primes=enumerate_primes(2,MAX_S_square);
        vector<ll> normal,pair;
        map <ll,ll>nmap,pmap,amap;
        vector<ll> norm1;
        vector<ll> norm1_num;
        bool n1=false;


        for(int i=0;i<N;i++) {
            if(A[i] == 1) {n1=true;continue;}
            if(amap[A[i]]!=0){
                nmap[amap[A[i]]]+=1;
                continue;
            }
            vector<ll> np = normalize_pairlize(A[i],primes);
            normal.push_back(np[0]);
            pair.push_back(np[1]);
            
            if(np[0] != 1){
                nmap[np[0]] += 1;
                pmap[np[0]] = np[1];
                amap[A[i]] = np[0];
            }
            else{n1=true;}
     
        }
     
     
     
     
        for(auto x:nmap){
            if(x.first==1) continue;
            if(nmap[x.first] >= nmap[pmap[x.first]]) {
                ans+=nmap[x.first];
                nmap[x.first]=0;
                nmap[pmap[x.first]]=0;
            }
     
            else{
                ans+=nmap[pmap[x.first]];
                nmap[x.first]=0;
                nmap[pmap[x.first]]=0;
            }
        }
        if(n1) ans++;
        cout<<ans<<endl;
        return 0;
    };