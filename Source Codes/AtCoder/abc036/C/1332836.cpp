#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>
#define ll long long
#define INF 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<int(n);i++)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
using namespace std;

int main(){
  ll n;
  cin>>n;
  vector<int>a(n);
  set<int>st;
  rep(i,n){
    cin>>a[i];
    st.insert(a[i]);
  }
  map<int,int>m;
  int cnt=0;
  for(int x : st){
    m[x]=cnt;
    cnt++;
  }
  rep(i,n)cout<<m[a[i]]<<endl;
  return 0;
}