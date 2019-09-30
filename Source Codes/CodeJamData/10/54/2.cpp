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

const int mod = 1000000007;

int nb(int x){return x==0?0:1+nb(x&(x-1));}
ll F[75];
ll c[75][75];


map<ll,int> d[75][75];


int q[75][75*75];

int b;
int go(ll n,int per,int left){
    if(n==0) return per==0 && left==0? 1 : 0;
    if(left==0) return n==per ? 1 : 0;
    if(d[per][left].count(n)) return d[per][left][n];

    int val = 0;
    REP(i,b*b)if(q[left][i]){
        int sum = per + i;
        if((sum-n)%b==0){
            REP(nl,left+1)if(left >= nl){
                ll temp  = go(n/b,sum/b,nl);
                temp*=F[left];
                temp%=mod;
                temp*=c[left][nl];                
                temp%=mod;
                temp*=q[left][i];
                temp%=mod;

                val += temp;
                val%=mod;
            }
        }
    }
    REP(i,b*b)if(q[left-1][i]){
        int sum = per + i;
        if((sum-n)%b==0){
            REP(nl,left+1)if(left-1 >= nl){
                ll temp  = go(n/b,sum/b,nl+1);
                temp*=F[left];
                temp%=mod;
                temp*=c[left-1][nl];                
                temp%=mod;
                temp*=q[left-1][i];
                temp%=mod;

                val += temp;
                val%=mod;
            }
        }
    }
    return d[per][left][n]=val;
}

ll qp(ll c,ll st){
    ll r = 1;
    while(st){
        if(st&1) r*=c,r%=mod;
        c*=c,c%=mod;
        st>>=1;
    }
    return r;
}
ll inv(int c) {return qp(c,mod-2);}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    F[0]=1;
    FOR(i,1,75) F[i]=F[i-1]*i,F[i]%=mod;
    c[0][0]=1;
    FOR(i,1,75){
        c[i][0]=c[i][i]=1;
        FOR(j,1,i) c[i][j]=c[i-1][j-1]+c[i-1][j],c[i][j]%=mod;
    }
    
    int TC;
    cin>>TC;
    REP(tc,TC){
        ll n;
        cin>>n>>b;

        CL(q,0);
        q[0][0]=1;
        FOR(i,1,b){
            for(int level = b-1;level>=0;level--)
                REP(sum,b*b)
                    q[level+1][sum+i] += q[level][sum], q[level+1][sum+i]%=mod;
        }

        REP(i,75)REP(j,75)d[i][j].clear();

        int res = 0;
        ll f = 1;
        FOR(i,1,b+1){
            ll temp = go(n,0,i);
            f*=i;
            f%=mod;
            temp *= inv(f);
            temp%=mod;
            res+=temp;
            res%=mod;
        }

        printf("Case #%d: %d\n",tc+1,res);       
    }
    return 0;
}