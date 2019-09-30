#include<iostream>
  #include<vector>
  #include<algorithm>
  #include<cmath>

  using namespace std;
  #define rep(i,n) for(int i=0;i<(n);i++)

  int main(){

    using i64=long long;
    i64 n; cin>> n;
    vector<int> x(n), y(n);
    rep(i, n) cin>> x[i]>> y[i];

    int cnt[3]={};
    rep(i, n)rep(j, i)rep(k, j){
      int ux=x[j]-x[i], uy=y[j]-y[i],
          vx=x[k]-x[i], vy=y[k]-y[i];
      int dot=ux*vx+uy*vy;
      if(dot==0) cnt[1]++;
      else if(dot<0) cnt[2]++;
      ux=x[k]-x[j]; uy=y[k]-y[j];
      vx=x[i]-x[j]; vy=y[i]-y[j];
      dot=ux*vx+uy*vy;
      if(dot==0) cnt[1]++;
      else if(dot<0) cnt[2]++;
      ux=x[i]-x[k]; uy=y[i]-y[k];
      vx=x[j]-x[k]; vy=y[j]-y[k];
      dot=ux*vx+uy*vy;
      if(dot==0) cnt[1]++;
      else if(dot<0) cnt[2]++;
    }

    cnt[0]=n*(n-1)*(n-2)/6-(cnt[1]+cnt[2]);
    rep(i, 3) cout<< cnt[i]<< (i+1<3 ? ' ' : '\n');

    return 0;
  }