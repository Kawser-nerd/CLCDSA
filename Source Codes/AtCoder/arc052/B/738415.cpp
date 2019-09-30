#include<iostream>
#include<cmath>
using namespace std;

void A(){
  string s;

  cin >> s;

  for(int i=0; i<(int)s.size(); i++){
    if('0'<=s[i] && s[i]<='9') cout << s[i];
  }
  cout << endl;
}


int x[1000], h[1000], r[1000];

void B(){
  int n, q;

  cin >> n >> q;
  cout.setf(ios::fixed,ios::floatfield);
  cout.precision(6);
  for(int i=0; i<n; i++) cin >> x[i] >> r[i] >> h[i];

  for(int i=0; i<q; i++){
    int a,b;
    double s = 0;
    cin >> a >> b;

    for(int j=0; j<n; j++){
      double lower, upper;
      if(x[j]+h[j] < a || b < x[j]) lower=0;
      else if(a <= x[j]) lower = r[j];
      else lower = (double)r[j] * (x[j]+h[j]-a) / h[j];

      if(x[j]+h[j] < b || b < x[j]) upper=0;
      else upper = (double)r[j] * (x[j]+h[j]-b) / h[j];

      double lheight = x[j]<a ? x[j]+h[j]-a : h[j];
      double uheight = x[j]+h[j]-b;

      //      cout << x[j] << " " << h[j] << " " << upper << " " << lower<< endl;
      s += lower*lower*M_PI*lheight/3 - upper*upper*M_PI*uheight/3;
    }
    cout << s << endl;
  }
}

int main(){
  B();
}