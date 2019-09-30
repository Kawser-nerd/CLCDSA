#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
 
#define REP(i,a,n) for(int i=a;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define REV(i,a,n) for(int i=n;i>=a;--i)
#define all(e) e.begin(),e.end()
#define rall(e) e.rbegin(),e.rend()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define show(n) cerr<<#n<<" = "<<n<<endl
#define shows(n) for(auto z:n){cerr<<z<<", ";}cerr<<endl
 
//????AtCoder??define
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pint = pair<int,int>;
 
const int INF = ~(1 << 31);

const int maxN=100000;
 
vector<bool> isprime;
int c[maxN+2]; 

void sieve(size_t max){
    if(max+1 > isprime.size()){
        isprime.resize(max+1,true);
    } 
    isprime[0] = false;
    isprime[1] = false;

    for(size_t i=2; i*i<=max; ++i)
        if(isprime[i])
            for(size_t j=2; i*j<=max; ++j)
                isprime[i*j] = false;
}

int main(){
    sieve(maxN+1);

    REP(i,1,maxN+1){
        if(isprime[i]&&isprime[(i+1)/2]) c[i]++;
    }

    REP(i,1,maxN+1) c[i]+=c[i-1];

    int q;
    cin>>q;
    int l,r;
    rep(i,q){
        scanf("%d" "%d" ,&l,&r);
        //show(c[r]);
        //show(c[l-1]);
        printf("%d\n",c[r]-c[l-1]);
    }
    
    return 0;
}