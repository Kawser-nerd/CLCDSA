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
   int x,a,b;
   cin>>x>>a>>b;
   int ans=0;
   ans=x-a-(x-a)/b*b;
   cout<<ans<<endl;
}