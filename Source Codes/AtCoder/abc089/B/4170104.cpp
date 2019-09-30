#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

int main(){
   int n;
   cin>>n;
   char s[110];
   for(int i=0;i<n;i++)cin>>s[i];
   int cnt[4]={0};
   for(int i=0;i<n;i++){
      if(s[i]=='P')cnt[0]=1;
      else if (s[i]=='W')cnt[1]=1;
      else if(s[i]=='G')cnt[2]=1;
      else cnt[3]=1;
   }
   if(cnt[0]==1 && cnt[1]==1 && cnt[2]==1 && cnt[3]==1)cout<<"Four"<<endl;
   else cout<<"Three"<<endl;

   
}