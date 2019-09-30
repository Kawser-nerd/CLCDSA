#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
#define maxn 200005
 typedef long long ll;
ll l,n,T,x[200005];
ll w[200005],t[200005];
ll sum[200005],ans[200005];
ll f(ll x){
  while(x<0)x+=l;
  return x%l;
}
ll calc(int left,int right,int p){
  if(p==1)return sum[right]-sum[left];
  else return (right-left)-(sum[right]-sum[left]);
}
 void solve(){
  ll o=T*2/l;
  ll nt=T*2%l;
  int h=0;
  for(int i=0;i<n;i++){
    if(w[i]==2)continue;
    ll key=i;
    key+=o*(n-sum[n]);
    while(h<n+n&&(w[h]==1||x[h]-x[i]<=nt))h++;
    key+=calc(i,h,2);
    key%=n;
    ans[key]=t[i];
  }
  h=n+n-1;
  for(int i=n+n-1;i>=n;i--){
    if(w[i]==1)continue;
    ll key=i;
    key+= n-(o*(sum[n]) )%n;
    while(h>=0&&(w[h]==2||x[i]-x[h]<=nt))h--;
    key+=(n-calc(h+1,i,1))%n;
    key%=n;
    ans[key]=t[i];
  }
}
 int main(){
  memset(ans,-1,sizeof(ans));
  cin>>n>>l>>T; 
  for(int i=0;i<n;i++){
    cin>>x[i]>>w[i]; 
    if(w[i]==1){
      t[i]=x[i]+T;
    } else{
      t[i]=x[i]-T;
    }
    t[i]=f(t[i]);
  }
  
  for(int i=0;i<n;i++){
    x[i+n]=x[i]+l;
    w[i+n]=w[i];
    t[i+n]=t[i];
  }
  for(int i=1;i<=n*2;i++){
    sum[i]=sum[i-1];
    if(w[i-1]==1)sum[i]++;
  }
  solve();
 for(int i=0;i<n;i++)
    cout<<ans[i]<<endl;
  return 0;
}