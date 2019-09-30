#include <iostream>

using namespace std;

double answer(int get,int need);
double choose(int n,int k);
const int N=41;
int key=0;

int main(){
  int t;
  cin>>t;
  cout.setf(ios::fixed|ios::showpoint);
  cout.precision(7);
  for(int i=1;i<=t;i++){
    int get,need;
    key++;
    cin>>need>>get;
    cout<<"Case #"<<i<<": "<<answer(get,need)<<'\n';
  }
}

double choose(int n,int k){
  if(k<0 || k>n) return 0;
  static int cached[N][N];
  static double cache[N][N];

  if(cached[n][k]++)
    return cache[n][k];
  double& ret=cache[n][k]=0;
  if(n==k || k==0)
    return ret=1;
  return ret=choose(n-1,k)+choose(n-1,k-1);
}

double memo(int get,int need,int have);

double answer(int get,int need){
  return 1+memo(get,need,get);
}

double prob(int get,int need,int have,int more,double total){
  return choose(need-have,more)*choose(have,get-more)/total;
}

double memo(int get,int need,int have){
  static int cached[N];
  static double cache[N];
  if(cached[have]==key)
    return cache[have];
  cached[have]=key;
  double& ret=cache[have]=0;
  if(have==need)
    return ret=0;
  double total=choose(need,get);
  double p0=prob(get,need,have,0,total);
  double s=0;
  for(int i=1;i<=get && have+i<=need;i++)
    s+=prob(get,need,have,i,total)*memo(get,need,have+i);
  ret=(1+s)/(1-p0);
  return ret;
}
