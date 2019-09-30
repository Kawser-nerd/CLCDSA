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
#define double long double
#define free __fucking_free

using namespace std;

const double EPS = 1e-7;

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

const int MAX_N = 150000+20;
vector<Pair> e[MAX_N][2];
vector<int> Glo;
bool mark[MAX_N],ans[MAX_N];

struct TwoSat{
  int n;
  TwoSat(int s){ 
    n=s; 
    Glo.clear();
    for (int i=0;i<MAX_N;i++){
      e[i][0].clear(); e[i][1].clear();
      mark[i]=ans[i]=false;
    }
  }
  inline bool dfs(int s,bool t){
    if (mark[s]) return(ans[s] == t);
    mark[s]=true; ans[s]=t; Glo.push_back(s);
    for (int i=0;i<e[s][t].size();i++)
      if (!dfs(e[s][t][i].first,e[s][t][i].second))
	return(false);
    return(true);
  }
  inline bool fix(Pair s){
    Glo.clear();
    if (dfs(s.first,s.second)) return(true);
    for (int i=0;i<Glo.size();i++) mark[Glo[i]]=ans[Glo[i]]=false;
    return(false);
  }
  inline void push_back(int A,bool a,int B,bool b){  
    e[A][!a].push_back(Pair(B,b));
    e[B][!b].push_back(Pair(A,a));
  }
  inline bool relax(){
    for (int i=1;i<=n;i++) 
      if (!fix(Pair(i,0)) && !fix(Pair(i,1))) 
	return(false);
    return(true);
  }
};


int n;

bool eq(double s,double t){
  return(abs(s-t) < 1e-6);
}

bool inters[6000][51][51];
bool free[6000][51];

char where[51];
int speed[51],p[51];

TwoSat getTwoSat(int tn,vector<double> times){
  TwoSat mai(n*tn);
  for (int i=0;i<tn;i++)
    for (int j=1;j<=n;j++)
      if (!free[i][j]){
	for (int k=1;k<=n;k++)
	  if (inters[i][j][k]){
	    mai.push_back(i*n+j,0,i*n+k,0);
	    mai.push_back(i*n+j,1,i*n+k,1);
	  }
	if (i > 0 && !free[i-1][j]){
	  mai.push_back(i*n+j,1,(i-1)*n+j,0);
	  mai.push_back(i*n+j,0,(i-1)*n+j,1);
	}
      }
  for (int i=1;i<=n;i++)
    if (where[i] == 'L')
      mai.push_back(i,0,i,0);
    else
      mai.push_back(i,1,i,1);
  return(mai);
}

int main(){
  ios_base::sync_with_stdio(false) ;
  int ttime;
  cin>>ttime;
  for (int ccount=1;ccount<=ttime;ccount++){
    cin>>n;
    for (int i=1;i<=n;i++)
      cin>>where[i]>>speed[i]>>p[i];
    vector<double> events(1,0);
    for (int i=1;i<=n;i++)
      for (int j=i+1;j<=n;j++)
	if (speed[i] != speed[j]){
	  events.push_back((double)(p[j]-p[i]-5)/(speed[i]-speed[j]));
	  events.push_back((double)(p[j]-p[i]+5)/(speed[i]-speed[j]));
	}
    sort(events.begin(),events.end());
    events.resize(unique(events.begin(),events.end(),eq)-events.begin());
    vector<double> times(1,0);
    for (int i=0;i+1<events.size();i++) if (events[i] > -EPS)
      times.push_back((events[i]+events[i+1])/2);
    times.push_back(events.back()+1);
    for (int i=0;i<events.size();i++) if (events[i] > EPS)
      times.push_back(events[i]);

    sort(times.begin(),times.end());
//     cout<<times<<endl;

    for (int i=0;i<times.size();i++){
      for (int j=1;j<=n;j++)
	for (int k=1;k<=n;k++)
	  inters[i][j][k] = false;
      for (int j=1;j<=n;j++)
	free[i][j] = true;
    }

    for (int i=1;i<=n;i++)
      for (int j=i+1;j<=n;j++)
	if (speed[i] != speed[j]){
	  double x = (double)(p[j]-p[i]-5)/(speed[i]-speed[j]);
	  double y = (double)(p[j]-p[i]+5)/(speed[i]-speed[j]);
	  if (x > y)
	    swap(x,y);
	  for (int a=0;a<times.size();a++)
	    if (times[a] >= x+EPS && times[a] <= y-EPS){
	      inters[a][i][j] = inters[a][j][i] = true;
	      free[a][i] = free[a][j] = false;
	    }
	}else{
	  if (abs(p[i]-p[j]) < 5)
	    for (int a=0;a<times.size();a++){
	      inters[a][i][j] = inters[a][j][i] = true;
	      free[a][i] = free[a][j] = false;
	    }
	}

//     for (int i=0;i<2;i++){
//       cout<<times[i]<<": "<<endl;
//       for (int j=1;j<=n;j++,cout<<endl)
// 	for (int k=1;k<=n;k++) 
// 	  cout<<inters[i][j][k]<<' ';
//       cout<<endl;
//       cout<<endl;
//       for (int j=1;j<=n;j++)
// 	cout<<free[i][j]<<' ';
//       cout<<endl;
//       cout<<endl;
//     }

//     cout<<"Hi :"<<getTwoSat(2,times).relax()<<endl;
    
    int start = 0,end = times.size()-1;
    while (start != end){
      int mid = (start+end)/2+1;
      if (getTwoSat(mid+1,times).relax())
	start=mid;
      else
	end = mid-1;
    }

    cout<<fixed;
    cout.precision(20);

 

    if (end == times.size()-1)
      cout<<"Case #"<<ccount<<": Possible"<<endl;
    else
      cout<<"Case #"<<ccount<<": "<<times[end]<<endl;
  }
}
