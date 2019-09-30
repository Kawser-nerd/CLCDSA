#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
using ll=long long;

int N_MAX=100;
int main(){
    long i,N,tsum,t[N_MAX+4],v[N_MAX+2],tn,vpre,va,ans;
    cin>>N;
    tsum=0;
    for(i=0;i<N;i++){
        cin>>t[i+2];
        t[i+2]+=t[i+1];
        tsum+=t[i+2];
    }
    v[0]=0;
    v[N+1]=0;
    for(i=0;i<N;i++){
        cin>>v[i+1];
    }
    t[0]=0;
    t[1]=0;
    t[N+2]=tsum;
    vpre=0.0;
    ans=0.0;
    for(tn=1;tn<2*tsum+1;tn+=1){
        va=1e7;
        for(i=0;i<N+2;i++){
            if(tn<=2*t[i]){
                //va=min(double(va),v[i]+(t[i]-double(tn)/2));
                va=min(va,2*v[i]+(2*t[i]-tn));
            }
            else if(2*t[i]<=tn && tn<=2*t[i+1]){
                //va=min(double(va),double(v[i]));
                va=min(va,2*v[i]);
            }
            else if(2*t[i+1]<=tn){
                //va=min(double(va),v[i]+(double(tn)/2)-t[i+1]);
                va=min(va,2*v[i]+tn-2*t[i+1]);
            }
        }
        //cout<<va<<" "<<vpre<<endl;
        ans+=va+vpre;
        vpre=va;
    }
    //for(i=0;i<N+4;i++){
    //    cout<<t[i]<<endl;
    //}
    //cout << fixed;
    cout << fixed << setprecision(6) << double(ans)/8<<endl;
//    printf("%.12f", double(ans)/8);
//    cout<< std::setprecision(2)<<double(ans)/8<<endl;
    return 0;
}