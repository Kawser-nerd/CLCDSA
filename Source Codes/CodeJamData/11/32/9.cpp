#include <cstdio>
#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <algorithm>
#include <functional>
#include <fstream>
#include <numeric>
#include <string>
#include <valarray>
#define int long long


using namespace std;

template<class t>
ostream & operator << (ostream & tout,const vector<t> &s){
  tout<<'[';
  for (int i=0;i<s.size();i++)
    if (i+1 == s.size())
      tout<<s[i];
    else
      tout<<s[i]<<',';
  tout<<']';
  return(tout);
}


int l,t,n,c;

int cal(vector<int> all,int pointer,int l,bool qp){
  int sum=0;
  if (l < 1)
    return(accumulate(all.begin(),all.end(),0ll)*2);
  int tp=0;
  for (int i=0;i<pointer && i < all.size();i++){
    tp+=all[i]*2;
    sum+=all[i]*2;
  }
  if (pointer < all.size()){
    if (qp){
      if (tp >= t)
	sum+=all[pointer];
      else
	sum+=(t-tp)+(all[pointer]-(t-tp)/2);
    }else
      pointer--;
    vector<int> q;
    for (int j=pointer+1;j<all.size();j++)
      q.push_back(all[j]);
//     cerr<<" p "<<sum<<' '<<q<<endl;
    sort(q.begin(),q.end());
    reverse(q.begin(),q.end());
    for (int j=0;j<q.size();j++)
      if (j < l-1+(!qp))
	sum+=q[j];
      else
	sum+=q[j]*2;
  }
//   cerr<<"here "<<pointer<<' '<<l<<' '<<sum<<endl;
  return(sum);
}

#undef int
int main(){
#define int long long
  int ttime;
  cin>>ttime;
  for (int ccount=1;ccount<=ttime;ccount++){
    cin>>l>>t>>n>>c;
    vector<int> all(n);
    for (int i=1;i<=c;i++){
      int x;
      cin>>x;
      for (int j=0;j*c+i-1<all.size();j++)
	all[j*c+i-1] = x;
    }
//     cout<<all<<' '<<t<<' '<<l<<endl;
    int sum=0,pointer=0;
    while (pointer < all.size() && sum+all[pointer]*2 <= t){
      sum+=all[pointer]*2;
      pointer++;
    }
    int ans=min(cal(all,pointer,l,true),cal(all,pointer+1,l,false));
    cout<<"Case #"<<ccount<<": "<<ans<<endl;
  }
  
}
