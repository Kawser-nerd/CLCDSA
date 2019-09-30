#include <iostream>
using namespace std;
int main(){
int n;
while(cin>>n){
   int ge,bai;
   ge=n%10;
   bai=n/100;
   if(ge==bai) cout<<"Yes"<<endl;
   else cout<<"No"<<endl;
}
return 0;
}