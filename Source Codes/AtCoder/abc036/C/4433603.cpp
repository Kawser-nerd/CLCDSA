#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include <cstdlib>
#include <string>
#include <typeinfo>

using namespace std;

int n;
int a[100005];
map< string, int>m;
vector<int>V, W;

void solver(){
  int v = 0;
  int cnt = 0;
  for(int i = 0; i < n; ++i){
    if(V[i] > v){
      v = V[i];
      m.insert(make_pair(to_string(V[i]), cnt));
      cnt++;
    }
  }
  for(int i = 0; i < n; ++i){
    decltype(m)::iterator it = m.find(to_string(W[i]));
    if (it != m.end()) { // ?????
      std::cout << it->second << std::endl;
    }
  }
}

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    V.push_back(a[i]);
    W.push_back(a[i]);
  }
  sort(V.begin(), V.end());
  solver();
}