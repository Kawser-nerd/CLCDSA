#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main(){

  long long n; 
  cin >> n;
  vector<int> a(n),b(n),c(n);
  rep(i,n)cin >> a[i];
  rep(i,n)cin >> b[i];
  rep(i,n)cin >> c[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());
  // rep(i,n)cout << a[i]<<" ";
  // cout<<endl;
  // rep(i,n)cout<<b[i]<<" ";
  // cout<<endl;
  // rep(i,n)cout<<c[i]<<" ";
  // cout<<endl;

  vector<long long> b_pos(n);
  rep(i,n){
    vector<int>::iterator up;
    up = upper_bound(c.begin(),c.end(),b[i]);
    b_pos[i] = n-(long long)(up-c.begin());
    // cout << b_pos[i]<<endl;
  }
  rep(i,n){
    if(i==0)continue;
    b_pos[n-1-i] += b_pos[n-i];
  }
  //rep(i,n)cout<<b_pos[i]<<endl;
  //cout << endl;

  long long sum = 0;
  rep(i,n){
    vector<int>::iterator up;
    up = upper_bound(b.begin(),b.end(),a[i]);
    sum += b_pos[(int)(up-b.begin())]; 
  }
  cout << sum << endl;

  return 0;
}