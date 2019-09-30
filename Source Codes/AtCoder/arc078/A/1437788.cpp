#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(){
int n;
long long X=0,x=0,ans=1000000000000000000LL;
cin>>n;
vector<long long> a(n);
for(int i=0;i<n;i++){
cin>>a[i];
X+=a[i];
}
for(int i=0;i<n;i++){
x+=a[i];
if(i+1<n)ans=min(ans,abs(X-2*x));
}
cout<<ans<<endl;
}