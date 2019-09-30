#include <iostream>
#include <cmath>
using namespace std;
using ll=long long;

int N_MAX=50;
int main(){
    int N,K,xt,yt,xmin,xmax,ymin,ymax,ct;
    int x[N_MAX],y[N_MAX];
    ll ans=4*1e18;
    cin>>N>>K;
    //cout<<N<<" "<<K<<endl;
    for(int i=0;i<N;i++){
        cin>>xt>>yt;
        x[i]=xt;
        y[i]=yt;
    }
    //for(int i =0;i<N;i++){
    //    cout<<x[i]<<" "<<y[i]<<endl;
    //}
    for(int i=0; i<N;i++){
        for(int j=0;j<N;j++){
            xmin=x[i];
            xmax=x[j];
            if(xmin>=xmax)
                continue;
            for(int k=0;k<N;k++){
                for(int l=0;l<N;l++){
                    ymin=y[k];
                    ymax=y[l];
                    if(ymin>=ymax)
                        continue;
                    ct=0;
                    for(int m=0;m<N;m++){
                        if(xmin<=x[m] && x[m]<=xmax && ymin<=y[m] && y[m]<=ymax)
                            ct++;
                        if(ct==K){
                            ans=min(ans,1ll *(xmax-xmin)*(ymax-ymin));
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}