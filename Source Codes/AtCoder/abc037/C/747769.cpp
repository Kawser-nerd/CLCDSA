#include<iostream>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];

  long long S[n];
  S[0]=a[0];
  for(int i=1;i<n;i++)
    S[i]=S[i-1]+a[i];

  long long ans=S[k-1];
  for(int i=k;i<n;i++)
    ans+=S[i]-S[i-k];
  cout<<ans<<endl;
  return 0;
}