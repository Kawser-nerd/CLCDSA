#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int main(){
   int n;
   cin>>n;
   int a[110];
   for(int i=0;i<n;i++)cin>>a[i];
   int ans=0;
   sort(a,a+n,greater<int>());
   for(int i=0;i<n;i++){
      if(i%2==0){
         ans+=a[i];
      }
      else ans-=a[i];
   }
   cout<<ans<<endl;

   
   
}