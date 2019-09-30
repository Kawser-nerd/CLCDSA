#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <set>

using namespace std;
int c[4][4];

int main(){
   for(int i=1;i<4;i++){
      for(int j=1;j<4;j++){
         cin>>c[i][j];
      }
   }
   for(int a1=0;a1<c[1][1]+1;a1++){
      if(c[2][1]+c[1][2]-c[1][1]==c[2][2] && c[2][1]+c[1][3]-c[1][1]==c[2][3] && c[3][1]+c[1][2]-c[1][1]==c[3][2] && c[3][1]+c[1][3]-c[1][1]==c[3][3]){
         cout<<"Yes"<<endl;
         return 0;
      }
   }
   cout<<"No"<<endl;

   
   
}