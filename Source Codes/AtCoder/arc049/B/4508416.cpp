#include <iostream>
#include <string.h>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
    int N;
    cin>>N;
    double x[N],y[N],c[N];
    for(int i=0;i<N;i++)cin>>x[i]>>y[i]>>c[i];
    double r,l;
    double ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            ans=max(ans,abs(x[i]-x[j])*c[i]*c[j]/(c[i]+c[j]));
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            ans=max(ans,abs(y[i]-y[j])*c[i]*c[j]/(c[i]+c[j]));
        }
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
    return 0;
}