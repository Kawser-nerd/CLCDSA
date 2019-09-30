#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long LL;
int INF=0x3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(false);
    
    LL A,B,C,D,E,F;
    LL ans1=0,ans2=0;
    double tmp,LD=-1;
    cin>>A>>B>>C>>D>>E>>F;
    
    for(int a=0;a*A*100<=F;a++){
        for(int b=0;a*A*100+b*B*100<=F;b++){
            for(int c=0;a*A*100+b*B*100+c*C<=F;c++){
                for(int d=0;a*A*100+b*B*100+c*C+d*D<=F;d++){
                    if(c*C+d*D>(a*A+b*B)*E) break;
                    tmp=(1.0)*(c*C+d*D)/(a*A*100+b*B*100+c*C+d*D);
                    if(LD<tmp) {LD=tmp;ans1=(a*A*100+b*B*100+c*C+d*D);ans2=(c*C+d*D);}
                }
            }
        }
    }
    
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}