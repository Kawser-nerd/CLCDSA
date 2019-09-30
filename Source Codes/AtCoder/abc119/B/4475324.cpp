#include <iostream>
#include <string>
using namespace std;
int main(void){
    // Your code here!
    double n,ans,a;
    string b;
    cin>>n;
    ans=0;
    for (int i=0; i<n; i++){
        cin>>a>>b;
        if(b=="BTC") a=a*380000;
        ans+=a;
    }cout<<ans<<endl;
}