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


using namespace std;

typedef pair<int,int> Pair;

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

template<class a,class b>
ostream & operator << (ostream & tout,const pair<a,b> &c){
  return(tout<<'('<<c.first<<','<<c.second<<')');
}

template<class T> struct __set__print{
  __set__print(ostream& out) : tout(out), count(0) {}
  void operator() (T x) { 
    if (count > 0)
      tout<<',';
    tout<<x;
    ++count; 
  }
  ostream& tout;
  int count;
};

template<class T>
ostream & operator << (ostream & tout,const set<T> &s){
  tout<<'{';
  for_each(s.begin(),s.end(),__set__print<T>(tout));
  return(tout<<'}');
}

template<class T,class Q> struct print_map{
  print_map(ostream& out) : tout(out), count(0) {}
  void operator() (const pair<T,Q> &x) { 
    if (count > 0)
      tout<<',';
    tout<<'('<<x.first<<" => "<<x.second<<')';
    ++count; 
  }
  ostream& tout;
  int count;
};

template<class T,class Q>
ostream & operator << (ostream & tout,map<T,Q> s){
  tout<<'{';
  for_each(s.begin(),s.end(),print_map<T,Q>(tout));
  return(tout<<'}');
}

template<class T>
string to_string(T s){
  stringstream tin;
  tin<<s;
  string res;
  getline(tin,res);
  return(res);
}


template<class T>
vector<T> to_vector(T *s,int n){
  vector<T> result;
  for (int i=0;i<n;i++)
    result.push_back(s[i]);
  return(result);
}

// *********************************** MY CODE ***************************

const int MAX_N = 1000+200;

int l1[MAX_N],l2[MAX_N],n,used[MAX_N];

bool better(Pair s,Pair t){
  if (s.first != t.first)
    return(s.first > t.first);
  if (l2[s.second] != l2[t.second])
    return(l2[s.second] > l2[t.second]);
  return(s < t);
}

int main(){
  ios_base::sync_with_stdio(false) ;
  int ttime;
  cin>>ttime;
  for (int ccount=1;ccount<=ttime;ccount++){
    cin>>n;
    for (int i=1;i<=n;i++)
      cin>>l1[i]>>l2[i];

    for (int i=1;i<=n;i++)
      used[i] = 0;
    
    int stars = 0;
    int cnt = 0;
    while (stars < 2*n){
      cnt++;
      Pair next(-1,-1);
      for (int i=1;i<=n;i++){
	if (used[i] < 1 && l1[i] <= stars)
	  next = min(next,Pair(1,i),better);
	if (used[i] < 2 && l2[i] <= stars)
	  next = min(next,Pair(2,i),better);
      }
//       cout<<stars<<' '<<next<<endl;
      if (next.first == -1)
	break;
      stars+=next.first-used[next.second];
      used[next.second]+=next.first;
    }
    if (stars < 2*n)
      cout<<"Case #"<<ccount<<": Too Bad"<<endl;
    else
      cout<<"Case #"<<ccount<<": "<<cnt<<endl;
  }
}
