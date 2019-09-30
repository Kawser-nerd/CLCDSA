#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<climits>
#include<cstdlib>
#include<map>
#include<math.h>
using namespace std;
int main(){
  long long n;
  long long a[1000001];

  cin >> n;
  for(long long i=0; i<n; i++){
    cin >> a[i];
  }
  long long sa[1000001];
  sa[0] = 0;
  for(long long i=0; i<n; i++){
    sa[i+1] = sa[i] + a[i];
  }

  sort(sa, sa+n+1);
  long long k = 1;
  long long ans=0;
  for(long long i = 1; i<=n; i++){
    if(sa[i]==sa[i-1]) k++;
    else{
      ans += k*(k-1)/2;
      k = 1;
    }
  }
  cout << ans+k*(k-1)/2 << endl;
}