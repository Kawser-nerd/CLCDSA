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

vector<pii> v;

bool bad(){REP(i,v.size()) if(v[i].second>=2) return 1;return 0;}
void add(int x){
    REP(i,v.size()) if(v[i].first==x){v[i].second++;return;}
    else if(v[i].first>x){
        v.insert(v.begin()+i,pii(x,1));
        return;
    }
    v.pb(pii(x,1));
}
void split(){
    REP(i,v.size()) if(v[i].second>1){
        int x = v[i].first;
        v[i].second-=2;
        if(v[i].second==0) v.erase(v.begin()+i);
        add(x-1);
        add(x+1);
        break;
    }
}
int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
    int TC;
    cin>>TC;
    REP(tc,TC){
        int n;
        cin>>n;
        v.resize(n);
        REP(i,n) scanf("%d %d",&v[i].first,&v[i].second);

        int num = 0;
        while(bad()) 
            split(),num++;   

        printf("Case #%d: %d\n",tc+1,num);

       
    }
    return 0;
}