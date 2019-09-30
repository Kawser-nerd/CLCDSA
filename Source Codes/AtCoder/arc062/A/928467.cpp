#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin>>N;
    int64_t t=1,a=1;
    for(int i=0;i<N;i++){
        int64_t T,A;
        cin>>T>>A;
        if(abs((double)T/A-(double)t/a)<1e-8){
            //????
            continue;
        }else if((double)T/A<(double)t/a){
            //A???
            if(t%T!=0){
                t+=T-t%T;
            }
            a=A*(t/T);
        }else{
            //T???
            if(a%A!=0){
                a+=A-a%A;
            }
            t=T*(a/A);
        }
        // cout<<a<<' '<<t<<endl;
    }
    cout<<a+t<<endl;
    return 0;
}