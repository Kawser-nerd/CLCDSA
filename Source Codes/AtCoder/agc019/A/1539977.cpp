#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int q,h,s,d,n;
    cin>>q>>h>>s>>d>>n;
    long long ans=0;
    while(n>0){
        if(n>2){
            long long x= min(min(8*q,4*h),min(2*s,d));
            ans=ans+n/2*x;
            n=n%2;
        }
        if(n==1){
            ans+=min(4*q,min(2*h,s));
            n=0;
        }
    }
    cout<<ans;
    return 0;
}