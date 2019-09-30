#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> read(string s);
int answer(const vector<int>& v);

int main(){
  int t;
  cin>>t;
  string line;
  getline(cin,line);
  for(int i=1;i<=t;i++){
    getline(cin,line);
    vector<int> bases=read(line);
    cout<<"Case #"<<i<<": "<<answer(bases)<<'\n';
  }
}

vector<int> read(string s){
  vector<int> ret;
  int n;
  istringstream sin(s);
  while(sin>>n)
    ret.push_back(n);
  return ret;
}

bool happy(int n,int b);

int answer(const vector<int>& v){
  for(int i=2;;i++){
    bool good=true;
    for(int j=0;j<v.size();j++)
      if(!happy(i,v[j])){
        good=false;
        break;
      }
    if(good)
      return i;
  }
}

const int B=16,N=1024*1024*8;
int cache[N][B];
int cached[N][B];

int square_sum(int n,int b){
  int ret=0;
  while(n){
    int d=n%b;
    n/=b;
    ret+=d*d;
  }
  return ret;
}

bool happy(int n,int b){
  if(n<N && cached[n][b]++)
    return cache[n][b];
  if(n<N)
    cache[n][b]=false;
  int s=square_sum(n,b);
  if(s==1){
    if(n<N)
      return cache[n][b]=true;
    return true;
  }
  int ret=happy(s,b);
  if(n<N)
    return cache[n][b]=ret;
  return ret;
}
