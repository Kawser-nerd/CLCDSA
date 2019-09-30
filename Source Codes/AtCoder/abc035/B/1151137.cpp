#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<utility>
#include<set>
#include<complex>
#include<map>
#define vi vector<int>
#define vvi vector<vector<int> >
#define ll long long int
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ld long double
#define INF 1e9
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define all(in) in.begin(), in.end()
#define MAX 9999999
using namespace std;
typedef pair<int, int> pii;
typedef pair<double,double>pdd;
typedef pair<ll,ll>pll;
int main(){
    string s; cin>>s; int t; cin>>t; --t;
    int un=0; pii now=pii(0,0);
    rep(i,s.size()){
        if(s[i]=='U')now=pii(now.first+1,now.second);
        else if(s[i]=='D')now=pii(now.first-1,now.second);
        else if(s[i]=='R')now=pii(now.first,now.second+1);
        else if(s[i]=='L')now=pii(now.first,now.second-1);
        else un++;
    }
    if(!t)cout<<abs(now.first)+abs(now.second)+un<<endl;
    else{
        cout<<max((int)s.size()%2,abs(now.first)+abs(now.second)-un)<<endl;
    }
}