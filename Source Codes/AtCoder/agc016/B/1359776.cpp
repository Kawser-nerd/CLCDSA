#include<iostream>
#include<algorithm>

using namespace std;

void ng(){
  cout << "No" << endl;
  exit(0);
}

void ok(){
  cout << "Yes" << endl;
  exit(0);
}
int a[108000], n;
int main(){
  cin >> n;
  int mn = n + 1;
  int mx = 0;
  int mxcnt = 0;
  int mncnt = 0;
  for(int i = 0;i < n;i++){
    cin >> a[i];
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
  }

  if(mx == mn){
    if(2 * mx <= n || mx == n-1)ok();
    else ng();
  }
  if(mx - mn > 1)ng();
  
  for(int i = 0;i < n;i++){
    mncnt += a[i] == mn;
    mxcnt += a[i] == mx;
  }
  if(mx < mncnt + 1)ng();
  if((mx - mncnt) * 2 <= mxcnt)ok();
  else ng();
}