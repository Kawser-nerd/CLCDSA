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
     
    typedef long long ll;
    using namespace std;
    const int MAX_N=1e5+1;
    const int MAX_Q=1e5+1;
    ll MAX_q=1e18+1;
    ll a[MAX_N];
    ll t[MAX_N];
     
    int binsearch(vector<ll> x,ll y,int z){
        int l=-1,r=z,mid;
        while(r-l>1){
            mid=(l+r) / 2;
            if(y >= x[mid]) l=mid;
            else  r = mid;
        }
        return r;
    }
     
    int main(){
        int N;
        int Q;
        cin>>N>>Q;
        vector<ll> q;
        q.push_back(N);
        for(int i =0;i<Q;i++) {
            ll x;
            cin>>x;
            while(!q.empty() && q.back() >= x) q.pop_back();
            q.push_back(x);
        }
     
        int L = q.size() - 1;
        t[L] = 1;
     
        for(int i = L;i >0;i--){
            ll k=q[i];
            while(k>q[0]){
                int ind=lower_bound(q.begin(),q.begin()+i,k)-q.begin()-1;
                t[ind]+=t[i]*(k/q[ind]);
                k=k%q[ind];
            }
            a[k-1]+=t[i];
        }
        a[q[0]-1] += t[0];
        for(int i=N-1;i>=0;i--) a[i]+=a[i+1];
        for(int i=0;i<N;i++) cout<<a[i]<<endl;    
        return 0;
    };