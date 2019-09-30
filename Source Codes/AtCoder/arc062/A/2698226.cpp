#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;

    int64_t t=1,a=1;

    for(int i=0;i<N;i++){
        int64_t T,A;
        cin>>T>>A;
        int64_t mul=max((t+T-1)/T,(a+A-1)/A);
        t=T*mul; a=A*mul;
        // cout<<t<<' '<<a<<endl;
    }
    cout<<t+a<<endl;

    return 0;
}