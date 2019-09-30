#include <iostream>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  int a[n];
  bool f=true;
  for(int i=0;i<n;i++){cin >> a[i]; if(a[i]==0){cout << n << endl; return 0;} if(a[i]<=k) f=false;}
  if(f){cout << 0 << endl; return 0;}
  int m=0;
  long long int mul = 1;
  int j=0;
  for(int i=0;i<n;i++){
    mul = mul * a[i];
    while(mul>k&&i>=j){
      mul = mul / a[j];
      j++;
    }
    if(mul==0){mul = a[i]; j=i;}
    m = (mul<=k&&m<(i-j+1)) ? (i-j+1) : m;
  }
  cout << m << endl;
  return 0;
}