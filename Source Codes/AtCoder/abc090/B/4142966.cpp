#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

int main(){
   int a,b;
   cin>>a>>b;
   int ans=0;
   for(int i=a;i<b+1;i++){
      string s=to_string(i);
      if(s[0]==s[4] && s[1]==s[3])ans++;
   }
   cout<<ans<<endl;
}