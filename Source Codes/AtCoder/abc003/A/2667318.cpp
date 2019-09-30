#include <iostream>
using namespace std;
signed main() {
    int N;
    cin>>N;
    double ans = 0;
    for(int i=1;i<=N;++i){
        ans+=(double)i*10000/N;
    }
    cout<<ans<<endl;
    return 0;
}