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
#define rp(i,a,b) for(int (i)=(int)(a);i<(int)(b);++i)

using namespace std;

typedef long long ll;
/*
struct aInt{
    int index;
    long long value;
    aInt(int i, int v){
        index = i;
        value = v;
    }
    bool operator<( const aInt& right ) const {
        return value == right.value ? index < right.index : value < right.value;
    }
};
*/
int main(){
    int N,y=0;
    ll x;
    ll ans = 1LL<<62;;
    vector<ll> a;
    vector<ll>a_c;
    cin>>N>>x;
    rp(i,0,N){ll A;cin>>A;a.push_back(A);a_c.push_back(A);}
    rp(i,0,N){
        ll tmp=0;
        rp(j,0,N) {
            //cout<<(j+N-i)%N<<endl;
            a_c[j] = min(a_c[j],a[(j+N-i)%N]);
            tmp+=a_c[j];
        }
        ans = min(ans,tmp + x*i);
    }
    cout<<ans<<endl;



        return 0;
};