#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,p,odd=0;
    cin>>n>>p;
    int v[n];
    for(int i=0;i<n;i++){
      cin>>v[i];
      if (v[i]%2) odd++;}
  if(odd==0)
  {if(p==1) cout << 0 << endl;
  else cout <<  (long long) pow(2,n)<< endl;
  }
  else  cout << (long long) pow(2,n-1)<< endl;
}