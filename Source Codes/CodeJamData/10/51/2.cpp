#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

bool p[1111111];
int a[11];

int qp(ll c,int st,int mod){
    ll r = 1;
    while(st){
        if(st&1) r*=c,r%=mod;
        c*=c,c%=mod;
        st>>=1;
    }
    return int(r);
}
ll inv(int c,int mod){
    return qp(c,mod-2,mod);
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    for(int j=2;j<=1111;j++)if(!p[j]){
        for(int i = j+j;i<=1000000;i+=j)p[i]=true;
    }
    int TC;
    cin>>TC;
    REP(tc,TC){
        int res = -2;

        int d,k;
        cin>>d>>k;
    
        int to = 1;
        REP(i,d) to*=10;

        int mx = 0;
        REP(i,k) cin>>a[i],mx=max(mx,a[i]);

        if(a[0]==a[1]) res = a[0];
        else if(k<=2) res = -1;
        else{
            for(int i=mx+1;i<=to;i++)if(!p[i]){
                int P = i;

                int k1 = inv(a[1],P) - inv(a[0],P);
                if(k1<0) k1+=P;

                ll k2 = inv(a[1],P)*a[2] - inv(a[0],P)*a[1];
                k2%=P;
                if(k2<0) k2+=P;

                k2*=inv(k1,P);
                k2%=P;

                ll B = k2;

                if(a[0]==0 || a[1]==0){
                    REP(j,2)if(a[j]==0){
                        B = a[j+1];
                        break;
                    }
                }

                ll A = inv(a[0], P) * (a[1] - B);
                if(a[0]==0)
                    A = inv(a[1], P) * (a[2] - B);
                A%=P;
                if(A<0) A+=P;

                bool good = true;
                for(int j= 1;j<k;j++){
                    if(a[j]!=((A*a[j-1]+B)%P)){
                        good = 0;
                        break;
                    }
                }
                if(good){
                    if(res >=0 && res !=((A*a[k-1]+B)%P)) {
                        res=-1;
                        break;
                    }
                    res = (A*a[k-1]+B)%P;
                }
            }
        }
        
        printf("Case #%d: ",tc+1);
        if(res<0) puts("I don't know.");
        else cout<<res<<endl;
    }
    return 0;
}