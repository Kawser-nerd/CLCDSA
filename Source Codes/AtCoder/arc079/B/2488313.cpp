#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll; 
int main(){
  ll k;
  cin >> k;
  if(k==0){
  cout << 2 << endl;
  cout << "1 1" << endl;
    return 0;
  }
  vector<ll>  v(50);
  for(int i=0;i<50;i++) v[i] = (k/50)+50;
  int res = k % 50;
  res = 50 - res;
  for(int i=0;i<res;i++){
  	int ind=-1; ll m = 0;
    for(int j=0;j<50;j++){
    	if(v[j]>m){ m = v[j]; ind = j;}
    }
    for(int j=0;j<50;j++){
    	if(ind==j) v[j] -= 50;
      	else v[j]++;
    }
  }
  cout << 50 << endl;
  for(int j=0;j<50;j++) cout << v[j] << " ";
  cout << endl;
  return 0;
}