#include<iostream>
#include<string>
using namespace std;
long N,M;
string S,T;
long i,k;
bool good;
long ans;
int main(){
  cin >> N >> M >> S >> T;
  for (i=1;i<=N;i++){
    if (N%i!=0){continue;}
    k = N/i;
    if (M%k==0){break;}
  }
  good = true;
  for (i=0;i<k;i++){
      if (S[(N/k)*i]!=T[(M/k)*i]){good = false;}
  }
  if (good){ans = N*M/k;}
  else{ans = -1;}
  cout << ans <<endl;
  return 0;
}